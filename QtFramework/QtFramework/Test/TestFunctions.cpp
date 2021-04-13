#include <cmath>
#include "TestFunctions.h"
#include "../Core/Constants.h"

using namespace cagd;
using namespace std;

GLdouble spiral_on_cone::u_min = -TWO_PI;
GLdouble spiral_on_cone::u_max = +TWO_PI;


DCoordinate3 spiral_on_cone::d0(GLdouble u)
{
	return DCoordinate3(u * cos(u), u * sin(u), u);
}

DCoordinate3 spiral_on_cone::d1(GLdouble u)
{
	GLdouble c = cos(u), s = sin(u);
	return DCoordinate3(c - u * s, s + u * c, 1.0);
}

DCoordinate3 spiral_on_cone::d2(GLdouble u)
{
	GLdouble c = cos(u), s = sin(u);
	return DCoordinate3(-2.0 * s - u * c, 2.0 * c - u * s, 0);
}

GLdouble torus_knot::u_min = 0;
GLdouble torus_knot::u_max = 3 * TWO_PI;

DCoordinate3 torus_knot::d0(GLdouble u)
{
	GLdouble x = (2 + cos(2 * u / 3)) * cos(u);
	GLdouble y = (2 + cos(2 * u / 3)) * sin(u);
	GLdouble z = sin(2 * u / 3);
	return DCoordinate3(x, y, z);
}

DCoordinate3 torus_knot::d1(GLdouble u)
{
	GLdouble x = -(cos(2 * u / 3) + 2) * sin(u) - (2 * sin(2 * u / 3) * cos(u)) / 3;
	GLdouble y = (cos(2 * u / 3) + 2) * cos(u) - (2 * sin(2 * u / 3) * sin(u)) / 3;
	GLdouble z = 2 * cos(2 * u / 3) / 3;
	return DCoordinate3(x, y, z);
}

DCoordinate3 torus_knot::d2(GLdouble u)
{
	GLdouble x = (12 * sin(2 * u / 3) * sin(u) + (-13 * cos(2 * u / 3) - 18) * cos(u)) / 9;
	GLdouble y = -((13 * cos(2 * u / 3) + 18) * sin(u) + 12 * sin(2 * u / 3) * cos(u)) / 9;
	GLdouble z = -(4 * sin(2 * u / 3) / 9);
	return DCoordinate3(x, y, z);
}

GLdouble parametric_curve_1::u_min = PI / 2;
GLdouble parametric_curve_1::u_max = 3 * PI / 2;

DCoordinate3 parametric_curve_1::d0(GLdouble u)
{
	GLdouble x = 2 * sin(u);
	GLdouble y = cos(4 * u);
	GLdouble z = tan(u);
	return DCoordinate3(x, y, z);
}

DCoordinate3 parametric_curve_1::d1(GLdouble u)
{
	GLdouble x = 2 * cos(u);
	GLdouble y = -4 * sin(4 * u);
	GLdouble z = 1 / cos(u) / cos(u);
	return DCoordinate3(x, y, z);
}

DCoordinate3 parametric_curve_1::d2(GLdouble u)
{
	GLdouble x = -2 * sin(u);
	GLdouble y = -16 * cos(4 * u);
	GLdouble z = 2 / cos(u) / cos(u) / cos(u) / cos(u) * tan(u);
	return DCoordinate3(x, y, z);
}

GLdouble hypotrochoid::u_min = 0;
GLdouble hypotrochoid::u_max = 6 * TWO_PI;

DCoordinate3 hypotrochoid::d0(GLdouble u)
{
	GLdouble x = 2 * cos(u) + 5 * cos(2 * u / 3);
	GLdouble y = 2 * sin(u) + 5 * sin(2 * u / 3);
	GLdouble z = u;
	return DCoordinate3(x, y, z);
}

DCoordinate3 hypotrochoid::d1(GLdouble u)
{
	GLdouble x = -(6 * sin(u) + 10 * sin(2 * u / 3)) / 3;
	GLdouble y = 2 * cos(u) + 10 * cos(2 * u / 3) / 3;
	GLdouble z = 1.0;
	return DCoordinate3(x, y, z);
}

