#include "GLWidget.h"

#if !defined(__APPLE__)
#include <GL/glu.h>
#endif

#include <iostream>
using namespace std;

#include <Core/Exceptions.h>
#include <Core/Materials.h>
#include "Test/TestFunctions.h"
#include <Windows.h>
#include <Core/Constants.h>
#include <Core/CubicBSplineArc3.h>
#include <Core/CubicBSplinePatch.h>
#include <time.h>
#include <stdlib.h>
namespace cagd
{
	//--------------------------------
	// special and default constructor
	//--------------------------------
	GLWidget::GLWidget(QWidget* parent) : QOpenGLWidget(parent)
	{
		_timer = new QTimer(this);
		_timer->setInterval(0);
		connect(_timer, SIGNAL(timeout()), this, SLOT(_animate()));
	}

	//--------------------------------------------------------------------------------------
	// this virtual function is called once before the first call to paintGL() or resizeGL()
	//--------------------------------------------------------------------------------------
	void GLWidget::initializeGL()
	{
		// creating a perspective projection matrix
		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();

		_aspect = static_cast<double>(width()) / static_cast<double>(height());
		_z_near = 1.0;
		_z_far = 1000.0;
		_fovy = 45.0;

		gluPerspective(_fovy, _aspect, _z_near, _z_far);

		// setting the model view matrix
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		_eye[0] = _eye[1] = 0.0; _eye[2] = 6.0;
		_center[0] = _center[1] = _center[2] = 0.0;
		_up[0] = _up[2] = 0.0; _up[1] = 1.0;

		gluLookAt(_eye[0], _eye[1], _eye[2], _center[0], _center[1], _center[2], _up[0], _up[1], _up[2]);

		// enabling the depth test
		glEnable(GL_DEPTH_TEST);

		// setting the background color
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		// initial values of transformation parameters
		_angle_x = _angle_y = _angle_z = 0.0;
		_trans_x = _trans_y = _trans_z = 0.0;
		_zoom = 1.0;

		// ...

		try
		{
			// initializing the OpenGL Extension Wrangler library
			GLenum error = glewInit();

			if (error != GLEW_OK)
			{
				throw Exception("Could not initialize the OpenGL Extension Wrangler Library!");
			}

			if (!glewIsSupported("GL_VERSION_2_0"))
			{
				throw Exception("Your graphics card is not compatible with OpenGL 2.0+! "
					"Try to update your driver or buy a new graphics adapter!");
			}

			// create and store your geometry in display lists or vertex buffer objects
			// ...
			srand(time(NULL));
			_angle = 0;
			_timer->start();
			initParametricCurves();
			initModels();
			initShaders();
			//initSandbox();
			initParametricSurfaces();
			initTextures();
			//initCyclicControlCoordinates();
			//initCyclicCurve();
			//setCyclicCoordinateIndex(0);

			initArcData();
			setArcUiValues();
			initArc();

			initPatchData();
			setPatchUiValues();
			initPatch();
		}
		catch (Exception& e)
		{
			cout << e << endl;
		}
	}

	//-----------------------
	// the rendering function
	//-----------------------
	void GLWidget::paintGL()
	{
		// clears the color and depth buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// stores/duplicates the original model view matrix
		glPushMatrix();

		// applying transformations
		glRotatef(_angle_x, 1.0, 0.0, 0.0);
		glRotatef(_angle_y, 0.0, 1.0, 0.0);
		glRotatef(_angle_z, 0.0, 0.0, 1.0);
		glTranslated(_trans_x, _trans_y, _trans_z);
		glScaled(_zoom, _zoom, _zoom);

		// render your geometry (this is oldest OpenGL rendering technique, later we will use some advanced methods)

		switch (image_index) {
		case 0:
			showParametricCurves();
			break;
		case 1:
			showModels();
			break;
		case 2:
			showParametricSurfaces();
			break;
		case 3:
			showCyclicCurve();
			break;
		case 4:
			showArc();
			break;
		case 5:
			showPatch();
			break;
		case 6:
			showSandbox();
			break;
		}
		if (textureIndex != 0)
		{
			textures[textureIndex - 1]->release();
		}
		// pops the current matrix stack, replacing the current matrix with the one below it on the stack,
		// i.e., the original model view matrix is restored
		glPopMatrix();
	}

	//----------------------------------------------------------------------------
	// when the main window is resized one needs to redefine the projection matrix
	//----------------------------------------------------------------------------
	void GLWidget::resizeGL(int w, int h)
	{
		// setting the new size of the rendering context
		glViewport(0, 0, w, h);

		// redefining the projection matrix
		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();

		_aspect = static_cast<double>(w) / static_cast<double>(h);

		gluPerspective(_fovy, _aspect, _z_near, _z_far);

		// switching back to the model view matrix
		glMatrixMode(GL_MODELVIEW);

		update();
	}


	void GLWidget::showParametricCurves()
	{
		if (_images_of_pc[pc_index]) {
			glColor3f(1.0f, 0.0f, 0.0f);
			_images_of_pc[pc_index]->RenderDerivatives(0, GL_LINE_STRIP);

			glPointSize(5.0f);

			glColor3f(0.0f, 1.0f, 0.0f);
			_images_of_pc[pc_index]->RenderDerivatives(1, GL_LINES);
			_images_of_pc[pc_index]->RenderDerivatives(1, GL_POINTS);

			glColor3f(0.1f, 0.5f, 0.9f);
			_images_of_pc[pc_index]->RenderDerivatives(2, GL_LINES);
			_images_of_pc[pc_index]->RenderDerivatives(2, GL_POINTS);

			glPointSize(1.0f);
		}
	}

