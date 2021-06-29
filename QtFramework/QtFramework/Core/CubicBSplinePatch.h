#ifndef CubicBSplinePatch_H
#define CubicBSplinePatch_H
#include "../Core/TensorProductSurfaces3.h"

using namespace cagd;

class CubicBSplinePatch : public TensorProductSurface3
{
public:
    CubicBSplinePatch() : TensorProductSurface3(0.0, 1.0, 0.0, 1.0, 4, 4)
    {}

    virtual GLboolean UBlendingFunctionValues(GLdouble u_knot, RowMatrix<GLdouble> &blending_values) const override;
    virtual GLboolean VBlendingFunctionValues(GLdouble v_knot, RowMatrix<GLdouble> &blending_values) const override;
    virtual GLboolean CalculatePartialDerivatives(GLuint maximum_order_of_partial_derivatives, GLdouble u, GLdouble v, PartialDerivatives &pd) const override;

    GLdouble F00(double t) const;
    GLdouble F10(double t) const;
    GLdouble F20(double t) const;
    GLdouble F30(double t) const;

    GLdouble F01(double t) const;
    GLdouble F11(double t) const;
    GLdouble F21(double t) const;
    GLdouble F31(double t) const;
};
#endif
