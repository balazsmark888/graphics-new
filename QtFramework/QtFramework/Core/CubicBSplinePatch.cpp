#include "CubicBSplinePatch.h"

GLboolean CubicBSplinePatch::UBlendingFunctionValues(GLdouble u_knot,
                                                  RowMatrix<GLdouble> &blending_values) const
{
    if (u_knot < this->_u_min || u_knot > this->_u_max) {
        return static_cast<GLboolean>(false);
    }

    blending_values.ResizeColumns(4);
    blending_values[0] = this->F00(u_knot);
    blending_values[1] = this->F10(u_knot);
    blending_values[2] = this->F20(u_knot);
    blending_values[3] = this->F30(u_knot);

    return static_cast<GLboolean>(true);
}

GLboolean CubicBSplinePatch::VBlendingFunctionValues(GLdouble v_knot,
                                                  RowMatrix<GLdouble> &blending_values) const
{
    return this->UBlendingFunctionValues(v_knot, blending_values);
}

GLboolean CubicBSplinePatch::CalculatePartialDerivatives(GLuint maximum_order_of_partial_derivatives,
                                                      GLdouble u,
                                                      GLdouble v,
                                                      PartialDerivatives &pd) const
{
    if (u < this->_u_min || u > this->_u_max || v < this->_v_min || v > this->_v_max || maximum_order_of_partial_derivatives > 1) {
        return static_cast<GLboolean>(false);
    }

    RowMatrix<GLdouble> u_blending_values(4),d1_u_blending_values(4);
    UBlendingFunctionValues(u,u_blending_values);
    d1_u_blending_values[0] = F01(u);
    d1_u_blending_values[1] = F11(u);
    d1_u_blending_values[2] = F21(u);
    d1_u_blending_values[3] = F31(u);

    RowMatrix<GLdouble> v_blending_values(4),d1_v_blending_values(4);
    VBlendingFunctionValues(v,v_blending_values);
    d1_v_blending_values[0] = F01(v);
    d1_v_blending_values[1] = F11(v);
    d1_v_blending_values[2] = F21(v);
    d1_v_blending_values[3] = F31(v);

    pd.ResizeRows(2);
    pd.LoadNullVectors();
    for (GLuint row=0;row < 4;++row) {
        DCoordinate3 aux_d0_v,aux_d1_v;
        for (GLuint column=0;column< 4;++column) {
          aux_d0_v += _data(row,column) * v_blending_values(column);
          aux_d1_v += _data(row,column) * d1_v_blending_values(column);
        }
        pd(0,0) += aux_d0_v * u_blending_values(row);
        pd(1,0) += aux_d0_v * d1_u_blending_values(row);
        pd(1,1) += aux_d1_v * u_blending_values(row);
    }

    return true;
}

GLdouble CubicBSplinePatch::F00(double t) const
{
    return pow(1 - t, 3) / 6;
}

GLdouble CubicBSplinePatch::F10(double t) const
{
   return (3 * t * pow(1 - t, 2) + 3 * (1 - t) + 1) / 6;
}

GLdouble CubicBSplinePatch::F20(double t) const
{
    return (3 * t * t * (1 - t) + 3 * t + 1) / 6;
}

GLdouble CubicBSplinePatch::F30(double t) const
{
   return pow(t, 3) / 6;
}

GLdouble CubicBSplinePatch::F01(double t) const
{
    return -pow(1 - t, 2) / 2;
}

GLdouble CubicBSplinePatch::F11(double t) const
{
    return t * (3 * t - 4) / 2;
}

GLdouble CubicBSplinePatch::F21(double t) const
{
    return -(3 * pow(t, 2) - 2 * t - 1) / 2;
}

GLdouble CubicBSplinePatch::F31(double t) const
{
    return pow(t, 2) / 2;
}
