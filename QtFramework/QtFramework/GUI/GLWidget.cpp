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
			_angle = 0;
			_timer->start();
			initParametricCurves();
			initModels();
			initShaders();
			initSandbox();
			initParametricSurfaces();
			initTextures();
			initCyclicControlCoordinates();
			initCyclicCurve();
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
			//                case 4:
			//                    showBiquarticArc();
			//                    break;
			//                case 5:
			//                    showBiquarticPatch();
			//                    break;
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
		isBiquarticPolygon = value;
		update();
	}

	void GLWidget::set_isBiquarticFirstDeriv(bool value)
	{
		isBiquarticFirstDeriv = value;
		update();
	}

	void GLWidget::set_isBiquarticSecondDeriv(bool value)
	{
		isBiquarticSecondDeriv = value;
		update();
	}

	void GLWidget::set_isBiquarticArcNoInterpolation(bool value)
	{
		isBiquarticArcNoInterpolation = value;
		update();
	}

	void GLWidget::set_isBiquarticData(bool value)
	{
		isBiquarticData = value;
		update();
	}

	void GLWidget::set_isBiquarticNoInterpolation(bool value)
	{
		isBiquarticNoInterpolation = value;
		update();
	}

	void GLWidget::set_isBiquarticInterpolated(bool value)
	{
		isBiquarticInterpolated = value;
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

	void GLWidget::set_ArcVectorValue1_1(double value)
	{
		DCoordinate3 temp = (*bArc)[0];
		temp.setx(value);
		(*bArc)[0] = temp;
		bArc->UpdateVertexBufferObjectsOfData();
		bArcImage = bArc->GenerateImage(2, 20, GL_STATIC_DRAW);

		if (bArcImage) {
			bArcImage->UpdateVertexBufferObjects();
		}
		update();
	}

	void GLWidget::set_ArcVectorValue1_2(double value)
	{
		DCoordinate3 temp = (*bArc)[0];
		temp.sety(value);
		(*bArc)[0] = temp;
		bArc->UpdateVertexBufferObjectsOfData();
		bArcImage = bArc->GenerateImage(2, 20, GL_STATIC_DRAW);

		if (bArcImage) {
			bArcImage->UpdateVertexBufferObjects();
		}
		update();
	}

	void GLWidget::set_ArcVectorValue1_3(double value)
	{
		DCoordinate3 temp = (*bArc)[0];
		temp.setz(value);
		(*bArc)[0] = temp;
		bArc->UpdateVertexBufferObjectsOfData();
		bArcImage = bArc->GenerateImage(2, 20, GL_STATIC_DRAW);

		if (bArcImage) {
			bArcImage->UpdateVertexBufferObjects();
		}
		update();
	}

	void GLWidget::set_ArcVectorValue2_1(double value)
	{
		DCoordinate3 temp = (*bArc)[1];
		temp.setx(value);
		(*bArc)[1] = temp;
		bArc->UpdateVertexBufferObjectsOfData();
		bArcImage = bArc->GenerateImage(2, 20, GL_STATIC_DRAW);

		if (bArcImage) {
			bArcImage->UpdateVertexBufferObjects();
		}
		update();
	}

	void GLWidget::set_ArcVectorValue2_2(double value)
	{
		DCoordinate3 temp = (*bArc)[1];
		temp.sety(value);
		(*bArc)[1] = temp;
		bArc->UpdateVertexBufferObjectsOfData();
		bArcImage = bArc->GenerateImage(2, 20, GL_STATIC_DRAW);

		if (bArcImage) {
			bArcImage->UpdateVertexBufferObjects();
		}
		update();
	}

	void GLWidget::set_ArcVectorValue2_3(double value)
	{
		DCoordinate3 temp = (*bArc)[1];
		temp.setz(value);
		(*bArc)[1] = temp;
		bArc->UpdateVertexBufferObjectsOfData();
		bArcImage = bArc->GenerateImage(2, 20, GL_STATIC_DRAW);

		if (bArcImage) {
			bArcImage->UpdateVertexBufferObjects();
		}
		update();
	}

	void GLWidget::set_ArcVectorValue3_1(double value)
	{
		DCoordinate3 temp = (*bArc)[2];
		temp.setx(value);
		(*bArc)[2] = temp;
		bArc->UpdateVertexBufferObjectsOfData();
		bArcImage = bArc->GenerateImage(2, 20, GL_STATIC_DRAW);

		if (bArcImage) {
			bArcImage->UpdateVertexBufferObjects();
		}
		update();
	}

	void GLWidget::set_ArcVectorValue3_2(double value)
	{
		DCoordinate3 temp = (*bArc)[2];
		temp.sety(value);
		(*bArc)[2] = temp;
		bArc->UpdateVertexBufferObjectsOfData();
		bArcImage = bArc->GenerateImage(2, 20, GL_STATIC_DRAW);

		if (bArcImage) {
			bArcImage->UpdateVertexBufferObjects();
		}
		update();
	}

	void GLWidget::set_ArcVectorValue3_3(double value)
	{
		DCoordinate3 temp = (*bArc)[2];
		temp.setz(value);
		(*bArc)[2] = temp;
		bArc->UpdateVertexBufferObjectsOfData();
		bArcImage = bArc->GenerateImage(2, 20, GL_STATIC_DRAW);

		if (bArcImage) {
			bArcImage->UpdateVertexBufferObjects();
		}
		update();
	}

	void GLWidget::set_ArcVectorValue4_1(double value)
	{
		DCoordinate3 temp = (*bArc)[3];
		temp.setx(value);
		(*bArc)[3] = temp;
		bArc->UpdateVertexBufferObjectsOfData();
		bArcImage = bArc->GenerateImage(2, 20, GL_STATIC_DRAW);

		if (bArcImage) {
			bArcImage->UpdateVertexBufferObjects();
		}
		update();
	}

	void GLWidget::set_ArcVectorValue4_2(double value)
	{
		DCoordinate3 temp = (*bArc)[3];
		temp.sety(value);
		(*bArc)[3] = temp;
		bArc->UpdateVertexBufferObjectsOfData();
		bArcImage = bArc->GenerateImage(2, 20, GL_STATIC_DRAW);

		if (bArcImage) {
			bArcImage->UpdateVertexBufferObjects();
		}
		update();
	}

	void GLWidget::set_ArcVectorValue4_3(double value)
	{
		DCoordinate3 temp = (*bArc)[3];
		temp.setz(value);
		(*bArc)[3] = temp;
		bArc->UpdateVertexBufferObjectsOfData();
		bArcImage = bArc->GenerateImage(2, 20, GL_STATIC_DRAW);

		if (bArcImage) {
			bArcImage->UpdateVertexBufferObjects();
		}
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
