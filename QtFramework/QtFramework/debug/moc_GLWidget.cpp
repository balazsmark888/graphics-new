/****************************************************************************
** Meta object code from reading C++ file 'GLWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../GUI/GLWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cagd__GLWidget_t {
    const uint offsetsAndSize[100];
    char stringdata0[968];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_cagd__GLWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_cagd__GLWidget_t qt_meta_stringdata_cagd__GLWidget = {
    {
QT_MOC_LITERAL(0, 14), // "cagd::GLWidget"
QT_MOC_LITERAL(15, 11), // "set_angle_x"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 5), // "value"
QT_MOC_LITERAL(34, 11), // "set_angle_y"
QT_MOC_LITERAL(46, 11), // "set_angle_z"
QT_MOC_LITERAL(58, 15), // "set_zoom_factor"
QT_MOC_LITERAL(74, 11), // "set_trans_x"
QT_MOC_LITERAL(86, 11), // "set_trans_y"
QT_MOC_LITERAL(98, 11), // "set_trans_z"
QT_MOC_LITERAL(110, 24), // "set_selected_curve_index"
QT_MOC_LITERAL(135, 19), // "set_division_points"
QT_MOC_LITERAL(155, 20), // "set_first_derivative"
QT_MOC_LITERAL(176, 21), // "set_second_derivative"
QT_MOC_LITERAL(198, 26), // "set_selected_surface_index"
QT_MOC_LITERAL(225, 24), // "set_selected_model_index"
QT_MOC_LITERAL(250, 15), // "set_image_index"
QT_MOC_LITERAL(266, 32), // "set_isCyclicCurveNoInterpolation"
QT_MOC_LITERAL(299, 19), // "set_isCyclicPolygon"
QT_MOC_LITERAL(319, 22), // "set_isCyclicFirstDeriv"
QT_MOC_LITERAL(342, 23), // "set_isCyclicSecondDeriv"
QT_MOC_LITERAL(366, 24), // "set_isCyclicInterpolated"
QT_MOC_LITERAL(391, 22), // "set_isBiquarticPolygon"
QT_MOC_LITERAL(414, 25), // "set_isBiquarticFirstDeriv"
QT_MOC_LITERAL(440, 26), // "set_isBiquarticSecondDeriv"
QT_MOC_LITERAL(467, 33), // "set_isBiquarticArcNoInterpola..."
QT_MOC_LITERAL(501, 19), // "set_isBiquarticData"
QT_MOC_LITERAL(521, 30), // "set_isBiquarticNoInterpolation"
QT_MOC_LITERAL(552, 27), // "set_isBiquarticInterpolated"
QT_MOC_LITERAL(580, 16), // "set_shader_index"
QT_MOC_LITERAL(597, 15), // "set_show_shader"
QT_MOC_LITERAL(613, 13), // "set_smoothing"
QT_MOC_LITERAL(627, 15), // "set_scaleFactor"
QT_MOC_LITERAL(643, 11), // "set_shading"
QT_MOC_LITERAL(655, 21), // "set_ArcVectorValue1_1"
QT_MOC_LITERAL(677, 21), // "set_ArcVectorValue1_2"
QT_MOC_LITERAL(699, 21), // "set_ArcVectorValue1_3"
QT_MOC_LITERAL(721, 21), // "set_ArcVectorValue2_1"
QT_MOC_LITERAL(743, 21), // "set_ArcVectorValue2_2"
QT_MOC_LITERAL(765, 21), // "set_ArcVectorValue2_3"
QT_MOC_LITERAL(787, 21), // "set_ArcVectorValue3_1"
QT_MOC_LITERAL(809, 21), // "set_ArcVectorValue3_2"
QT_MOC_LITERAL(831, 21), // "set_ArcVectorValue3_3"
QT_MOC_LITERAL(853, 21), // "set_ArcVectorValue4_1"
QT_MOC_LITERAL(875, 21), // "set_ArcVectorValue4_2"
QT_MOC_LITERAL(897, 21), // "set_ArcVectorValue4_3"
QT_MOC_LITERAL(919, 17), // "set_reloadSandbox"
QT_MOC_LITERAL(937, 8), // "_animate"
QT_MOC_LITERAL(946, 15), // "setTextureIndex"
QT_MOC_LITERAL(962, 5) // "index"

    },
    "cagd::GLWidget\0set_angle_x\0\0value\0"
    "set_angle_y\0set_angle_z\0set_zoom_factor\0"
    "set_trans_x\0set_trans_y\0set_trans_z\0"
    "set_selected_curve_index\0set_division_points\0"
    "set_first_derivative\0set_second_derivative\0"
    "set_selected_surface_index\0"
    "set_selected_model_index\0set_image_index\0"
    "set_isCyclicCurveNoInterpolation\0"
    "set_isCyclicPolygon\0set_isCyclicFirstDeriv\0"
    "set_isCyclicSecondDeriv\0"
    "set_isCyclicInterpolated\0"
    "set_isBiquarticPolygon\0set_isBiquarticFirstDeriv\0"
    "set_isBiquarticSecondDeriv\0"
    "set_isBiquarticArcNoInterpolation\0"
    "set_isBiquarticData\0set_isBiquarticNoInterpolation\0"
    "set_isBiquarticInterpolated\0"
    "set_shader_index\0set_show_shader\0"
    "set_smoothing\0set_scaleFactor\0set_shading\0"
    "set_ArcVectorValue1_1\0set_ArcVectorValue1_2\0"
    "set_ArcVectorValue1_3\0set_ArcVectorValue2_1\0"
    "set_ArcVectorValue2_2\0set_ArcVectorValue2_3\0"
    "set_ArcVectorValue3_1\0set_ArcVectorValue3_2\0"
    "set_ArcVectorValue3_3\0set_ArcVectorValue4_1\0"
    "set_ArcVectorValue4_2\0set_ArcVectorValue4_3\0"
    "set_reloadSandbox\0_animate\0setTextureIndex\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cagd__GLWidget[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  290,    2, 0x0a,    0 /* Public */,
       4,    1,  293,    2, 0x0a,    2 /* Public */,
       5,    1,  296,    2, 0x0a,    4 /* Public */,
       6,    1,  299,    2, 0x0a,    6 /* Public */,
       7,    1,  302,    2, 0x0a,    8 /* Public */,
       8,    1,  305,    2, 0x0a,   10 /* Public */,
       9,    1,  308,    2, 0x0a,   12 /* Public */,
      10,    1,  311,    2, 0x0a,   14 /* Public */,
      11,    1,  314,    2, 0x0a,   16 /* Public */,
      12,    1,  317,    2, 0x0a,   18 /* Public */,
      13,    1,  320,    2, 0x0a,   20 /* Public */,
      14,    1,  323,    2, 0x0a,   22 /* Public */,
      15,    1,  326,    2, 0x0a,   24 /* Public */,
      16,    1,  329,    2, 0x0a,   26 /* Public */,
      17,    1,  332,    2, 0x0a,   28 /* Public */,
      18,    1,  335,    2, 0x0a,   30 /* Public */,
      19,    1,  338,    2, 0x0a,   32 /* Public */,
      20,    1,  341,    2, 0x0a,   34 /* Public */,
      21,    1,  344,    2, 0x0a,   36 /* Public */,
      22,    1,  347,    2, 0x0a,   38 /* Public */,
      23,    1,  350,    2, 0x0a,   40 /* Public */,
      24,    1,  353,    2, 0x0a,   42 /* Public */,
      25,    1,  356,    2, 0x0a,   44 /* Public */,
      26,    1,  359,    2, 0x0a,   46 /* Public */,
      27,    1,  362,    2, 0x0a,   48 /* Public */,
      28,    1,  365,    2, 0x0a,   50 /* Public */,
      29,    1,  368,    2, 0x0a,   52 /* Public */,
      30,    1,  371,    2, 0x0a,   54 /* Public */,
      31,    1,  374,    2, 0x0a,   56 /* Public */,
      32,    1,  377,    2, 0x0a,   58 /* Public */,
      33,    1,  380,    2, 0x0a,   60 /* Public */,
      34,    1,  383,    2, 0x0a,   62 /* Public */,
      35,    1,  386,    2, 0x0a,   64 /* Public */,
      36,    1,  389,    2, 0x0a,   66 /* Public */,
      37,    1,  392,    2, 0x0a,   68 /* Public */,
      38,    1,  395,    2, 0x0a,   70 /* Public */,
      39,    1,  398,    2, 0x0a,   72 /* Public */,
      40,    1,  401,    2, 0x0a,   74 /* Public */,
      41,    1,  404,    2, 0x0a,   76 /* Public */,
      42,    1,  407,    2, 0x0a,   78 /* Public */,
      43,    1,  410,    2, 0x0a,   80 /* Public */,
      44,    1,  413,    2, 0x0a,   82 /* Public */,
      45,    1,  416,    2, 0x0a,   84 /* Public */,
      46,    1,  419,    2, 0x0a,   86 /* Public */,
      47,    0,  422,    2, 0x0a,   88 /* Public */,
      48,    1,  423,    2, 0x0a,   89 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   49,

       0        // eod
};