	void GLWidget::initParametricCurves()
	{
		RowMatrix<ParametricCurve3::Derivative> derivative(1 + (isFirstDerivative ? 1 : 0) + (isSecondDerivative ? 1 : 0));
		derivative(0) = spiral_on_cone::d0;
		if (isFirstDerivative)
			derivative(1) = spiral_on_cone::d1;
		if (isFirstDerivative && isSecondDerivative)
			derivative(2) = spiral_on_cone::d2;
		if (!isFirstDerivative && isSecondDerivative)
			derivative(1) = spiral_on_cone::d2;


		_pcs[0] = new (nothrow) ParametricCurve3(derivative, spiral_on_cone::u_min, spiral_on_cone::u_max, pcFirstDerivScale, pcSecondDerivScale);

		if (!_pcs[0]) {
			exit(-1);
		}

		derivative(0) = torus_knot::d0;
		if (isFirstDerivative)
			derivative(1) = torus_knot::d1;
		if (isFirstDerivative && isSecondDerivative)
			derivative(2) = torus_knot::d2;
		if (!isFirstDerivative && isSecondDerivative)
			derivative(1) = torus_knot::d2;

		_pcs[1] = new (nothrow) ParametricCurve3(derivative, torus_knot::u_min, torus_knot::u_max, pcFirstDerivScale, pcSecondDerivScale);

		if (!_pcs[1]) {
			exit(-1);
		}

		derivative(0) = parametric_curve_1::d0;
		if (isFirstDerivative)
			derivative(1) = parametric_curve_1::d1;
		if (isFirstDerivative && isSecondDerivative)
			derivative(2) = parametric_curve_1::d2;
		if (!isFirstDerivative && isSecondDerivative)
			derivative(1) = parametric_curve_1::d2;

		_pcs[2] = new (nothrow)
			ParametricCurve3(derivative, parametric_curve_1::u_min, parametric_curve_1::u_max, pcFirstDerivScale, pcSecondDerivScale);

		if (!_pcs[2]) {
			exit(-1);
		}

		derivative(0) = hypotrochoid::d0;
		if (isFirstDerivative)
			derivative(1) = hypotrochoid::d1;
		if (isFirstDerivative && isSecondDerivative)
			derivative(2) = hypotrochoid::d2;
		if (!isFirstDerivative && isSecondDerivative)
			derivative(1) = hypotrochoid::d2;

		_pcs[3] = new (nothrow) ParametricCurve3(derivative, hypotrochoid::u_min, hypotrochoid::u_max, pcFirstDerivScale, pcSecondDerivScale);

		if (!_pcs[3]) {
			exit(-1);
		}

		derivative(0) = viviani::d0;
		if (isFirstDerivative)
			derivative(1) = viviani::d1;
		if (isFirstDerivative && isSecondDerivative)
			derivative(2) = viviani::d2;
		if (!isFirstDerivative && isSecondDerivative)
			derivative(1) = viviani::d2;

		_pcs[4] = new (nothrow) ParametricCurve3(derivative, viviani::u_min, viviani::u_max, pcFirstDerivScale, pcSecondDerivScale);

		if (!_pcs[4]) {
			exit(-1);
		}

		derivative(0) = archytas::d0;
		if (isFirstDerivative)
			derivative(1) = archytas::d1;
		if (isFirstDerivative && isSecondDerivative)
			derivative(2) = archytas::d2;
		if (!isFirstDerivative && isSecondDerivative)
			derivative(1) = archytas::d2;

		_pcs[5] = new (nothrow) ParametricCurve3(derivative, archytas::u_min, archytas::u_max, pcFirstDerivScale, pcSecondDerivScale);

		if (!_pcs[5]) {
			exit(-1);
		}

		GLuint div_point_count = pcDivisionPoints;
		GLenum usage_flag = GL_STATIC_DRAW;

		for (int i = 0; i < 6; i++) {
			_images_of_pc[i] = _pcs[i]->GenerateImage(div_point_count, usage_flag);

			if (!_images_of_pc[i]) {
				exit(-2);
			}

			if (!_images_of_pc[i]->UpdateVertexBufferObjects(usage_flag)) {
				cout << "Could not create the vertex buffer object of the parametric curve!" << endl;
			}
		}
	}

	void GLWidget::initModels()
	{
		_images_of_model.ResizeColumns(8);

		_angle = 0.0;

		if (_images_of_model[0].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models/angel.off", true)) {
			if (_images_of_model[0].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW)) {
			}
			else {
				cout << "Couldn't update Vertex Buffer Objects" << endl;
			}
		}
		else {
			cout << "Couldn't load model angel" << endl;
		}

