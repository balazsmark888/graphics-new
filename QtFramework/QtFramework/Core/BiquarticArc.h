#ifndef BIQUARTICARC_H
#define BIQUARTICARC_H
#include "../Core/LinearCombination3.h"
#include "../Core/Matrices.h"

using namespace cagd;
using namespace std;
class BiquarticArc : public LinearCombination3
{
private:
public:
    BiquarticArc()
        : LinearCombination3(0, 1.0, 4)
    {}
    BiquarticArc(const BiquarticArc &other)
        : LinearCombination3(other)
    {}
    virtual GLboolean BlendingFunctionValues(GLdouble u, RowMatrix<GLdouble> &values) const;
    virtual GLboolean CalculateDerivatives(GLuint max_order_of_derivatives,
                                           GLdouble u,
                                           Derivatives &d) const;
    virtual GLboolean UpdateDataForInterpolation(
        const ColumnMatrix<GLdouble> &knot_vector,
        const ColumnMatrix<DCoordinate3> &data_points_to_interpolate);
};
#endif // CYCLICCURVES3_H
