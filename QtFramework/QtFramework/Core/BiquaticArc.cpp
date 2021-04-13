#include "BiquarticArc.h"
#include <cmath>

using namespace cagd;
using namespace std;

GLdouble F20(GLdouble t)
{
    return 4 * pow(t, 3) * (1 - t) + 3 * pow(t, 2) * pow((1 - t), 2);
}

GLdouble F30(GLdouble t)
{
    return pow(t, 4);
}

GLdouble F00(GLdouble t)
{
    return F30(1 - t);
}

GLdouble F10(GLdouble t)
{
    return F20(1 - t);
}

// first order derivatives

GLdouble F21(GLdouble t)
{
    return -4.0 * pow(t, 3.0) - 6.0 * pow(t, 2.0) + 6.0 * t;
}

GLdouble F31(GLdouble t)
{
    return 4 * pow(t, 3);
}

GLdouble F01(GLdouble t)
{
    return -F31(1 - t);
}

GLdouble F11(GLdouble t)
{
    return -F21(1 - t);
}

// second order derivatives

GLdouble F22(GLdouble t)
{
    return -12.0 * pow(t, 2.0) - 12.0 * t + 6.0;
}

GLdouble F32(GLdouble t)
{
    return 12.0 * pow(t, 2);
}

GLdouble F02(GLdouble t)
{
    return F32(1 - t);
}

GLdouble F12(GLdouble t)
{
    return F22(1 - t);
}

GLboolean BiquarticArc::BlendingFunctionValues(GLdouble u, RowMatrix<GLdouble> &values) const
{
    values.ResizeColumns(4);

    values[0] = F00(u);
    values[1] = F10(u);
    values[2] = F20(u);
    values[3] = F30(u);

    return true;
}

GLboolean BiquarticArc::CalculateDerivatives(GLuint max_order_of_derivatives,
                                             GLdouble u,
                                             Derivatives &d) const
{
    if (u < _u_min || u > _u_max || max_order_of_derivatives > 2) {
        return false;
    }
    d.ResizeRows(max_order_of_derivatives + 1);
    d.LoadNullVectors();

    RowMatrix<GLdouble> funcValues;
    BlendingFunctionValues(u, funcValues);
    for (auto i = 0; i < 4; i++) {
        d[0] += _data[i] * funcValues[i];
    }

    d[1] += _data[0] * F01(u);
    d[1] += _data[1] * F11(u);
    d[1] += _data[2] * F21(u);
    d[1] += _data[3] * F31(u);

    if (max_order_of_derivatives == 2) {
        d[2] += _data[0] * F02(u);
        d[2] += _data[1] * F12(u);
        d[2] += _data[2] * F22(u);
        d[2] += _data[3] * F32(u);
    }

    return true;
}

GLboolean BiquarticArc::UpdateDataForInterpolation(
    const ColumnMatrix<GLdouble> &knot_vector,
    const ColumnMatrix<DCoordinate3> &data_points_to_interpolate)
{
    return true;
}
