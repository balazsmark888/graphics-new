#pragma once

#include <GL/glew.h>
#include <QtOpenGLWidgets/qopenglwidget.h>
#include "Parametric/ParametricCurves3.h"
#include "Parametric/ParametricSurfaces3.h"
#include "Core/BiquarticArc.h"
#include "Core/BiquarticPatch.h"
#include "Core/TriangulatedMeshes3.h"
#include "Core/CyclicCurves3.h"
#include "Core/ShaderPrograms.h"
#include "Core/Lights.h"
#include <Sandbox.h>
#include <qtimer.h>
#include <QOpenGLTexture>

namespace cagd
{
    class GLWidget: public QOpenGLWidget
    {
        Q_OBJECT

    private:

        QTimer* _timer;
        GLfloat _angle;

        // variables defining the projection matrix
        double       _aspect;            // aspect ratio of the rendering window
        double       _fovy;              // field of view in direction y
        double       _z_near, _z_far;    // distance of near and far clipping planes

        // variables defining the model-view matrix
        double       _eye[3], _center[3], _up[3];

        // variables needed by transformations
        int         _angle_x, _angle_y, _angle_z;
        double      _zoom;
        double      _trans_x, _trans_y, _trans_z;

        // your other declarations
        int image_index = 0;

        int pc_index = 0;
        int pcDivisionPoints = 500;
        bool isFirstDerivative = true;
        bool isSecondDerivative = true;
        bool isParametricCurve = false;
        ParametricCurve3* _pcs[6];
        GenericCurve3* _images_of_pc[6];

        int ps_index = 0;

        bool isParametricSurface = false;
        bool isModel = false;

        int model_index = 0;
        double scaleFactor = 4.0;
        double smoothing = 2.0;
        double shading = 1.0;

        Sandbox sandbox;
        bool reloadSandbox = false;

        bool isCyclicCurveNoInterpolation = false;
        bool isCyclicPolygon = false;
        bool isCyclicFirstDeriv = false;
        bool isCyclicSecondDeriv = false;
        bool isCyclicInterpolated = false;

        bool isBiquarticPolygon = false;
        bool isBiquarticFirstDeriv = false;
        bool isBiquarticSecondDeriv = false;
        bool isBiquarticArcNoInterpolation = false;

        bool isBiquarticData = false;
        bool isBiquarticNoInterpolation = false;
        bool isBiquarticInterpolated = false;
        

        ParametricSurface3 *_pss[6];

        RowMatrix<TriangulatedMesh3> _images_of_model;
        TriangulatedMesh3 *_images_of_ps[5];

        BiquarticArc *bArc;
        GenericCurve3 *bArcImage;

        CyclicCurve3 *cCurve;
        GenericCurve3 *cCurveImage;
        GenericCurve3 *cCurveImageInterpolated;

        BiquarticPatch *bPatch;
        TriangulatedMesh3 *bPatchImage;
        TriangulatedMesh3 *bPatchImageInterpolated;

        ShaderProgram shader;
        RowMatrix<ShaderProgram> shaders;
        GLint shader_index = 0;
        bool show_shader = false;
        RowMatrix<float> default_outline_color;

        DirectionalLight *dl;

        int textureIndex = 0;
        QOpenGLTexture* textures[10];

    public:
        // special and default constructor
        // the format specifies the properties of the rendering window
        GLWidget(QWidget* parent = 0);

        

        // redeclared virtual functions
        void initializeGL();
        void paintGL();
        void resizeGL(int w, int h);

        void initParametricCurves();
        void showParametricCurves();

        void initModels();
        void showModels();

        void initSandbox();
        void showSandbox();

        void initShaders();
        void initTextures();

        void initParametricSurfaces();
        void showParametricSurfaces();

    public slots:
        // public event handling methods/slots
        void set_angle_x(int value);
        void set_angle_y(int value);
        void set_angle_z(int value);

        void set_zoom_factor(double value);

        void set_trans_x(double value);
        void set_trans_y(double value);
        void set_trans_z(double value);

        void set_selected_curve_index(int value);
        void set_division_points(int value);
        void set_first_derivative(bool value);
        void set_second_derivative(bool value);

        void set_selected_surface_index(int value);

        void set_selected_model_index(int value);

        void set_image_index(int value);

        void set_isCyclicCurveNoInterpolation(bool value);
        void set_isCyclicPolygon(bool value);
        void set_isCyclicFirstDeriv(bool value);
        void set_isCyclicSecondDeriv(bool value);
        void set_isCyclicInterpolated(bool value);

        void set_isBiquarticPolygon(bool value);
        void set_isBiquarticFirstDeriv(bool value);
        void set_isBiquarticSecondDeriv(bool value);
        void set_isBiquarticArcNoInterpolation(bool value);

        void set_isBiquarticData(bool value);
        void set_isBiquarticNoInterpolation(bool value);
        void set_isBiquarticInterpolated(bool value);

        void set_shader_index(int value);
        void set_show_shader(bool value);

        void set_smoothing(double value);
        void set_scaleFactor(double value);
        void set_shading(double value);

        void set_ArcVectorValue1_1(double value);
        void set_ArcVectorValue1_2(double value);
        void set_ArcVectorValue1_3(double value);
        void set_ArcVectorValue2_1(double value);
        void set_ArcVectorValue2_2(double value);
        void set_ArcVectorValue2_3(double value);
        void set_ArcVectorValue3_1(double value);
        void set_ArcVectorValue3_2(double value);
        void set_ArcVectorValue3_3(double value);
        void set_ArcVectorValue4_1(double value);
        void set_ArcVectorValue4_2(double value);
        void set_ArcVectorValue4_3(double value);

        void set_reloadSandbox(bool value);
        void _animate();

        void setTextureIndex(int index);
    };
}