		if (_images_of_model[1].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models//bird.off", true)) {
			if (_images_of_model[1].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW)) {
			}
			else {
				cout << "Couldn't update Vertex Buffer Objects" << endl;
			}
		}
		else {
			cout << "Couldn't load model bird" << endl;
		}

		if (_images_of_model[2].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models//cone.off", true)) {
			if (_images_of_model[2].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW)) {
			}
			else {
				cout << "Couldn't update Vertex Buffer Objects" << endl;
			}
		}
		else {
			cout << "Couldn't load model cone" << endl;
		}

		if (_images_of_model[3].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models//cube.off", true)) {
			if (_images_of_model[3].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW)) {
			}
			else {
				cout << "Couldn't update Vertex Buffer Objects" << endl;
			}
		}
		else {
			cout << "Couldn't load model cube" << endl;
		}

		if (_images_of_model[4].LoadFromOFF("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models//dragon.off", true)) {
			if (_images_of_model[4].UpdateVertexBufferObjects(GL_DYNAMIC_DRAW)) {
			}
			else {
				cout << "Couldn't update Vertex Buffer Objects" << endl;
			}
		}
		else {
			cout << "Couldn't load model icosahedron" << endl;
		}
	}

	void GLWidget::showModels()
	{
		if (show_shader) {
			shaders[shader_index].Enable();
		}

		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_NORMALIZE);
		MatFBRuby.Apply();
		_images_of_model[model_index].Render();

		if (show_shader) {
			shaders[shader_index].Disable();
		}
		glDisable(GL_LIGHTING);
		glDisable(GL_NORMALIZE);
		glDisable(GL_LIGHT0);
	}

	void GLWidget::initSandbox()
	{
		sandbox.Init();
		sandbox.LoadFromFile("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models//sandbox.off");

		/*for (int i = 0; i < sandbox.numberOfModels; i++)
		{
			sandbox.imagesOfModels[i].Translate(0, 0.8, 0);
			sandbox.imagesOfModels[i].Scale(0.02);
		}

		sandbox.SaveToFile("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models//out.off");*/
	}

	void GLWidget::showSandbox()
	{
		if (reloadSandbox) {
			sandbox.LoadFromFile("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Models//sandbox.off");
		}
		sandbox.Render();
		sandbox.Animate(_angle);
	}

	void GLWidget::initShaders()
	{
		shaders.ResizeColumns(4);
		default_outline_color.ResizeColumns(3);
		for (GLuint i = 0; i < 3; i++) {
			default_outline_color[i] = 0.5f;
		}

		if (!shaders[0].InstallShaders("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Shaders/directional_light.vert",
			"D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Shaders/directional_light.frag")) {
			throw Exception("Directional light failed to load.");
		}

		if (!shaders[1].InstallShaders("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Shaders/reflection_lines.vert",
			"D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Shaders/reflection_lines.frag")) {
			throw Exception("Reflection lines failed to load.");
		}
		else {
			shaders[1].Enable();
			shaders[1].SetUniformVariable1f("scale_factor", scaleFactor);
			shaders[1].SetUniformVariable1f("smoothing", smoothing);
			shaders[1].SetUniformVariable1f("shading", shading);
			shaders[1].Disable();
		}

		if (!shaders[2].InstallShaders("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Shaders/toon.vert", "D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Shaders/toon.frag")) {
			throw Exception("Toon failed to load.");
		}
		{
			shaders[2].Enable();
			shaders[2].SetUniformVariable4f("default_outline_color", scaleFactor, smoothing, shading, 1.0f);
			shaders[2].Disable();
		}

		if (!shaders[3].InstallShaders("D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Shaders/two_sided_lighting.vert",
			"D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Shaders/two_sided_lighting.frag")) {
			throw Exception("Two sided lighting failed to load.");
		}
	}

	void GLWidget::initTextures()
	{
		for (int i = 0; i < 10; i++)
		{
			stringstream  fileName;
			fileName << "D:/Programming/repos/graphics-new/QtFramework/QtFramework/debug/Textures/periodic_texture_0" << i << ".jpg";
			textures[i] = new QOpenGLTexture(QImage(fileName.str().c_str()).mirrored());
			textures[i]->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
			textures[i]->setMagnificationFilter(QOpenGLTexture::Linear);
		}
	}

	void GLWidget::initParametricSurfaces()
	{
		MatFBEmerald.Apply();
		TriangularMatrix<ParametricSurface3::PartialDerivative> derivatives(3);
		derivatives(0, 0) = torus::d00;
		derivatives(1, 0) = torus::d10;
		derivatives(1, 1) = torus::d01;
		_pss[0] = new ParametricSurface3(derivatives,
			torus::u_min,
			torus::u_max,
			torus::v_min,
			torus::v_max);

		derivatives(0, 0) = hyperboloid::d00;
		derivatives(1, 0) = hyperboloid::d10;
		derivatives(1, 1) = hyperboloid::d01;
		_pss[1] = new ParametricSurface3(derivatives,
			hyperboloid::u_min,
			hyperboloid::u_max,
			hyperboloid::v_min,
			hyperboloid::v_max);

		derivatives(0, 0) = cylindrical_helicoid::d00;
		derivatives(1, 0) = cylindrical_helicoid::d10;
		derivatives(1, 1) = cylindrical_helicoid::d01;
		_pss[2] = new ParametricSurface3(derivatives,
			cylindrical_helicoid::u_min,
			cylindrical_helicoid::u_max,
			cylindrical_helicoid::v_min,
			cylindrical_helicoid::v_max);

		derivatives(0, 0) = alfred_gray::d00;
		derivatives(1, 0) = alfred_gray::d10;
		derivatives(1, 1) = alfred_gray::d01;
		_pss[3] = new ParametricSurface3(derivatives,
			alfred_gray::u_min,
			alfred_gray::u_max,
			alfred_gray::v_min,
			alfred_gray::v_max);

		derivatives(0, 0) = klein_bottle::d00;
		derivatives(1, 0) = klein_bottle::d10;
		derivatives(1, 1) = klein_bottle::d01;
		_pss[4] = new ParametricSurface3(derivatives,
			klein_bottle::u_min,
			klein_bottle::u_max,
			klein_bottle::v_min,
			klein_bottle::v_max);

		GLenum usage_flag_s = GL_STATIC_DRAW;
		GLuint div_point_count_u = pcDivisionPoints, div_point_count_v = pcDivisionPoints;
		for (GLuint i = 0; i < 5; i++) {
			if (!_pss[i]) {
				throw Exception("Couldn't create the parameteric surface.");
			}

			_images_of_ps[i] = nullptr;
			_images_of_ps[i] = _pss[i]->GenerateImage(div_point_count_u,
				div_point_count_v,
				usage_flag_s);

			if (!_images_of_ps[i]) {
				if (_pss[i]) {
					delete _pss[i];
					_pss[i] = nullptr;
				}
				throw Exception("Couldn't create the parametric surface's image.");
			}

			if (!_images_of_ps[i]->UpdateVertexBufferObjects(usage_flag_s)) {
				cout << "could not create the vertex buffer object of the parametric surface!" << endl;
			}
		}
	}

	void GLWidget::showParametricSurfaces()
	{
		if (show_shader) {
			shaders[shader_index].Enable();
		}

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_NORMALIZE);
		glEnable(GL_TEXTURE_2D);
		if (textureIndex != 0)
		{
			textures[textureIndex - 1]->bind();
		}
		if (_images_of_ps[ps_index]) {
			_images_of_ps[ps_index]->Render();
		}
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
		glDisable(GL_NORMALIZE);

		if (show_shader) {
			shaders[shader_index].Disable();
		}
	}

	void GLWidget::initCyclicControlCoordinates()
	{
		cyclicControlCoordinates.ResizeColumns(6);
		cyclicControlCoordinates[0] = DCoordinate3(0, 1, 0);
		cyclicControlCoordinates[1] = DCoordinate3(0, 0.5, 0.2 * sqrt(3));
		cyclicControlCoordinates[2] = DCoordinate3(0, -0.5, 0.5 * sqrt(2));
		cyclicControlCoordinates[3] = DCoordinate3(0, -1, 0);
		cyclicControlCoordinates[4] = DCoordinate3(1, -0.7, -0.3 * sqrt(5));
		cyclicControlCoordinates[5] = DCoordinate3(1, 0.22, -0.5 * sqrt(7));
	}

	void GLWidget::initCyclicCurve()
	{
		GLint curvePointNumber = 6;

		cCurve = new CyclicCurve3(curvePointNumber / 2);
		(*cCurve)[0] = cyclicControlCoordinates[0];
		(*cCurve)[1] = cyclicControlCoordinates[1];
		(*cCurve)[2] = cyclicControlCoordinates[2];
		(*cCurve)[3] = cyclicControlCoordinates[3];
		(*cCurve)[4] = cyclicControlCoordinates[4];
		(*cCurve)[5] = cyclicControlCoordinates[5];
		(*cCurve)[6] = (*cCurve)[0];

		cCurve->UpdateVertexBufferObjectsOfData();

		cCurveImage = cCurve->GenerateImage(2, 200);

		if (cCurveImage) {
			cCurveImage->UpdateVertexBufferObjects(GL_STATIC_DRAW);
		}

		ColumnMatrix<DCoordinate3> cyclicCurveDataPointsToInterpolate(curvePointNumber + 1);
		for (auto i = 0; i < curvePointNumber + 1; i++) {
			cyclicCurveDataPointsToInterpolate[i] = (*cCurve)[i];
		}

		ColumnMatrix<GLdouble> knotVector(curvePointNumber + 1);
		for (auto i = 0; i < curvePointNumber + 1; i++) {
			knotVector[i] = TWO_PI * (i / (GLdouble)curvePointNumber + 1);
		}

		if (cCurve->UpdateDataForInterpolation(knotVector, cyclicCurveDataPointsToInterpolate)) {
			cCurveImageInterpolated = cCurve->GenerateImage(0, 200);
			if (cCurveImageInterpolated) {
				cCurveImageInterpolated->UpdateVertexBufferObjects();
			}
		}
	}

	void GLWidget::showCyclicCurve()
	{
		if (isCyclicPolygon) {
			glColor3f(1.0f, 1.0f, 1.0f);
			cCurve->RenderData();
		}
		if (cCurveImage) {
			if (isCyclicCurveNoInterpolation) {
				glColor3f(0.0f, 0.0f, 1.0f);
				cCurveImage->RenderDerivatives(0, GL_LINE_STRIP);
			}
			if (isCyclicFirstDeriv) {
				glColor3f(0.3f, 0.2f, 0.5f);
				cCurveImage->RenderDerivatives(1, GL_LINES);
			}
			if (isCyclicSecondDeriv) {
				glColor3f(0.5f, 0.2f, 0.4f);
				cCurveImage->RenderDerivatives(2, GL_LINES);
			}
		}
		if (cCurveImageInterpolated) {
			if (isCyclicInterpolated) {
				glColor3f(0.8f, 0.8f, 0.4f);
				cCurveImageInterpolated->RenderDerivatives(0, GL_LINE_STRIP);
			}
		}
	}

	void GLWidget::initArcData()
	{
		auto dataSize = arcCount < 3 ? 4 : arcCount + 1;
		arcData = new RowMatrix<DCoordinate3>(dataSize);
		for (int i = 0; i < dataSize; i++) {
			arcData->operator[](i) = DCoordinate3((rand() % 100) / 300.0, i * 0.3, (rand() % 100) / 300.0);
		}

		arcs = new RowMatrix<CubicBSplineArc3*>(arcCount);
		arcImages = new RowMatrix<GenericCurve3*>(arcCount);
		arcColors = new Matrix<GLfloat>(arcCount, 3);
		for (int i = 0; i < arcCount; i++) {
			for (int j = 0; j < 3; j++) {
				arcColors->operator()(i, j) = (rand() % 100) / 100.0;
			}
		}

		auto size = _sideWidget->arcDataIndexComboBox->count();
		for (int i = 0; i < size; i++) {
			_sideWidget->arcDataIndexComboBox->removeItem(0);
		}
		for (int i = 0; i < dataSize; i++) {
			_sideWidget->arcDataIndexComboBox->addItem(to_string(i).c_str());
		}
	}

	void GLWidget::initArc()
	{
		for (int k = 0; k < arcCount; k++) {
			arcs->operator[](k) = new CubicBSplineArc3();
			if (arcCount == 1) {
				for (int i = 0; i < 4; i++) {
					arcs->operator[](k)->operator[](i) = arcData-> operator[](i);
				}
			}
			else {
				auto topLimit = arcCount < 3 ? 3 : arcCount;
				for (int i = 0; i < 4; i++) {
					auto l = k - 1 + i;
					if (l < 0)l = 0;
					if (l > topLimit)l = topLimit;
					arcs->operator[](k)->operator[](i) = arcData-> operator[](l);
				}
			}

			arcs->operator[](k)->UpdateVertexBufferObjectsOfData();
			arcImages->operator[](k) = arcs->operator[](k)->GenerateImage(2, arcDivPointCount, GL_STATIC_DRAW);
			if (arcImages->operator[](k)) {
				arcImages->operator[](k)->UpdateVertexBufferObjects();
			}
		}
	}

	void GLWidget::showArc()
	{
		if (isArcNoInterpolation) {
			for (int k = 0; k < arcCount; k++) {
				if (arcImages->operator[](k)) {
					glColor3f(arcColors->operator()(k, 0), arcColors->operator()(k, 1), arcColors->operator()(k, 2));
					arcImages->operator[](k)->RenderDerivatives(0, GL_LINE_STRIP);
				}
			}
		}
		if (isArcFirstDeriv) {
			glColor3f(1.0f, 0.0f, 0.0f);
			for (int k = 0; k < arcCount; k++) {
				arcImages->operator[](k)->RenderDerivatives(1, GL_LINES);
			}
		}
		if (isArcSecondDeriv) {
			glColor3f(0.0f, 0.0f, 1.0f);
			for (int k = 0; k < arcCount; k++) {
				arcImages->operator[](k)->RenderDerivatives(2, GL_LINES);
			}
		}
		if (isArcPolygon) {
			glColor3f(1.0f, 1.0f, 1.0f);
			for (int k = 0; k < arcCount; k++) {
				arcs->operator[](k)->RenderData();
			}
		}
	}

	void GLWidget::setArcUiValues()
	{
		_sideWidget->arcDataSpinner_X->setValue(arcData->operator[](arcDataIndex).x());
		_sideWidget->arcDataSpinner_Y->setValue(arcData->operator[](arcDataIndex).y());
		_sideWidget->arcDataSpinner_Z->setValue(arcData->operator[](arcDataIndex).z());
	}

	void GLWidget::initPatchData()
	{
		auto dataSize = patchSize < 3 ? 4 : patchSize + 1;
		patches = new Matrix<CubicBSplinePatch*>(patchSize, patchSize);
		patchImages = new Matrix<TriangulatedMesh3*>(patchSize, patchSize);

		patchData = new Matrix<DCoordinate3*>(dataSize, dataSize);
		patchMaterials = new Matrix<Material>(dataSize, dataSize);

		for (auto i = 0; i < dataSize; i++)
		{
			for (auto j = 0; j < dataSize; j++)
			{
				patchData->operator()(i, j) = new DCoordinate3(rand() % 2 + (rand() % 100) / 100.0, j, i);
				patchMaterials->operator()(i, j) = (i + j) % 2 == 0 ? MatFBEmerald : MatFBRuby;
			}
		}
		auto size = _sideWidget->patchDataPointComboBox_row->count();
		for (auto i = 0; i < size; i++) {
			_sideWidget->patchDataPointComboBox_row->removeItem(0);
			_sideWidget->patchDataPointComboBox_col->removeItem(0);
		}
		for (auto i = 0; i < dataSize; i++)
		{
			_sideWidget->patchDataPointComboBox_col->addItem(to_string(i).c_str());
			_sideWidget->patchDataPointComboBox_row->addItem(to_string(i).c_str());
		}
	}

	void GLWidget::setPatchUiValues()
	{
		if (patchData->operator()(patchSelectedRow, patchSelectedColumn) != nullptr) {
			_sideWidget->patchDataPointSpinner_X->setValue(patchData->operator()(patchSelectedRow, patchSelectedColumn)->x());
			_sideWidget->patchDataPointSpinner_Y->setValue(patchData->operator()(patchSelectedRow, patchSelectedColumn)->y());
			_sideWidget->patchDataPointSpinner_Z->setValue(patchData->operator()(patchSelectedRow, patchSelectedColumn)->z());
		}

	}

	void GLWidget::initPatch()
	{
		for (auto i = 0; i < patchSize; i++)
		{
			for (auto j = 0; j < patchSize; j++)
			{

				patches->operator()(i, j) = new CubicBSplinePatch();
				if (patchSize < 3) {
					if (patchSize == 1) {
						for (int i2 = 0; i2 < 4; i2++) {
							for (int j2 = 0; j2 < 4; j2++) {
								patches->operator()(i, j)->SetData(i2, j2, *patchData->operator()(i2, j2));
							}
						}
					}
					else {
						for (int i2 = 0; i2 < 4; i2++) {
							for (int j2 = 0; j2 < 4; j2++) {
								auto k = i - 1 + i2, l = j - 1 + j2;
								if (k < 0)k = 0;
								if (k > 3)k = 3;
								if (l < 0)l = 0;
								if (l > 3)l = 3;

								patches->operator()(i, j)->SetData(i2, j2, *patchData->operator()(k, l));
							}
						}
					}

				}
				else {
					for (int i2 = 0; i2 < 4; i2++) {
						for (int j2 = 0; j2 < 4; j2++) {
							auto k = i - 1 + i2, l = j - 1 + j2;
							if (k < 0)k = 0;
							if (k > patchSize)k = patchSize;
							if (l < 0)l = 0;
							if (l > patchSize)l = patchSize;

							patches->operator()(i, j)->SetData(i2, j2, *patchData->operator()(k, l));
						}
					}
				}

				patches->operator()(i, j)->UpdateVertexBufferObjectsOfData();

				patchImages->operator()(i, j) = patches->operator()(i, j)->GenerateImage(patchDivPointCount_U, patchDivPointCount_V, GL_STATIC_DRAW);
				if (patchImages->operator()(i, j)) {
					patchImages->operator()(i, j)->UpdateVertexBufferObjects();
				}
			}
		}
		RowMatrix<GLdouble> uKnotVector(4);
		ColumnMatrix<GLdouble> vKnotVector(4);

		for (auto i = 0; i <= 3; i++)
		{
			uKnotVector[i] = i * 1.0 / (3);
			vKnotVector[i] = i * 1.0 / (3);
		}

		Matrix<DCoordinate3> dataPointsToInterpolate(4, 4);

		for (auto i = 0; i < 4; i++) {
			for (auto j = 0; j < 4; j++) {
				dataPointsToInterpolate(i, j) = patches->operator()(0, 0)->_data(i, j);
			}
		}

		if (patches->operator()(0, 0)->UpdateDataForInterpolation(uKnotVector, vKnotVector, dataPointsToInterpolate)) {
			patchImageInterpolated = patches->operator()(0, 0)->GenerateImage(patchDivPointCount_U, patchDivPointCount_V, GL_STATIC_DRAW);
		}

		if (patchImageInterpolated) {
			patchImageInterpolated->UpdateVertexBufferObjects();
		}
		patchIsoCurves_U = patches->operator()(0, 0)->GenerateUIsoparametricLines(patchDivPointCount_U, 1, patchDivPointCount_V, GL_STATIC_DRAW);
		auto length = patchIsoCurves_U->GetColumnCount();
		for (auto i = 0; i < length; i++) {
			if ((*patchIsoCurves_U)[i]) {
				(*patchIsoCurves_U)[i]->UpdateVertexBufferObjects();
			}
		}

		patchIsoCurves_V = patches->operator()(0, 0)->GenerateVIsoparametricLines(patchDivPointCount_U, 1, patchDivPointCount_V, GL_STATIC_DRAW);
		length = patchIsoCurves_V->GetColumnCount();
		for (auto i = 0; i < length; i++) {
			if ((*patchIsoCurves_V)[i]) {
				(*patchIsoCurves_V)[i]->UpdateVertexBufferObjects();
			}
		}
	}

	void GLWidget::showPatch()
	{


		if (show_shader) {
			shaders[shader_index].Enable();
		}
		if (patchImageInterpolated) {
			if (showPatchInterpolated) {
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT0);
				glEnable(GL_NORMALIZE);
				glEnable(GL_BLEND);
				glDepthMask(GL_FALSE);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE);
				MatFBPearl.Apply();
				patchImageInterpolated->Render(GL_TRIANGLES);
				glDisable(GL_LIGHTING);
				glDisable(GL_LIGHT0);
				glDisable(GL_NORMALIZE);
				glDisable(GL_BLEND);
				glDepthMask(GL_TRUE);
			}
		}
		if (showPatchNoInterpolation)
		{
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
			glEnable(GL_NORMALIZE);
			for (auto i = 0; i < patchSize; i++)
			{
				for (auto j = 0; j < patchSize; j++)
				{
					if (patchImages->operator()(i, j))
					{
						patchMaterials->operator()(i, j).Apply();
						patchImages->operator()(i, j)->Render(GL_TRIANGLES);
					}
				}
			}
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT0);
			glDisable(GL_NORMALIZE);
		}
		if (showPatchData) {
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);
			glEnable(GL_NORMALIZE);
			glColor3f(0.5f, 0.5f, 0.7f);
			for (auto i = 0; i < patchSize; i++)
			{
				for (auto j = 0; j < patchSize; j++)
				{
					patches->operator()(i, j)->RenderData();
				}
			}
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT0);
			glDisable(GL_NORMALIZE);
		}

		if (show_shader) {
			shaders[shader_index].Disable();
		}
		if (showPatchIsoparametricCurves_U) {
			glColor3f(1.0f, 0.0f, 0.0f);
			auto length = patchIsoCurves_U->GetColumnCount();
			for (auto i = 0; i < length; i++) {
				(*patchIsoCurves_U)[i]->RenderDerivatives(0, GL_LINE_STRIP);
			}
		}

		if (showPatchIsoparametricCurves_V) {
			glColor3f(0.0f, 0.0f, 1.0f);
			auto length = patchIsoCurves_V->GetColumnCount();
			for (auto i = 0; i < length; i++) {
				(*patchIsoCurves_V)[i]->RenderDerivatives(0, GL_LINE_STRIP);
			}
		}
	}

	//-----------------------------------
	// implementation of the public slots
	//-----------------------------------

	void GLWidget::set_angle_x(int value)
	{
		if (_angle_x != value)
		{
			_angle_x = value;
			update();
		}
	}

	void GLWidget::set_angle_y(int value)
	{
		if (_angle_y != value)
		{
			_angle_y = value;
			update();
		}
	}

	void GLWidget::set_angle_z(int value)
	{
		if (_angle_z != value)
		{
			_angle_z = value;
			update();
		}
	}

	void GLWidget::set_zoom_factor(double value)
	{
		if (_zoom != value)
		{
			_zoom = value;
			update();
		}
	}

	void GLWidget::set_trans_x(double value)
	{
		if (_trans_x != value)
		{
			_trans_x = value;
			update();
		}
	}

	void GLWidget::set_trans_y(double value)
	{
		if (_trans_y != value)
		{
			_trans_y = value;
			update();
		}
	}

	void GLWidget::set_trans_z(double value)
	{
		if (_trans_z != value)
		{
			_trans_z = value;
			update();
		}
	}

	void GLWidget::set_selected_curve_index(int value)
	{
		if (pc_index != value) {
			pc_index = value;
			update();
		}
	}

	void GLWidget::set_division_points(int value)
	{
		if (pcDivisionPoints != value) {
			pcDivisionPoints = value;
			initParametricCurves();
			update();
		}
	}

	void GLWidget::set_first_derivative(bool value)
	{
		if (isFirstDerivative != value) {
			isFirstDerivative = value;
			initParametricCurves();
			update();
		}
	}

	void GLWidget::set_second_derivative(bool value)
	{
		if (isSecondDerivative != value) {
			isSecondDerivative = value;
			initParametricCurves();
			update();
		}
	}

	void GLWidget::set_selected_surface_index(int value)
	{
		if (ps_index != value) {
			ps_index = value;
			update();
		}
	}

	void GLWidget::set_selected_model_index(int value)
	{
		if (model_index != value) {
			model_index = value;
			update();
		}
	}

	void GLWidget::set_image_index(int value)
	{
		image_index = value;
		update();
	}

	void GLWidget::set_isCyclicPolygon(bool value)
	{
		isCyclicPolygon = value;
		update();
	}

	void GLWidget::set_isCyclicCurveNoInterpolation(bool value)
	{
		isCyclicCurveNoInterpolation = value;
		update();
	}

	void GLWidget::set_isCyclicFirstDeriv(bool value)
	{
		isCyclicFirstDeriv = value;
		update();
	}

	void GLWidget::set_isCyclicSecondDeriv(bool value)
	{
		isCyclicSecondDeriv = value;
		update();
	}

	void GLWidget::set_isCyclicInterpolated(bool value)
	{
		isCyclicInterpolated = value;
		update();
	}

	void GLWidget::set_isBiquarticPolygon(bool value)
	{
		isArcPolygon = value;
		update();
	}

	void GLWidget::set_isBiquarticFirstDeriv(bool value)
	{
		isArcFirstDeriv = value;
		update();
	}

	void GLWidget::set_isBiquarticSecondDeriv(bool value)
	{
		isArcSecondDeriv = value;
		update();
	}

	void GLWidget::set_isBiquarticArcNoInterpolation(bool value)
	{
		isArcNoInterpolation = value;
		update();
	}

	void GLWidget::set_isBiquarticData(bool value)
	{
		showPatchData = value;
		update();
	}

	void GLWidget::set_isBiquarticNoInterpolation(bool value)
	{
		showPatchNoInterpolation = value;
		update();
	}

	void GLWidget::set_isBiquarticInterpolated(bool value)
	{
		showPatchInterpolated = value;
		update();
	}

	void GLWidget::setPatchDivPointCount_U(int value)
	{
		patchDivPointCount_U = value;
		initPatch();
		update();
	}

	void GLWidget::setPatchDivPointCount_V(int value)
	{
		patchDivPointCount_V = value;
		initPatch();
		update();
	}

	void GLWidget::setShowPatchIsoCurves_U(bool value)
	{
		showPatchIsoparametricCurves_U = value;
		initPatch();
		update();
	}

	void GLWidget::setShowPatchIsoCurves_V(bool value)
	{
		showPatchIsoparametricCurves_V = value;
		initPatch();
		update();
	}

	void GLWidget::setPatchSelectedRow(int value)
	{
		patchSelectedRow = value;
		if (patchSelectedRow < 0)patchSelectedRow = 0;
		setPatchUiValues();
	}

	void GLWidget::setPatchSelectedColumn(int value)
	{
		patchSelectedColumn = value;
		if (patchSelectedColumn < 0)patchSelectedColumn = 0;
		setPatchUiValues();
	}

	void GLWidget::setSelectedDatapoint_X(double value)
	{
		if (value != patchData->operator()(patchSelectedRow, patchSelectedColumn)->x()) {
			patchData->operator()(patchSelectedRow, patchSelectedColumn)->setx(value);
			initPatch();
			update();
		}
	}

	void GLWidget::setSelectedDatapoint_Y(double value)
	{
		if (value != patchData->operator()(patchSelectedRow, patchSelectedColumn)->y()) {
			patchData->operator()(patchSelectedRow, patchSelectedColumn)->sety(value);
			initPatch();
			update();
		}
	}

	void GLWidget::setSelectedDatapoint_Z(double value)
	{
		if (value != patchData->operator()(patchSelectedRow, patchSelectedColumn)->z()) {
			patchData->operator()(patchSelectedRow, patchSelectedColumn)->setz(value);
			initPatch();
			update();
		}
	}

	void GLWidget::setPatchSize(int value)
	{
		patchSize = value;
		initPatchData();
		initPatch();
		update();
	}

	void GLWidget::set_show_shader(bool value)
	{
		show_shader = value;
		update();
	}

	void GLWidget::set_shader_index(int value)
	{
		shader_index = value;
		update();
	}

	void GLWidget::set_smoothing(double value)
	{
		smoothing = value;
		shaders[shader_index].Enable();
		shaders[shader_index].SetUniformVariable1f("smoothing", smoothing);
		shaders[shader_index].SetUniformVariable4f("default_outline_color", scaleFactor, smoothing, shading, 1.0f);
		shaders[shader_index].Disable();
		update();
	}

	void GLWidget::set_scaleFactor(double value)
	{
		scaleFactor = value;
		shaders[shader_index].Enable();
		shaders[shader_index].SetUniformVariable1f("scale_factor", scaleFactor);
		shaders[shader_index].SetUniformVariable4f("default_outline_color", scaleFactor, smoothing, shading, 1.0f);
		shaders[shader_index].Disable();
		update();
	}

	void GLWidget::set_shading(double value)
	{
		shading = value;
		shaders[shader_index].Enable();
		shaders[shader_index].SetUniformVariable1f("shading", shading);
		shaders[shader_index].SetUniformVariable4f("default_outline_color", scaleFactor, smoothing, shading, 1.0f);
		shaders[shader_index].Disable();
		update();
	}

	void GLWidget::setArcCount(int value)
	{
		arcCount = value;
		initArcData();
		initArc();
		update();
	}

	void GLWidget::setArcDivPointCount(int value)
	{
		arcDivPointCount = value;
		initArc();
		update();
	}

	void GLWidget::setArcDataIndex(int value)
	{
		if (value > 0) {
			arcDataIndex = value;
			setArcUiValues();
		}
	}

	void GLWidget::setArcData_X(double value)
	{
		arcData->operator[](arcDataIndex).setx(value);
		initArc();
		update();
	}

	void GLWidget::setArcData_Y(double value)
	{
		arcData->operator[](arcDataIndex).sety(value);
		initArc();
		update();
	}

	void GLWidget::setArcData_Z(double value)
	{
		arcData->operator[](arcDataIndex).setz(value);
		initArc();
		update();
	}

	void GLWidget::set_reloadSandbox(bool value)
	{
		reloadSandbox = value;
	}

	void GLWidget::_animate()
	{
		GLfloat* vertex[3];
		GLfloat* normal[3];

		for (GLuint i = 0; i < 3; i++) {
			vertex[i] = _images_of_model[i].MapVertexBuffer(GL_READ_WRITE);
			normal[i] = _images_of_model[i].MapNormalBuffer(GL_READ_ONLY);
		}
		_angle += DEG_TO_RADIAN;
		if (_angle >= TWO_PI)
			_angle -= TWO_PI;

		GLfloat scale = sin(_angle) / 4500.0;
		for (GLuint i = 0; i < 3; i++) {
			for (GLuint j = 0; j < _images_of_model[i].VertexCount(); ++j) {
				for (GLuint coordinate = 0; coordinate < 3; ++coordinate, ++vertex[i], ++normal[i]) {
					*vertex[i] += scale * (*normal[i]);
				}
			}
		}

		for (GLuint i = 0; i < 3; i++) {
			_images_of_model[i].UnmapVertexBuffer();
			_images_of_model[i].UnmapNormalBuffer();
		}
		update();
	}

	void GLWidget::setTextureIndex(int index)
	{
		if (index == 0)
		{
			textures[textureIndex - 1]->release();
		}
		textureIndex = index;
		initParametricSurfaces();
		update();
	}
	void GLWidget::setFirstDerivScale(double value)
	{
		pcFirstDerivScale = value;
		initParametricCurves();
	}
	void GLWidget::setSecondDerivScale(double value)
	{
		pcSecondDerivScale = value;
		initParametricCurves();
	}
	void GLWidget::setCyclicCoordinateIndex(int value)
	{
		cyclicCoordinateIndex = value;
		_sideWidget->cyclicCoordXSpinner->setValue(cyclicControlCoordinates[cyclicCoordinateIndex].x());
		_sideWidget->cyclicCoordYSpinner->setValue(cyclicControlCoordinates[cyclicCoordinateIndex].y());
		_sideWidget->cyclicCoordZSpinner->setValue(cyclicControlCoordinates[cyclicCoordinateIndex].z());
	}
	void GLWidget::setCyclicCoordinateX(double value)
	{
		cyclicControlCoordinates[cyclicCoordinateIndex].setx(value);
		initCyclicCurve();
		update();
	}
	void GLWidget::setCyclicCoordinateY(double value)
	{
		cyclicControlCoordinates[cyclicCoordinateIndex].sety(value);
		initCyclicCurve();
		update();
	}
	void GLWidget::setCyclicCoordinateZ(double value)
	{
		cyclicControlCoordinates[cyclicCoordinateIndex].setz(value);
		initCyclicCurve();
		update();
	}
}
