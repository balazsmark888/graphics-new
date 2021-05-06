#include "MainWindow.h"

namespace cagd {
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

    /*

    the structure of the main window's central widget
            
            *---------------------------------------------------*
        |                 central widget                    |
        |                                                   |
        |  *---------------------------*-----------------*  |
        |  |     rendering context     |   scroll area   |  |
        |  |       OpenGL widget       | *-------------* |  |
        |  |                           | | side widget | |  |
        |  |                           | |             | |  |
        |  |                           | |             | |  |
        |  |                           | *-------------* |  |
        |  *---------------------------*-----------------*  |
        |                                                   |
            *---------------------------------------------------*
                    
                    */
    _side_widget = new SideWidget(this);

    _scroll_area = new QScrollArea(this);
    _scroll_area->setWidget(_side_widget);
    _scroll_area->setSizePolicy(_side_widget->sizePolicy());
    _scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    _gl_widget = new GLWidget(this);
    _gl_widget->_sideWidget = _side_widget;

    centralWidget()->setLayout(new QHBoxLayout());
    centralWidget()->layout()->addWidget(_gl_widget);
    centralWidget()->layout()->addWidget(_scroll_area);

    // creating a signal slot mechanism between the rendering context and the side widget
    connect(_side_widget->rotate_x_slider,
            SIGNAL(valueChanged(int)),
            _gl_widget,
            SLOT(set_angle_x(int)));
    connect(_side_widget->rotate_y_slider,
            SIGNAL(valueChanged(int)),
            _gl_widget,
            SLOT(set_angle_y(int)));
    connect(_side_widget->rotate_z_slider,
            SIGNAL(valueChanged(int)),
            _gl_widget,
            SLOT(set_angle_z(int)));

    connect(_side_widget->zoom_factor_spin_box,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_zoom_factor(double)));

    connect(_side_widget->trans_x_spin_box,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_trans_x(double)));
    connect(_side_widget->trans_y_spin_box,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_trans_y(double)));
    connect(_side_widget->trans_z_spin_box,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_trans_z(double)));
    connect(_side_widget->firstDerivScaleSpinner,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(setFirstDerivScale(double)));
    connect(_side_widget->secondDerivScaleSpinner,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(setSecondDerivScale(double)));

    connect(_side_widget->pc_combo_box,
            SIGNAL(currentIndexChanged(int)),
            _gl_widget,
            SLOT(set_selected_curve_index(int)));
    connect(_side_widget->ps_combo_box,
            SIGNAL(currentIndexChanged(int)),
            _gl_widget,
            SLOT(set_selected_surface_index(int)));
    connect(_side_widget->textureComboBox,
            SIGNAL(currentIndexChanged(int)),
            _gl_widget,
            SLOT(setTextureIndex(int)));
    connect(_side_widget->pcDivisionPointsSpinBox,
            SIGNAL(valueChanged(int)),
            _gl_widget,
            SLOT(set_division_points(int)));
    connect(_side_widget->pcFirstDerivCheckBox,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_first_derivative(bool)));
    connect(_side_widget->pcSecondDerivCheckBox,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_second_derivative(bool)));

    connect(_side_widget->model_combo_box,
            SIGNAL(currentIndexChanged(int)),
            _gl_widget,
            SLOT(set_selected_model_index(int)));
    connect(_side_widget->imageComboBox,
            SIGNAL(currentIndexChanged(int)),
            _gl_widget,
            SLOT(set_image_index(int)));
    connect(_side_widget->cPolygon,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_isCyclicPolygon(bool)));
    connect(_side_widget->cNoInterp,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_isCyclicCurveNoInterpolation(bool)));
    connect(_side_widget->cFirstDeriv,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_isCyclicFirstDeriv(bool)));
    connect(_side_widget->cSecondDeriv,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_isCyclicSecondDeriv(bool)));
    connect(_side_widget->cInterp,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_isCyclicInterpolated(bool)));
    connect(_side_widget->aPolygon,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_isBiquarticPolygon(bool)));
    connect(_side_widget->aFirstDeriv,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_isBiquarticFirstDeriv(bool)));
    connect(_side_widget->aSecondDeriv,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_isBiquarticSecondDeriv(bool)));
    connect(_side_widget->aNoInterp,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_isBiquarticArcNoInterpolation(bool)));
    connect(_side_widget->pData, SIGNAL(toggled(bool)), _gl_widget, SLOT(set_isBiquarticData(bool)));
    connect(_side_widget->pNoInterp,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_isBiquarticNoInterpolation(bool)));
    connect(_side_widget->pInterp,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_isBiquarticInterpolated(bool)));
    connect(_side_widget->showShader,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_show_shader(bool)));
    connect(_side_widget->sandboxCheckbox,
            SIGNAL(toggled(bool)),
            _gl_widget,
            SLOT(set_reloadSandbox(bool)));
    connect(_side_widget->shaderComboBox,
            SIGNAL(currentIndexChanged(int)),
            _gl_widget,
            SLOT(set_shader_index(int)));
    connect(_side_widget->smoothingSpinBox,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_smoothing(double)));
    connect(_side_widget->scaleFactorSpinBox,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_scaleFactor(double)));
    connect(_side_widget->shadingSpinBox,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_shading(double)));
    connect(_side_widget->arcSpinbox1,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_ArcVectorValue1_1(double)));
    connect(_side_widget->arcSpinbox1_2,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_ArcVectorValue1_2(double)));
    connect(_side_widget->arcSpinbox1_3,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_ArcVectorValue1_3(double)));
    connect(_side_widget->arcSpinbox2,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_ArcVectorValue2_1(double)));
    connect(_side_widget->arcSpinbox2_2,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_ArcVectorValue2_2(double)));
    connect(_side_widget->arcSpinbox2_3,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_ArcVectorValue2_3(double)));
    connect(_side_widget->arcSpinbox3,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_ArcVectorValue3_1(double)));
    connect(_side_widget->arcSpinbox3_2,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_ArcVectorValue3_2(double)));
    connect(_side_widget->arcSpinbox3_3,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_ArcVectorValue3_3(double)));
    connect(_side_widget->arcSpinbox4,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_ArcVectorValue4_1(double)));
    connect(_side_widget->arcSpinbox4_2,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_ArcVectorValue4_2(double)));
    connect(_side_widget->arcSpinbox4_3,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(set_ArcVectorValue4_3(double)));

    connect(_side_widget->cyclicCoordIndexComboBox,
            SIGNAL(currentIndexChanged(int)),
            _gl_widget,
            SLOT(setCyclicCoordinateIndex(int)));
    connect(_side_widget->cyclicCoordXSpinner,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(setCyclicCoordinateX(double)));
    connect(_side_widget->cyclicCoordYSpinner,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(setCyclicCoordinateY(double)));
    connect(_side_widget->cyclicCoordZSpinner,
            SIGNAL(valueChanged(double)),
            _gl_widget,
            SLOT(setCyclicCoordinateZ(double)));
}

//--------------------------------
// implementation of private slots
//--------------------------------
void MainWindow::on_action_Quit_triggered()
{
    qApp->exit(0);
}
} // namespace cagd