DCoordinate3 hypotrochoid::d2(GLdouble u)
{
	GLdouble x = -(18 * cos(u) + 20 * cos(2 * u / 3)) / 9;
	GLdouble y = -(18 * sin(u) + 20 * sin(2 * u / 3)) / 9;
	GLdouble z = 0.0;
	return DCoordinate3(x, y, z);
}

GLdouble viviani::u_min = -TWO_PI;
GLdouble viviani::u_max = TWO_PI;

DCoordinate3 viviani::d0(GLdouble u)
{
	GLdouble x = 2 * (1 + cos(u));
	GLdouble y = 2 * sin(u);
	GLdouble z = 4 * sin(u / 2);
	return DCoordinate3(x, y, z);
}

DCoordinate3 viviani::d1(GLdouble u)
{
	GLdouble x = -2 * sin(u);
	GLdouble y = 2 * cos(u);
	GLdouble z = 2 * cos(u / 2);
	return DCoordinate3(x, y, z);
}

DCoordinate3 viviani::d2(GLdouble u)
{
	GLdouble x = -2 * cos(u);
	GLdouble y = -2 * sin(u);
	GLdouble z = -sin(u / 2);
	return DCoordinate3(x, y, z);
}

GLdouble archytas::u_min = -PI / 2;
GLdouble archytas::u_max = PI / 2;
GLdouble archytas::constant = 2;

DCoordinate3 archytas::d0(GLdouble u)
{
	GLdouble x = constant * cos(u) * cos(u);
	GLdouble y = constant * sin(u) * cos(u);
	GLdouble z = constant * sqrt((1 - cos(u)) * cos(u));
	return DCoordinate3(x, y, z);
}

DCoordinate3 archytas::d1(GLdouble u)
{
	GLdouble x = constant * -2 * sin(u) * cos(u);
	GLdouble y = -constant * (sin(u) * sin(u) - cos(u) * cos(u));
	GLdouble z = (constant * (2 * cos(u) - 1) * sin(u)) / (2 * sqrt(1 - cos(u)) * sqrt(cos(u)));
	return DCoordinate3(x, y, z);
}

DCoordinate3 archytas::d2(GLdouble u)
{
	GLdouble x = 2 * constant * (sin(u) * sin(u) - cos(u) * cos(u));
	GLdouble y = -4 * constant * cos(u) * sin(u);
	GLdouble z = -(constant * (sin(u) * sin(u) + 4 * cos(u) * cos(u) * cos(u) * cos(u) - 6 * cos(u) * cos(u) * cos(u) + 2 * cos(u) * cos(u))) / (4 * pow(1 - cos(u), 3 / 2) * pow(cos(u), 3 / 2));
	return DCoordinate3(x, y, z);
}

GLdouble torus::u_min = 0;
GLdouble torus::u_max = TWO_PI;
GLdouble torus::v_min = 0;
GLdouble torus::v_max = TWO_PI;
GLdouble torus::R = 1;
GLdouble torus::r = 0.5;

DCoordinate3 torus::d00(GLdouble u, GLdouble v)
{
	return DCoordinate3((R + r * sin(u)) * cos(v), (R + r * sin(u)) * sin(v), r * cos(u));
}
DCoordinate3 torus::d10(GLdouble u, GLdouble v)
{
	return DCoordinate3(r * cos(u) * cos(v), r * cos(u) * sin(v), -r * sin(u));
}
DCoordinate3 torus::d01(GLdouble u, GLdouble v)
{
	return DCoordinate3(-(R + r * sin(u)) * sin(v), (R + r * sin(u)) * cos(v), 0);
}

GLdouble hyperboloid::u_min = 0;
GLdouble hyperboloid::u_max = 3;
GLdouble hyperboloid::v_min = 0;
GLdouble hyperboloid::v_max = TWO_PI;

