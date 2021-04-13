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
    QCheckBox *cNoInterp;
    QLabel *label_8;
    QCheckBox *cSecondDeriv;
    QComboBox *ps_combo_box;
    QLabel *label_12;
    QCheckBox *cPolygon;
    QComboBox *pc_combo_box;
    QLabel *label_10;
    QCheckBox *cFirstDeriv;
    QCheckBox *cInterp;
    QLabel *label_9;
    QSpinBox *pcDivisionPointsSpinBox;
    QLabel *label_25;
    QCheckBox *pcFirstDerivCheckBox;
    QCheckBox *pcSecondDerivCheckBox;
    QCheckBox *sandboxCheckbox;
    QLabel *label_19;
    QComboBox *textureComboBox;
    QWidget *tabProject;
    QLabel *label_13;
    QCheckBox *aFirstDeriv;
    QCheckBox *aNoInterp;
    QCheckBox *aSecondDeriv;
    QCheckBox *aPolygon;
    QLabel *label_30;
    QDoubleSpinBox *arcSpinbox1;
    QDoubleSpinBox *arcSpinbox2;
    QDoubleSpinBox *arcSpinbox3;
    QDoubleSpinBox *arcSpinbox4;
    QDoubleSpinBox *arcSpinbox3_2;
    QDoubleSpinBox *arcSpinbox2_2;
    QDoubleSpinBox *arcSpinbox4_2;
    QDoubleSpinBox *arcSpinbox1_2;
    QDoubleSpinBox *arcSpinbox3_3;
    QDoubleSpinBox *arcSpinbox2_3;
    QDoubleSpinBox *arcSpinbox4_3;
    QDoubleSpinBox *arcSpinbox1_3;
    QWidget *tab;
    QCheckBox *pInterp;
    QLabel *label_14;
    QCheckBox *pData;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *pNoInterp;
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
        SideWidget->resize(286, 926);
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
        model_combo_box->setGeometry(QRect(130, 200, 131, 22));
        cNoInterp = new QCheckBox(tabHomework);
        cNoInterp->setObjectName(QString::fromUtf8("cNoInterp"));
        cNoInterp->setGeometry(QRect(10, 280, 81, 17));
        label_8 = new QLabel(tabHomework);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 10, 131, 16));
        cSecondDeriv = new QCheckBox(tabHomework);
        cSecondDeriv->setObjectName(QString::fromUtf8("cSecondDeriv"));
        cSecondDeriv->setGeometry(QRect(10, 320, 70, 17));
        ps_combo_box = new QComboBox(tabHomework);
        ps_combo_box->addItem(QString());
        ps_combo_box->addItem(QString());
        ps_combo_box->addItem(QString());
        ps_combo_box->addItem(QString());
        ps_combo_box->addItem(QString());
        ps_combo_box->setObjectName(QString::fromUtf8("ps_combo_box"));
        ps_combo_box->setGeometry(QRect(130, 120, 131, 22));
        label_12 = new QLabel(tabHomework);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 240, 131, 16));
        cPolygon = new QCheckBox(tabHomework);
        cPolygon->setObjectName(QString::fromUtf8("cPolygon"));
        cPolygon->setGeometry(QRect(10, 260, 70, 17));
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
        label_10->setGeometry(QRect(10, 200, 131, 16));
        cFirstDeriv = new QCheckBox(tabHomework);
        cFirstDeriv->setObjectName(QString::fromUtf8("cFirstDeriv"));
        cFirstDeriv->setGeometry(QRect(10, 300, 70, 17));
        cInterp = new QCheckBox(tabHomework);
        cInterp->setObjectName(QString::fromUtf8("cInterp"));
        cInterp->setGeometry(QRect(10, 340, 81, 17));
        label_9 = new QLabel(tabHomework);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 120, 131, 16));
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
        sandboxCheckbox->setGeometry(QRect(10, 400, 91, 20));
        label_19 = new QLabel(tabHomework);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 380, 49, 16));
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
        textureComboBox->setGeometry(QRect(130, 160, 131, 22));
        tabWidget->addTab(tabHomework, QString());
        tabProject = new QWidget();
        tabProject->setObjectName(QString::fromUtf8("tabProject"));
        label_13 = new QLabel(tabProject);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 0, 131, 16));
        aFirstDeriv = new QCheckBox(tabProject);
        aFirstDeriv->setObjectName(QString::fromUtf8("aFirstDeriv"));
        aFirstDeriv->setGeometry(QRect(10, 40, 81, 17));
        aNoInterp = new QCheckBox(tabProject);
        aNoInterp->setObjectName(QString::fromUtf8("aNoInterp"));
        aNoInterp->setGeometry(QRect(10, 80, 81, 17));
        aSecondDeriv = new QCheckBox(tabProject);
        aSecondDeriv->setObjectName(QString::fromUtf8("aSecondDeriv"));
        aSecondDeriv->setGeometry(QRect(10, 60, 81, 17));
        aPolygon = new QCheckBox(tabProject);
        aPolygon->setObjectName(QString::fromUtf8("aPolygon"));
        aPolygon->setGeometry(QRect(10, 20, 70, 17));
        label_30 = new QLabel(tabProject);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(150, 0, 71, 16));
        arcSpinbox1 = new QDoubleSpinBox(tabProject);
        arcSpinbox1->setObjectName(QString::fromUtf8("arcSpinbox1"));
        arcSpinbox1->setGeometry(QRect(100, 20, 51, 22));
        arcSpinbox2 = new QDoubleSpinBox(tabProject);
        arcSpinbox2->setObjectName(QString::fromUtf8("arcSpinbox2"));
        arcSpinbox2->setGeometry(QRect(100, 40, 51, 22));
        arcSpinbox3 = new QDoubleSpinBox(tabProject);
        arcSpinbox3->setObjectName(QString::fromUtf8("arcSpinbox3"));
        arcSpinbox3->setGeometry(QRect(100, 60, 51, 22));
        arcSpinbox4 = new QDoubleSpinBox(tabProject);
        arcSpinbox4->setObjectName(QString::fromUtf8("arcSpinbox4"));
        arcSpinbox4->setGeometry(QRect(100, 80, 51, 22));
        arcSpinbox4->setValue(2.000000000000000);
        arcSpinbox3_2 = new QDoubleSpinBox(tabProject);
        arcSpinbox3_2->setObjectName(QString::fromUtf8("arcSpinbox3_2"));
        arcSpinbox3_2->setGeometry(QRect(160, 60, 51, 22));
        arcSpinbox3_2->setValue(1.000000000000000);
        arcSpinbox2_2 = new QDoubleSpinBox(tabProject);
        arcSpinbox2_2->setObjectName(QString::fromUtf8("arcSpinbox2_2"));
        arcSpinbox2_2->setGeometry(QRect(160, 40, 51, 22));
        arcSpinbox2_2->setValue(1.000000000000000);
        arcSpinbox4_2 = new QDoubleSpinBox(tabProject);
        arcSpinbox4_2->setObjectName(QString::fromUtf8("arcSpinbox4_2"));
        arcSpinbox4_2->setGeometry(QRect(160, 80, 51, 22));
        arcSpinbox4_2->setValue(1.000000000000000);
        arcSpinbox1_2 = new QDoubleSpinBox(tabProject);
        arcSpinbox1_2->setObjectName(QString::fromUtf8("arcSpinbox1_2"));
        arcSpinbox1_2->setGeometry(QRect(160, 20, 51, 22));
        arcSpinbox3_3 = new QDoubleSpinBox(tabProject);
        arcSpinbox3_3->setObjectName(QString::fromUtf8("arcSpinbox3_3"));
        arcSpinbox3_3->setGeometry(QRect(220, 60, 51, 22));
        arcSpinbox3_3->setValue(1.000000000000000);
        arcSpinbox2_3 = new QDoubleSpinBox(tabProject);
        arcSpinbox2_3->setObjectName(QString::fromUtf8("arcSpinbox2_3"));
        arcSpinbox2_3->setGeometry(QRect(220, 40, 51, 22));
        arcSpinbox4_3 = new QDoubleSpinBox(tabProject);
        arcSpinbox4_3->setObjectName(QString::fromUtf8("arcSpinbox4_3"));
        arcSpinbox4_3->setGeometry(QRect(220, 80, 51, 22));
        arcSpinbox4_3->setValue(1.000000000000000);
        arcSpinbox1_3 = new QDoubleSpinBox(tabProject);
        arcSpinbox1_3->setObjectName(QString::fromUtf8("arcSpinbox1_3"));
        arcSpinbox1_3->setGeometry(QRect(220, 20, 51, 22));
        arcSpinbox1_3->setValue(1.000000000000000);
        tabWidget->addTab(tabProject, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pInterp = new QCheckBox(tab);
        pInterp->setObjectName(QString::fromUtf8("pInterp"));
        pInterp->setGeometry(QRect(120, 40, 81, 17));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 0, 131, 16));
        pData = new QCheckBox(tab);
        pData->setObjectName(QString::fromUtf8("pData"));
        pData->setGeometry(QRect(10, 20, 70, 17));
        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 40, 70, 17));
        checkBox_2 = new QCheckBox(tab);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 60, 91, 17));
        pNoInterp = new QCheckBox(tab);
        pNoInterp->setObjectName(QString::fromUtf8("pNoInterp"));
        pNoInterp->setGeometry(QRect(120, 20, 81, 17));
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

        tabWidget->setCurrentIndex(0);


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

        cNoInterp->setText(QCoreApplication::translate("SideWidget", "Before interp", nullptr));
        label_8->setText(QCoreApplication::translate("SideWidget", "Parametric curve", nullptr));
        cSecondDeriv->setText(QCoreApplication::translate("SideWidget", "2nd deriv", nullptr));
        ps_combo_box->setItemText(0, QCoreApplication::translate("SideWidget", "Torus", nullptr));
        ps_combo_box->setItemText(1, QCoreApplication::translate("SideWidget", "Hyperboloid", nullptr));
        ps_combo_box->setItemText(2, QCoreApplication::translate("SideWidget", "Cylindrical helicoid", nullptr));
        ps_combo_box->setItemText(3, QCoreApplication::translate("SideWidget", "Alfred Grey", nullptr));
        ps_combo_box->setItemText(4, QCoreApplication::translate("SideWidget", "Klein Bottle", nullptr));

        label_12->setText(QCoreApplication::translate("SideWidget", "Cyclic Curve", nullptr));
        cPolygon->setText(QCoreApplication::translate("SideWidget", "Polygon", nullptr));
        pc_combo_box->setItemText(0, QCoreApplication::translate("SideWidget", "Spiral cone", nullptr));
        pc_combo_box->setItemText(1, QCoreApplication::translate("SideWidget", "Torus knot", nullptr));
        pc_combo_box->setItemText(2, QCoreApplication::translate("SideWidget", "Own parametric curve", nullptr));
        pc_combo_box->setItemText(3, QCoreApplication::translate("SideWidget", "Hipotrochoid", nullptr));
        pc_combo_box->setItemText(4, QCoreApplication::translate("SideWidget", "Vivianni curve", nullptr));
        pc_combo_box->setItemText(5, QCoreApplication::translate("SideWidget", "Archytas", nullptr));

        label_10->setText(QCoreApplication::translate("SideWidget", "Model", nullptr));
        cFirstDeriv->setText(QCoreApplication::translate("SideWidget", "1st deriv", nullptr));
        cInterp->setText(QCoreApplication::translate("SideWidget", "After interp", nullptr));
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

        tabWidget->setTabText(tabWidget->indexOf(tabHomework), QCoreApplication::translate("SideWidget", "Homework", nullptr));
        label_13->setText(QCoreApplication::translate("SideWidget", "Arc", nullptr));
        aFirstDeriv->setText(QCoreApplication::translate("SideWidget", "First deriv", nullptr));
        aNoInterp->setText(QCoreApplication::translate("SideWidget", "No Interp", nullptr));
        aSecondDeriv->setText(QCoreApplication::translate("SideWidget", "Second deriv", nullptr));
        aPolygon->setText(QCoreApplication::translate("SideWidget", "Polygon", nullptr));
        label_30->setText(QCoreApplication::translate("SideWidget", "Vector values", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabProject), QCoreApplication::translate("SideWidget", "Arc", nullptr));
        pInterp->setText(QCoreApplication::translate("SideWidget", "Interp", nullptr));
        label_14->setText(QCoreApplication::translate("SideWidget", "Patch", nullptr));
        pData->setText(QCoreApplication::translate("SideWidget", "Datapoints", nullptr));
        checkBox->setText(QCoreApplication::translate("SideWidget", "First Deriv", nullptr));
        checkBox_2->setText(QCoreApplication::translate("SideWidget", "Normal vectors", nullptr));
        pNoInterp->setText(QCoreApplication::translate("SideWidget", "No Interp", nullptr));
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
        imageComboBox->setItemText(4, QCoreApplication::translate("SideWidget", "Biquartic Arc", nullptr));
        imageComboBox->setItemText(5, QCoreApplication::translate("SideWidget", "Biquartic Patch", nullptr));
        imageComboBox->setItemText(6, QCoreApplication::translate("SideWidget", "Sandbox", nullptr));

        label_11->setText(QCoreApplication::translate("SideWidget", "Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SideWidget: public Ui_SideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEWIDGET_H