void cagd::GLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GLWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->set_angle_x((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->set_angle_y((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->set_angle_z((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->set_zoom_factor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->set_trans_x((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->set_trans_y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->set_trans_z((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->set_selected_curve_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->set_division_points((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->set_first_derivative((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->set_second_derivative((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->set_selected_surface_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->set_selected_model_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->set_image_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->set_isCyclicCurveNoInterpolation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->set_isCyclicPolygon((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->set_isCyclicFirstDeriv((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->set_isCyclicSecondDeriv((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->set_isCyclicInterpolated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->set_isBiquarticPolygon((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->set_isBiquarticFirstDeriv((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->set_isBiquarticSecondDeriv((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->set_isBiquarticArcNoInterpolation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->set_isBiquarticData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->set_isBiquarticNoInterpolation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->set_isBiquarticInterpolated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->set_shader_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->set_show_shader((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->set_smoothing((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: _t->set_scaleFactor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 30: _t->set_shading((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->set_ArcVectorValue1_1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 32: _t->set_ArcVectorValue1_2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 33: _t->set_ArcVectorValue1_3((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 34: _t->set_ArcVectorValue2_1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 35: _t->set_ArcVectorValue2_2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 36: _t->set_ArcVectorValue2_3((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 37: _t->set_ArcVectorValue3_1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 38: _t->set_ArcVectorValue3_2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 39: _t->set_ArcVectorValue3_3((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 40: _t->set_ArcVectorValue4_1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 41: _t->set_ArcVectorValue4_2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 42: _t->set_ArcVectorValue4_3((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 43: _t->set_reloadSandbox((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: _t->_animate(); break;
        case 45: _t->setTextureIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject cagd::GLWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_meta_stringdata_cagd__GLWidget.offsetsAndSize,
    qt_meta_data_cagd__GLWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_cagd__GLWidget_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *cagd::GLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cagd::GLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cagd__GLWidget.stringdata0))
        return static_cast<void*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int cagd::GLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 46)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 46;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
