/********************************************************************************
** Form generated from reading UI file 'SideWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEWIDGET_H
#define UI_SIDEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SideWidget
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QSlider *rotate_x_slider;
    QLabel *label_2;
    QSlider *rotate_y_slider;
    QLabel *label_3;
    QSlider *rotate_z_slider;
    QLabel *label_4;
    QDoubleSpinBox *zoom_factor_spin_box;
    QLabel *label_5;
    QDoubleSpinBox *trans_x_spin_box;
    QLabel *label_6;
    QDoubleSpinBox *trans_y_spin_box;
    QLabel *label_7;
    QDoubleSpinBox *trans_z_spin_box;
    QTabWidget *tabWidget;
    QWidget *tabHomework;
    QComboBox *model_combo_box;
    QLabel *label_8;
    QComboBox *ps_combo_box;
    QComboBox *pc_combo_box;
    QLabel *label_10;
    QLabel *label_9;
    QSpinBox *pcDivisionPointsSpinBox;
    QLabel *label_25;
    QCheckBox *pcFirstDerivCheckBox;
    QCheckBox *pcSecondDerivCheckBox;
    QCheckBox *sandboxCheckbox;
    QLabel *label_19;
    QComboBox *textureComboBox;
    QDoubleSpinBox *firstDerivScaleSpinner;
    QDoubleSpinBox *secondDerivScaleSpinner;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_12;
    QCheckBox *cNoInterp;
    QCheckBox *cPolygon;
    QDoubleSpinBox *cyclicCoordYSpinner;
    QComboBox *cyclicCoordIndexComboBox;
    QDoubleSpinBox *cyclicCoordXSpinner;
    QDoubleSpinBox *cyclicCoordZSpinner;
    QCheckBox *cSecondDeriv;
    QCheckBox *cInterp;
    QCheckBox *cFirstDeriv;
    QWidget *tabProject;
    QLabel *label_13;
    QCheckBox *aFirstDeriv;
    QCheckBox *aNoInterp;
    QCheckBox *aSecondDeriv;
    QCheckBox *aPolygon;
    QDoubleSpinBox *arcDataSpinner_Y;
    QSpinBox *arcDivPointCountSpinner;
    QDoubleSpinBox *arcDataSpinner_Z;
    QDoubleSpinBox *arcDataSpinner_X;
    QComboBox *arcDataIndexComboBox;
    QLabel *label_27;
    QSpinBox *arcCountSpinner;
    QLabel *label_28;
    QWidget *tab;
    QLabel *label_14;
    QCheckBox *pData;
    QComboBox *patchDataPointComboBox_row;
    QDoubleSpinBox *patchDataPointSpinner_X;
    QDoubleSpinBox *patchDataPointSpinner_Y;
    QDoubleSpinBox *patchDataPointSpinner_Z;
    QCheckBox *patchIsoCurvesBox_V;
    QCheckBox *pInterp;
    QCheckBox *pNoInterp;
    QCheckBox *patchIsoCurvesBox_U;
    QSpinBox *patchDivPointSpinner_U;
    QSpinBox *patchDivPointSpinner_V;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QComboBox *patchDataPointComboBox_col;
    QSpinBox *patchCountSpinner;
    QLabel *label_26;
    QWidget *tab_2;
    QLabel *label_15;
    QDoubleSpinBox *smoothingSpinBox;
    QDoubleSpinBox *shadingSpinBox;
    QCheckBox *showShader;
    QLabel *label_16;
    QDoubleSpinBox *scaleFactorSpinBox;
    QLabel *label_17;
    QComboBox *shaderComboBox;
    QLabel *label_18;
    QComboBox *imageComboBox;
    QLabel *label_11;

    void setupUi(QWidget *SideWidget)
    {
        if (SideWidget->objectName().isEmpty())
            SideWidget->setObjectName(QString::fromUtf8("SideWidget"));
        SideWidget->resize(289, 926);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SideWidget->sizePolicy().hasHeightForWidth());
        SideWidget->setSizePolicy(sizePolicy);
        SideWidget->setMinimumSize(QSize(269, 0));
        groupBox = new QGroupBox(SideWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 271, 221));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(3, 21, 261, 192));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        rotate_x_slider = new QSlider(layoutWidget);
        rotate_x_slider->setObjectName(QString::fromUtf8("rotate_x_slider"));
        rotate_x_slider->setMinimum(-180);
        rotate_x_slider->setMaximum(180);
        rotate_x_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, rotate_x_slider);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        rotate_y_slider = new QSlider(layoutWidget);
        rotate_y_slider->setObjectName(QString::fromUtf8("rotate_y_slider"));
        rotate_y_slider->setMinimum(-180);
        rotate_y_slider->setMaximum(180);
        rotate_y_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, rotate_y_slider);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        rotate_z_slider = new QSlider(layoutWidget);
        rotate_z_slider->setObjectName(QString::fromUtf8("rotate_z_slider"));
        rotate_z_slider->setMinimum(-180);
        rotate_z_slider->setMaximum(180);
        rotate_z_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(2, QFormLayout::FieldRole, rotate_z_slider);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        zoom_factor_spin_box = new QDoubleSpinBox(layoutWidget);
        zoom_factor_spin_box->setObjectName(QString::fromUtf8("zoom_factor_spin_box"));
        zoom_factor_spin_box->setDecimals(5);
        zoom_factor_spin_box->setMinimum(0.000100000000000);
        zoom_factor_spin_box->setMaximum(10000.000000000000000);
        zoom_factor_spin_box->setSingleStep(0.100000000000000);
        zoom_factor_spin_box->setValue(1.000000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, zoom_factor_spin_box);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        trans_x_spin_box = new QDoubleSpinBox(layoutWidget);
        trans_x_spin_box->setObjectName(QString::fromUtf8("trans_x_spin_box"));
        trans_x_spin_box->setMinimum(-100.000000000000000);
        trans_x_spin_box->setMaximum(100.000000000000000);
        trans_x_spin_box->setSingleStep(0.100000000000000);

        formLayout->setWidget(4, QFormLayout::FieldRole, trans_x_spin_box);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        trans_y_spin_box = new QDoubleSpinBox(layoutWidget);
        trans_y_spin_box->setObjectName(QString::fromUtf8("trans_y_spin_box"));
        trans_y_spin_box->setMinimum(-100.000000000000000);
        trans_y_spin_box->setMaximum(100.000000000000000);
        trans_y_spin_box->setSingleStep(0.100000000000000);

        formLayout->setWidget(5, QFormLayout::FieldRole, trans_y_spin_box);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        trans_z_spin_box = new QDoubleSpinBox(layoutWidget);
        trans_z_spin_box->setObjectName(QString::fromUtf8("trans_z_spin_box"));
        trans_z_spin_box->setMinimum(-100.000000000000000);
        trans_z_spin_box->setMaximum(100.000000000000000);
        trans_z_spin_box->setSingleStep(0.100000000000000);

        formLayout->setWidget(6, QFormLayout::FieldRole, trans_z_spin_box);

        tabWidget = new QTabWidget(SideWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(-3, 270, 301, 531));
        tabHomework = new QWidget();
        tabHomework->setObjectName(QString::fromUtf8("tabHomework"));
        model_combo_box = new QComboBox(tabHomework);
        model_combo_box->addItem(QString());
        model_combo_box->addItem(QString());
        model_combo_box->addItem(QString());
        model_combo_box->addItem(QString());
        model_combo_box->addItem(QString());
        model_combo_box->addItem(QString());
        model_combo_box->addItem(QString());
        model_combo_box->addItem(QString());
        model_combo_box->setObjectName(QString::fromUtf8("model_combo_box"));
        model_combo_box->setGeometry(QRect(130, 250, 131, 22));
        label_8 = new QLabel(tabHomework);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 10, 131, 16));
        ps_combo_box = new QComboBox(tabHomework);
        ps_combo_box->addItem(QString());
        ps_combo_box->addItem(QString());
        ps_combo_box->addItem(QString());
        ps_combo_box->addItem(QString());
        ps_combo_box->addItem(QString());
        ps_combo_box->setObjectName(QString::fromUtf8("ps_combo_box"));
        ps_combo_box->setGeometry(QRect(130, 170, 131, 22));
        pc_combo_box = new QComboBox(tabHomework);
        pc_combo_box->addItem(QString());
        pc_combo_box->addItem(QString());
        pc_combo_box->addItem(QString());
        pc_combo_box->addItem(QString());
        pc_combo_box->addItem(QString());
        pc_combo_box->addItem(QString());
        pc_combo_box->setObjectName(QString::fromUtf8("pc_combo_box"));
        pc_combo_box->setGeometry(QRect(130, 10, 131, 22));
        label_10 = new QLabel(tabHomework);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 250, 131, 16));
        label_9 = new QLabel(tabHomework);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 170, 131, 16));
        pcDivisionPointsSpinBox = new QSpinBox(tabHomework);
        pcDivisionPointsSpinBox->setObjectName(QString::fromUtf8("pcDivisionPointsSpinBox"));
        pcDivisionPointsSpinBox->setGeometry(QRect(130, 50, 61, 22));
        pcDivisionPointsSpinBox->setMinimum(1);
        pcDivisionPointsSpinBox->setMaximum(10000);
        pcDivisionPointsSpinBox->setSingleStep(5);
        pcDivisionPointsSpinBox->setValue(500);
        label_25 = new QLabel(tabHomework);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 50, 91, 16));
        pcFirstDerivCheckBox = new QCheckBox(tabHomework);
        pcFirstDerivCheckBox->setObjectName(QString::fromUtf8("pcFirstDerivCheckBox"));
        pcFirstDerivCheckBox->setGeometry(QRect(10, 80, 76, 20));
        pcFirstDerivCheckBox->setChecked(true);
        pcSecondDerivCheckBox = new QCheckBox(tabHomework);
        pcSecondDerivCheckBox->setObjectName(QString::fromUtf8("pcSecondDerivCheckBox"));
        pcSecondDerivCheckBox->setGeometry(QRect(130, 80, 76, 20));
        pcSecondDerivCheckBox->setChecked(true);
        sandboxCheckbox = new QCheckBox(tabHomework);
        sandboxCheckbox->setObjectName(QString::fromUtf8("sandboxCheckbox"));
        sandboxCheckbox->setGeometry(QRect(10, 450, 91, 20));
        label_19 = new QLabel(tabHomework);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 430, 49, 16));
        textureComboBox = new QComboBox(tabHomework);
        textureComboBox->addItem(QString());
        textureComboBox->addItem(QString());
        textureComboBox->addItem(QString());
        textureComboBox->addItem(QString());
        textureComboBox->addItem(QString());
        textureComboBox->addItem(QString());
        textureComboBox->addItem(QString());
        textureComboBox->addItem(QString());
        textureComboBox->addItem(QString());
        textureComboBox->addItem(QString());
        textureComboBox->addItem(QString());
        textureComboBox->setObjectName(QString::fromUtf8("textureComboBox"));
        textureComboBox->setGeometry(QRect(130, 210, 131, 22));
        firstDerivScaleSpinner = new QDoubleSpinBox(tabHomework);
        firstDerivScaleSpinner->setObjectName(QString::fromUtf8("firstDerivScaleSpinner"));
        firstDerivScaleSpinner->setGeometry(QRect(130, 110, 62, 22));
        firstDerivScaleSpinner->setSingleStep(0.200000000000000);
        firstDerivScaleSpinner->setValue(1.000000000000000);
        secondDerivScaleSpinner = new QDoubleSpinBox(tabHomework);
        secondDerivScaleSpinner->setObjectName(QString::fromUtf8("secondDerivScaleSpinner"));
        secondDerivScaleSpinner->setGeometry(QRect(130, 140, 62, 22));
        secondDerivScaleSpinner->setSingleStep(0.200000000000000);
        secondDerivScaleSpinner->setValue(1.000000000000000);
        label_20 = new QLabel(tabHomework);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 110, 81, 16));
        label_21 = new QLabel(tabHomework);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 140, 81, 16));
        label_12 = new QLabel(tabHomework);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 280, 131, 16));
        cNoInterp = new QCheckBox(tabHomework);
        cNoInterp->setObjectName(QString::fromUtf8("cNoInterp"));
        cNoInterp->setGeometry(QRect(80, 300, 81, 17));
        cPolygon = new QCheckBox(tabHomework);
        cPolygon->setObjectName(QString::fromUtf8("cPolygon"));
        cPolygon->setGeometry(QRect(10, 300, 70, 17));
        cyclicCoordYSpinner = new QDoubleSpinBox(tabHomework);
        cyclicCoordYSpinner->setObjectName(QString::fromUtf8("cyclicCoordYSpinner"));
        cyclicCoordYSpinner->setGeometry(QRect(80, 380, 51, 22));
        cyclicCoordYSpinner->setMinimum(-99.000000000000000);
        cyclicCoordYSpinner->setSingleStep(0.100000000000000);
        cyclicCoordIndexComboBox = new QComboBox(tabHomework);
        cyclicCoordIndexComboBox->addItem(QString());
        cyclicCoordIndexComboBox->addItem(QString());
        cyclicCoordIndexComboBox->addItem(QString());
        cyclicCoordIndexComboBox->addItem(QString());
        cyclicCoordIndexComboBox->addItem(QString());
        cyclicCoordIndexComboBox->addItem(QString());
        cyclicCoordIndexComboBox->setObjectName(QString::fromUtf8("cyclicCoordIndexComboBox"));
        cyclicCoordIndexComboBox->setGeometry(QRect(20, 350, 69, 22));
        cyclicCoordXSpinner = new QDoubleSpinBox(tabHomework);
        cyclicCoordXSpinner->setObjectName(QString::fromUtf8("cyclicCoordXSpinner"));
        cyclicCoordXSpinner->setGeometry(QRect(20, 380, 51, 22));
        cyclicCoordXSpinner->setMinimum(-99.000000000000000);
        cyclicCoordXSpinner->setSingleStep(0.100000000000000);
        cyclicCoordZSpinner = new QDoubleSpinBox(tabHomework);
        cyclicCoordZSpinner->setObjectName(QString::fromUtf8("cyclicCoordZSpinner"));
        cyclicCoordZSpinner->setGeometry(QRect(140, 380, 51, 22));
        cyclicCoordZSpinner->setMinimum(-99.000000000000000);
        cyclicCoordZSpinner->setSingleStep(0.100000000000000);
        cSecondDeriv = new QCheckBox(tabHomework);
        cSecondDeriv->setObjectName(QString::fromUtf8("cSecondDeriv"));
        cSecondDeriv->setGeometry(QRect(190, 320, 70, 17));
        cInterp = new QCheckBox(tabHomework);
        cInterp->setObjectName(QString::fromUtf8("cInterp"));
        cInterp->setGeometry(QRect(80, 320, 81, 17));
        cFirstDeriv = new QCheckBox(tabHomework);
        cFirstDeriv->setObjectName(QString::fromUtf8("cFirstDeriv"));
        cFirstDeriv->setGeometry(QRect(190, 300, 70, 17));
        tabWidget->addTab(tabHomework, QString());
        tabProject = new QWidget();
        tabProject->setObjectName(QString::fromUtf8("tabProject"));
        label_13 = new QLabel(tabProject);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 20, 131, 16));
        aFirstDeriv = new QCheckBox(tabProject);
        aFirstDeriv->setObjectName(QString::fromUtf8("aFirstDeriv"));
        aFirstDeriv->setGeometry(QRect(10, 190, 81, 17));
        aNoInterp = new QCheckBox(tabProject);
        aNoInterp->setObjectName(QString::fromUtf8("aNoInterp"));
        aNoInterp->setGeometry(QRect(10, 230, 81, 17));
        aSecondDeriv = new QCheckBox(tabProject);
        aSecondDeriv->setObjectName(QString::fromUtf8("aSecondDeriv"));
        aSecondDeriv->setGeometry(QRect(10, 210, 81, 17));
        aPolygon = new QCheckBox(tabProject);
        aPolygon->setObjectName(QString::fromUtf8("aPolygon"));
        aPolygon->setGeometry(QRect(10, 40, 111, 17));
        arcDataSpinner_Y = new QDoubleSpinBox(tabProject);
        arcDataSpinner_Y->setObjectName(QString::fromUtf8("arcDataSpinner_Y"));
        arcDataSpinner_Y->setGeometry(QRect(100, 100, 62, 22));
        arcDataSpinner_Y->setMinimum(-99.000000000000000);
        arcDataSpinner_Y->setSingleStep(0.200000000000000);
        arcDivPointCountSpinner = new QSpinBox(tabProject);
        arcDivPointCountSpinner->setObjectName(QString::fromUtf8("arcDivPointCountSpinner"));
        arcDivPointCountSpinner->setGeometry(QRect(10, 160, 42, 22));
        arcDivPointCountSpinner->setMinimum(10);
        arcDivPointCountSpinner->setMaximum(999);
        arcDivPointCountSpinner->setValue(50);
        arcDataSpinner_Z = new QDoubleSpinBox(tabProject);
        arcDataSpinner_Z->setObjectName(QString::fromUtf8("arcDataSpinner_Z"));
        arcDataSpinner_Z->setGeometry(QRect(190, 100, 62, 22));
        arcDataSpinner_Z->setMinimum(-99.000000000000000);
        arcDataSpinner_Z->setSingleStep(0.200000000000000);
        arcDataSpinner_X = new QDoubleSpinBox(tabProject);
        arcDataSpinner_X->setObjectName(QString::fromUtf8("arcDataSpinner_X"));
        arcDataSpinner_X->setGeometry(QRect(10, 100, 62, 22));
        arcDataSpinner_X->setMinimum(-99.000000000000000);
        arcDataSpinner_X->setSingleStep(0.200000000000000);
        arcDataIndexComboBox = new QComboBox(tabProject);
        arcDataIndexComboBox->setObjectName(QString::fromUtf8("arcDataIndexComboBox"));
        arcDataIndexComboBox->setGeometry(QRect(10, 70, 131, 22));
        label_27 = new QLabel(tabProject);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(10, 140, 81, 16));
        arcCountSpinner = new QSpinBox(tabProject);
        arcCountSpinner->setObjectName(QString::fromUtf8("arcCountSpinner"));
        arcCountSpinner->setGeometry(QRect(10, 290, 51, 22));
        arcCountSpinner->setMinimum(1);
        arcCountSpinner->setMaximum(99);
        label_28 = new QLabel(tabProject);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(10, 270, 81, 16));
        tabWidget->addTab(tabProject, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 0, 131, 16));
        pData = new QCheckBox(tab);
        pData->setObjectName(QString::fromUtf8("pData"));
        pData->setGeometry(QRect(10, 20, 81, 21));
        patchDataPointComboBox_row = new QComboBox(tab);
        patchDataPointComboBox_row->setObjectName(QString::fromUtf8("patchDataPointComboBox_row"));
        patchDataPointComboBox_row->setGeometry(QRect(10, 50, 111, 22));
        patchDataPointSpinner_X = new QDoubleSpinBox(tab);
        patchDataPointSpinner_X->setObjectName(QString::fromUtf8("patchDataPointSpinner_X"));
        patchDataPointSpinner_X->setGeometry(QRect(20, 90, 62, 22));
        patchDataPointSpinner_X->setMinimum(-99.000000000000000);
        patchDataPointSpinner_X->setSingleStep(0.200000000000000);
        patchDataPointSpinner_Y = new QDoubleSpinBox(tab);
        patchDataPointSpinner_Y->setObjectName(QString::fromUtf8("patchDataPointSpinner_Y"));
        patchDataPointSpinner_Y->setGeometry(QRect(110, 90, 62, 22));
        patchDataPointSpinner_Y->setMinimum(-99.000000000000000);
        patchDataPointSpinner_Y->setSingleStep(0.200000000000000);
        patchDataPointSpinner_Z = new QDoubleSpinBox(tab);
        patchDataPointSpinner_Z->setObjectName(QString::fromUtf8("patchDataPointSpinner_Z"));
        patchDataPointSpinner_Z->setGeometry(QRect(200, 90, 62, 22));
        patchDataPointSpinner_Z->setMinimum(-99.000000000000000);
        patchDataPointSpinner_Z->setSingleStep(0.200000000000000);
        patchIsoCurvesBox_V = new QCheckBox(tab);
        patchIsoCurvesBox_V->setObjectName(QString::fromUtf8("patchIsoCurvesBox_V"));
        patchIsoCurvesBox_V->setGeometry(QRect(10, 250, 221, 20));
        pInterp = new QCheckBox(tab);
        pInterp->setObjectName(QString::fromUtf8("pInterp"));
        pInterp->setGeometry(QRect(10, 210, 91, 17));
        pNoInterp = new QCheckBox(tab);
        pNoInterp->setObjectName(QString::fromUtf8("pNoInterp"));
        pNoInterp->setGeometry(QRect(10, 190, 111, 17));
        patchIsoCurvesBox_U = new QCheckBox(tab);
        patchIsoCurvesBox_U->setObjectName(QString::fromUtf8("patchIsoCurvesBox_U"));
        patchIsoCurvesBox_U->setGeometry(QRect(10, 230, 221, 20));
        patchDivPointSpinner_U = new QSpinBox(tab);
        patchDivPointSpinner_U->setObjectName(QString::fromUtf8("patchDivPointSpinner_U"));
        patchDivPointSpinner_U->setGeometry(QRect(30, 150, 42, 22));
        patchDivPointSpinner_U->setMinimum(1);
        patchDivPointSpinner_U->setMaximum(999);
        patchDivPointSpinner_U->setSingleStep(5);
        patchDivPointSpinner_U->setValue(100);
        patchDivPointSpinner_V = new QSpinBox(tab);
        patchDivPointSpinner_V->setObjectName(QString::fromUtf8("patchDivPointSpinner_V"));
        patchDivPointSpinner_V->setGeometry(QRect(130, 150, 42, 22));
        patchDivPointSpinner_V->setMinimum(1);
        patchDivPointSpinner_V->setMaximum(999);
        patchDivPointSpinner_V->setSingleStep(5);
        patchDivPointSpinner_V->setValue(100);
        label_22 = new QLabel(tab);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 130, 101, 16));
        label_23 = new QLabel(tab);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 150, 16, 16));
        label_24 = new QLabel(tab);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(110, 150, 16, 16));
        patchDataPointComboBox_col = new QComboBox(tab);
        patchDataPointComboBox_col->setObjectName(QString::fromUtf8("patchDataPointComboBox_col"));
        patchDataPointComboBox_col->setGeometry(QRect(150, 50, 121, 22));
        patchCountSpinner = new QSpinBox(tab);
        patchCountSpinner->setObjectName(QString::fromUtf8("patchCountSpinner"));
        patchCountSpinner->setGeometry(QRect(20, 310, 61, 22));
        patchCountSpinner->setMinimum(1);
        patchCountSpinner->setMaximum(99);
        label_26 = new QLabel(tab);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 290, 81, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        label_15 = new QLabel(SideWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 810, 131, 16));
        smoothingSpinBox = new QDoubleSpinBox(SideWidget);
        smoothingSpinBox->setObjectName(QString::fromUtf8("smoothingSpinBox"));
        smoothingSpinBox->setGeometry(QRect(110, 870, 170, 20));
        smoothingSpinBox->setDecimals(5);
        smoothingSpinBox->setMinimum(0.000100000000000);
        smoothingSpinBox->setMaximum(10000.000000000000000);
        smoothingSpinBox->setSingleStep(0.100000000000000);
        smoothingSpinBox->setValue(2.000000000000000);
        shadingSpinBox = new QDoubleSpinBox(SideWidget);
        shadingSpinBox->setObjectName(QString::fromUtf8("shadingSpinBox"));
        shadingSpinBox->setGeometry(QRect(110, 890, 171, 20));
        shadingSpinBox->setDecimals(5);
        shadingSpinBox->setMinimum(0.000100000000000);
        shadingSpinBox->setMaximum(10000.000000000000000);
        shadingSpinBox->setSingleStep(0.100000000000000);
        shadingSpinBox->setValue(1.000000000000000);
        showShader = new QCheckBox(SideWidget);
        showShader->setObjectName(QString::fromUtf8("showShader"));
        showShader->setGeometry(QRect(10, 830, 91, 17));
        label_16 = new QLabel(SideWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 850, 61, 20));
        scaleFactorSpinBox = new QDoubleSpinBox(SideWidget);
        scaleFactorSpinBox->setObjectName(QString::fromUtf8("scaleFactorSpinBox"));
        scaleFactorSpinBox->setGeometry(QRect(110, 850, 170, 20));
        scaleFactorSpinBox->setDecimals(5);
        scaleFactorSpinBox->setMinimum(0.000100000000000);
        scaleFactorSpinBox->setMaximum(10000.000000000000000);
        scaleFactorSpinBox->setSingleStep(0.100000000000000);
        scaleFactorSpinBox->setValue(4.000000000000000);
        label_17 = new QLabel(SideWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 870, 58, 20));
        shaderComboBox = new QComboBox(SideWidget);
        shaderComboBox->addItem(QString());
        shaderComboBox->addItem(QString());
        shaderComboBox->addItem(QString());
        shaderComboBox->addItem(QString());
        shaderComboBox->setObjectName(QString::fromUtf8("shaderComboBox"));
        shaderComboBox->setGeometry(QRect(110, 830, 131, 22));
        label_18 = new QLabel(SideWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 890, 58, 20));
        imageComboBox = new QComboBox(SideWidget);
        imageComboBox->addItem(QString());
        imageComboBox->addItem(QString());
        imageComboBox->addItem(QString());
        imageComboBox->addItem(QString());
        imageComboBox->addItem(QString());
        imageComboBox->addItem(QString());
        imageComboBox->addItem(QString());
        imageComboBox->setObjectName(QString::fromUtf8("imageComboBox"));
        imageComboBox->setGeometry(QRect(10, 240, 131, 22));
        label_11 = new QLabel(SideWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 220, 131, 16));
#if QT_CONFIG(shortcut)
        label->setBuddy(rotate_x_slider);
        label_2->setBuddy(rotate_y_slider);
        label_3->setBuddy(rotate_z_slider);
        label_4->setBuddy(zoom_factor_spin_box);
        label_5->setBuddy(trans_x_spin_box);
        label_6->setBuddy(trans_y_spin_box);
        label_7->setBuddy(trans_z_spin_box);
        label_16->setBuddy(zoom_factor_spin_box);
        label_17->setBuddy(zoom_factor_spin_box);
        label_18->setBuddy(zoom_factor_spin_box);
#endif // QT_CONFIG(shortcut)

        retranslateUi(SideWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SideWidget);
    } // setupUi

    void retranslateUi(QWidget *SideWidget)
    {
        SideWidget->setWindowTitle(QCoreApplication::translate("SideWidget", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SideWidget", "Transformations", nullptr));
        label->setText(QCoreApplication::translate("SideWidget", "Rotate around x", nullptr));
        label_2->setText(QCoreApplication::translate("SideWidget", "Rotate around y", nullptr));
        label_3->setText(QCoreApplication::translate("SideWidget", "Rotate around z", nullptr));
        label_4->setText(QCoreApplication::translate("SideWidget", "Zoom factor", nullptr));
#if QT_CONFIG(tooltip)
        zoom_factor_spin_box->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("SideWidget", "Translate along x", nullptr));
        label_6->setText(QCoreApplication::translate("SideWidget", "Translate along y", nullptr));
        label_7->setText(QCoreApplication::translate("SideWidget", "Translate along z", nullptr));
        model_combo_box->setItemText(0, QCoreApplication::translate("SideWidget", "angel", nullptr));
        model_combo_box->setItemText(1, QCoreApplication::translate("SideWidget", "bird", nullptr));
        model_combo_box->setItemText(2, QCoreApplication::translate("SideWidget", "cone", nullptr));
        model_combo_box->setItemText(3, QCoreApplication::translate("SideWidget", "cube", nullptr));
        model_combo_box->setItemText(4, QCoreApplication::translate("SideWidget", "icosahedron", nullptr));
        model_combo_box->setItemText(5, QCoreApplication::translate("SideWidget", "sphere", nullptr));
        model_combo_box->setItemText(6, QCoreApplication::translate("SideWidget", "star", nullptr));
        model_combo_box->setItemText(7, QCoreApplication::translate("SideWidget", "space_station", nullptr));

        label_8->setText(QCoreApplication::translate("SideWidget", "Parametric curve", nullptr));
        ps_combo_box->setItemText(0, QCoreApplication::translate("SideWidget", "Torus", nullptr));
        ps_combo_box->setItemText(1, QCoreApplication::translate("SideWidget", "Hyperboloid", nullptr));
        ps_combo_box->setItemText(2, QCoreApplication::translate("SideWidget", "Cylindrical helicoid", nullptr));
        ps_combo_box->setItemText(3, QCoreApplication::translate("SideWidget", "Alfred Grey", nullptr));
        ps_combo_box->setItemText(4, QCoreApplication::translate("SideWidget", "Klein Bottle", nullptr));

        pc_combo_box->setItemText(0, QCoreApplication::translate("SideWidget", "Spiral cone", nullptr));
        pc_combo_box->setItemText(1, QCoreApplication::translate("SideWidget", "Torus knot", nullptr));
        pc_combo_box->setItemText(2, QCoreApplication::translate("SideWidget", "Own parametric curve", nullptr));
        pc_combo_box->setItemText(3, QCoreApplication::translate("SideWidget", "Hipotrochoid", nullptr));
        pc_combo_box->setItemText(4, QCoreApplication::translate("SideWidget", "Vivianni curve", nullptr));
        pc_combo_box->setItemText(5, QCoreApplication::translate("SideWidget", "Archytas", nullptr));

        label_10->setText(QCoreApplication::translate("SideWidget", "Model", nullptr));
        label_9->setText(QCoreApplication::translate("SideWidget", "Parametric surface", nullptr));
        label_25->setText(QCoreApplication::translate("SideWidget", "Division points", nullptr));
        pcFirstDerivCheckBox->setText(QCoreApplication::translate("SideWidget", "1st deriv", nullptr));
        pcSecondDerivCheckBox->setText(QCoreApplication::translate("SideWidget", "2nd deriv", nullptr));
        sandboxCheckbox->setText(QCoreApplication::translate("SideWidget", "Auto-reload", nullptr));
        label_19->setText(QCoreApplication::translate("SideWidget", "Sandbox", nullptr));
        textureComboBox->setItemText(0, QCoreApplication::translate("SideWidget", "No texture", nullptr));
        textureComboBox->setItemText(1, QCoreApplication::translate("SideWidget", "Texture 0", nullptr));
        textureComboBox->setItemText(2, QCoreApplication::translate("SideWidget", "Texture 1", nullptr));
        textureComboBox->setItemText(3, QCoreApplication::translate("SideWidget", "Texture 2", nullptr));
        textureComboBox->setItemText(4, QCoreApplication::translate("SideWidget", "Texture 3", nullptr));
        textureComboBox->setItemText(5, QCoreApplication::translate("SideWidget", "Texture 4", nullptr));
        textureComboBox->setItemText(6, QCoreApplication::translate("SideWidget", "Texture 5", nullptr));
        textureComboBox->setItemText(7, QCoreApplication::translate("SideWidget", "Texture 6", nullptr));
        textureComboBox->setItemText(8, QCoreApplication::translate("SideWidget", "Texture 7", nullptr));
        textureComboBox->setItemText(9, QCoreApplication::translate("SideWidget", "Texture 8", nullptr));
        textureComboBox->setItemText(10, QCoreApplication::translate("SideWidget", "Texture 9", nullptr));

        label_20->setText(QCoreApplication::translate("SideWidget", "1st deriv scale", nullptr));
        label_21->setText(QCoreApplication::translate("SideWidget", "2nd deriv scale", nullptr));
        label_12->setText(QCoreApplication::translate("SideWidget", "Cyclic Curve", nullptr));
        cNoInterp->setText(QCoreApplication::translate("SideWidget", "Before interp", nullptr));
        cPolygon->setText(QCoreApplication::translate("SideWidget", "Polygon", nullptr));
        cyclicCoordIndexComboBox->setItemText(0, QCoreApplication::translate("SideWidget", "p1", nullptr));
        cyclicCoordIndexComboBox->setItemText(1, QCoreApplication::translate("SideWidget", "p2", nullptr));
        cyclicCoordIndexComboBox->setItemText(2, QCoreApplication::translate("SideWidget", "p3", nullptr));
        cyclicCoordIndexComboBox->setItemText(3, QCoreApplication::translate("SideWidget", "p4", nullptr));
        cyclicCoordIndexComboBox->setItemText(4, QCoreApplication::translate("SideWidget", "p5", nullptr));
        cyclicCoordIndexComboBox->setItemText(5, QCoreApplication::translate("SideWidget", "p6", nullptr));

        cSecondDeriv->setText(QCoreApplication::translate("SideWidget", "2nd deriv", nullptr));
        cInterp->setText(QCoreApplication::translate("SideWidget", "After interp", nullptr));
        cFirstDeriv->setText(QCoreApplication::translate("SideWidget", "1st deriv", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHomework), QCoreApplication::translate("SideWidget", "Homework", nullptr));
        label_13->setText(QCoreApplication::translate("SideWidget", "Arc", nullptr));
        aFirstDeriv->setText(QCoreApplication::translate("SideWidget", "First deriv", nullptr));
        aNoInterp->setText(QCoreApplication::translate("SideWidget", "No Interp", nullptr));
        aSecondDeriv->setText(QCoreApplication::translate("SideWidget", "Second deriv", nullptr));
        aPolygon->setText(QCoreApplication::translate("SideWidget", "Control polygon", nullptr));
        label_27->setText(QCoreApplication::translate("SideWidget", "Division points", nullptr));
        label_28->setText(QCoreApplication::translate("SideWidget", "Arc count", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabProject), QCoreApplication::translate("SideWidget", "Arc", nullptr));
        label_14->setText(QCoreApplication::translate("SideWidget", "Patch", nullptr));
        pData->setText(QCoreApplication::translate("SideWidget", "Control net", nullptr));
        patchIsoCurvesBox_V->setText(QCoreApplication::translate("SideWidget", "V-directional isoparametric curves", nullptr));
        pInterp->setText(QCoreApplication::translate("SideWidget", "Interpolated", nullptr));
        pNoInterp->setText(QCoreApplication::translate("SideWidget", "No Interpolation", nullptr));
        patchIsoCurvesBox_U->setText(QCoreApplication::translate("SideWidget", "U-directional isoparametric curves", nullptr));
        label_22->setText(QCoreApplication::translate("SideWidget", "Division points", nullptr));
        label_23->setText(QCoreApplication::translate("SideWidget", "U:", nullptr));
        label_24->setText(QCoreApplication::translate("SideWidget", "V:", nullptr));
        label_26->setText(QCoreApplication::translate("SideWidget", "Patch Size", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SideWidget", "Patch", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SideWidget", "Interactive", nullptr));
        label_15->setText(QCoreApplication::translate("SideWidget", "Shader", nullptr));
#if QT_CONFIG(tooltip)
        smoothingSpinBox->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        shadingSpinBox->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        showShader->setText(QCoreApplication::translate("SideWidget", "Show Shader", nullptr));
        label_16->setText(QCoreApplication::translate("SideWidget", "Scale factor", nullptr));
#if QT_CONFIG(tooltip)
        scaleFactorSpinBox->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_17->setText(QCoreApplication::translate("SideWidget", "Smoothing", nullptr));
        shaderComboBox->setItemText(0, QCoreApplication::translate("SideWidget", "Directional", nullptr));
        shaderComboBox->setItemText(1, QCoreApplication::translate("SideWidget", "Reflection lines", nullptr));
        shaderComboBox->setItemText(2, QCoreApplication::translate("SideWidget", "Toon", nullptr));
        shaderComboBox->setItemText(3, QCoreApplication::translate("SideWidget", "Two sided", nullptr));

        label_18->setText(QCoreApplication::translate("SideWidget", "Shading", nullptr));
        imageComboBox->setItemText(0, QCoreApplication::translate("SideWidget", "Parametric Curve", nullptr));
        imageComboBox->setItemText(1, QCoreApplication::translate("SideWidget", "Model", nullptr));
        imageComboBox->setItemText(2, QCoreApplication::translate("SideWidget", "Parametric Surface", nullptr));
        imageComboBox->setItemText(3, QCoreApplication::translate("SideWidget", "Cyclic Curve", nullptr));
        imageComboBox->setItemText(4, QCoreApplication::translate("SideWidget", "Spline Arc", nullptr));
        imageComboBox->setItemText(5, QCoreApplication::translate("SideWidget", "Spline Patch", nullptr));
        imageComboBox->setItemText(6, QCoreApplication::translate("SideWidget", "Sandbox", nullptr));

        label_11->setText(QCoreApplication::translate("SideWidget", "Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SideWidget: public Ui_SideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEWIDGET_H
