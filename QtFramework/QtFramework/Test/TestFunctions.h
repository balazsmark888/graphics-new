#pragma once

#include "../Core/DCoordinates3.h"

namespace cagd
{
    namespace spiral_on_cone
    {
        extern GLdouble u_min, u_max;

        DCoordinate3 d0(GLdouble);
        DCoordinate3 d1(GLdouble);
        DCoordinate3 d2(GLdouble);
    }

    namespace torus_knot
    {
        extern GLdouble u_min,u_max;

        DCoordinate3 d0(GLdouble);
        DCoordinate3 d1(GLdouble);
        DCoordinate3 d2(GLdouble);
    }

    namespace parametric_curve_1
    {
        extern GLdouble u_min,u_max;

        DCoordinate3 d0(GLdouble);
        DCoordinate3 d1(GLdouble);
        DCoordinate3 d2(GLdouble);
    }

    namespace hypotrochoid
    {
        extern GLdouble u_min,u_max;

        DCoordinate3 d0(GLdouble);
        DCoordinate3 d1(GLdouble);
        DCoordinate3 d2(GLdouble);
    }

    namespace viviani
    {
        extern GLdouble u_min,u_max;

        //GLdouble a = 2;

        DCoordinate3 d0(GLdouble);
        DCoordinate3 d1(GLdouble);
        DCoordinate3 d2(GLdouble);
    }

    namespace archytas
    {
        extern GLdouble u_min, u_max, constant;

        DCoordinate3 d0(GLdouble);
        DCoordinate3 d1(GLdouble);
        DCoordinate3 d2(GLdouble);
    }

    namespace torus
    {
        extern GLdouble R, r;
        extern GLdouble u_min, u_max, v_min, v_max;
        DCoordinate3 d00(GLdouble u, GLdouble v);
        DCoordinate3 d10(GLdouble u, GLdouble v);
        DCoordinate3 d01(GLdouble u, GLdouble v);
    }

    namespace hyperboloid
    {
        extern GLdouble u_min, u_max, v_min, v_max;

        DCoordinate3 d00(GLdouble u, GLdouble v);
        DCoordinate3 d10(GLdouble u, GLdouble v);
        DCoordinate3 d01(GLdouble u, GLdouble v);
    }

    namespace cylindrical_helicoid
    {
        extern GLdouble u_min, u_max,
        v_min, v_max;

        DCoordinate3 d00(GLdouble u, GLdouble v);
        DCoordinate3 d10(GLdouble u, GLdouble v);
        DCoordinate3 d01(GLdouble u, GLdouble v);
    }

    namespace alfred_gray
    {
        extern GLdouble u_min, u_max,
        v_min, v_max;

        DCoordinate3 d00(GLdouble u, GLdouble v);
        DCoordinate3 d10(GLdouble u, GLdouble v);
        DCoordinate3 d01(GLdouble u, GLdouble v);
    }

    namespace klein_bottle
    {
        extern GLdouble  u_min, u_max,
        v_min, v_max;

        DCoordinate3 d00(GLdouble u, GLdouble v);
        DCoordinate3 d01(GLdouble u, GLdouble v);
        DCoordinate3 d10(GLdouble u, GLdouble v);
    }
}