DCoordinate3 hyperboloid::d00(GLdouble u, GLdouble v)
{
	return DCoordinate3((1 + cosh(u - 3.0 / 2)) * sin(v),
		(1 + cosh(u - 3.0 / 2)) * cos(v),
		sinh(u - 3.0 / 2));
}
DCoordinate3 hyperboloid::d01(GLdouble u, GLdouble v)
{
	return DCoordinate3(sinh(3.0 / 2 - u) * (-sin(v)),
		sinh(3.0 / 2 - u) * (-cos(v)),
		cosh(3.0 / 2 - u));
}
DCoordinate3 hyperboloid::d10(GLdouble u, GLdouble v)
{
	return DCoordinate3((cosh(3.0 / 2 - u) + 1) * cos(v), -(cosh(3.0 / 2 - u) + 1) * sin(v), 0);
}

GLdouble cylindrical_helicoid::u_min = 0;
GLdouble cylindrical_helicoid::u_max = 2;
GLdouble cylindrical_helicoid::v_min = 0;
GLdouble cylindrical_helicoid::v_max = TWO_PI;

DCoordinate3 cylindrical_helicoid::d00(GLdouble u, GLdouble v)
{
	return DCoordinate3((2 + u) * cos(v), (2 + u) * sin(v), v);
}
DCoordinate3 cylindrical_helicoid::d10(GLdouble u, GLdouble v)
{
	return DCoordinate3(cos(v), sin(v), 0);
}
DCoordinate3 cylindrical_helicoid::d01(GLdouble u, GLdouble v)
{
	return DCoordinate3(-(u + 2) * sin(v), (u + 2) * cos(v), 1);
}

GLdouble alfred_gray::u_min = 0;
GLdouble alfred_gray::u_max = 2;
GLdouble alfred_gray::v_min = 0;
GLdouble alfred_gray::v_max = TWO_PI;

DCoordinate3 alfred_gray::d00(GLdouble u, GLdouble v)
{
	return DCoordinate3((2 - (2 * u / 3)) * cos(v), (2 - (2 * u) / 3) * sin(v), u);
}
DCoordinate3 alfred_gray::d10(GLdouble u, GLdouble v)
{
	return DCoordinate3(-(2 * cos(v)) / 3, -(2 * sin(v)) / 3, 1);
}
DCoordinate3 alfred_gray::d01(GLdouble u, GLdouble v)
{
	return DCoordinate3((2 - (2 * u) / 3) * (-sin(v)), (2 - (2 * u / 3)) * cos(v), 0);
}

GLdouble klein_bottle::u_min = 0.0;
GLdouble klein_bottle::u_max = TWO_PI;
GLdouble klein_bottle::v_min = 0.0;
GLdouble klein_bottle::v_max = TWO_PI;

DCoordinate3 klein_bottle::d00(GLdouble u, GLdouble v)
{
	return DCoordinate3(3 * cos(u) + 1.0 / 2.0 * (1 + cos(2 * u)) * sin(v)
		- 1 / 2 * sin(2 * u) * sin(2 * v),
		3 * sin(u) + 1 / 2 * sin(2 * u) * sin(v)
		- 1.0 / 2.0 * (1 - cos(2 * u)) * sin(2 * v),
		cos(u) * sin(2 * v) + sin(u) * sin(v));
}

DCoordinate3 klein_bottle::d10(GLdouble u, GLdouble v)
{
	return DCoordinate3(-3 * sin(u) + (1 / 2 - sin(2 * u)) * sin(v) + cos(2 * u) * sin(2 * v),
		3 * cos(u) + cos(2 * u) * sin(v) - (1.0 / 2.0 + sin(2 * u)) * sin(2 * v),
		-sin(u) * sin(2 * v) + cos(u) * sin(v));
}

DCoordinate3 klein_bottle::d01(GLdouble u, GLdouble v)
{
	return DCoordinate3(3 * cos(u) + 1 / 2 * (1 + cos(2 * u)) * cos(v) - sin(2 * u) * cos(2 * v),
		3 * sin(u) + 1.0 / 2.0 * sin(2 * u) * cos(v) + (1 - cos(2 * u)) * cos(2 * v),
		2 * cos(u) * cos(2 * v) + sin(u) * cos(v));
}
