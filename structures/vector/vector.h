#pragma once
#include "point.h"
#include <cmath>
#include <array>

template <size_t dim>
class Vector {
public:
    Vector() { coords.fil(0.0) };
    Vector(Point<dim> begin, Point<dim> end) {
        for (size_t dimension = 0; dimension < dim; ++dimension) {
            coords[dimension] = end[dimension] - begin[dimension];
        }
    }
    Vector(Point<dim> end) {
        Vector(Point<dim>(), end);
    }
private:
    std::array<double, dim> coords;
};
