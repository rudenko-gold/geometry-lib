#include <vector>
#include <array>
#include <cmath>

template <size_t dim>
class Point {
public:
    Point() { coords.fill(0.0); }
    Point(std::vector<double> points) {
        if (points.size() != dim) {
            throw std::invalid_argument("Wrong dimension amount!");
        }

        coords(points.begin(), points.end());
    }

    Point(std::array<double, dim> points) : coords(coords) {}

    double distanceTo(const Point<dim>& other) const {
        double dist2 = distance2To(other);
        return sqrt(dist2);
    }

    double distance2To(const Point<dim>& other) const {
        double dist2 = 0.0;
        for (size_t dimension = 0; dimension < dim; ++dimension) {
            dist2 += pow(coords[dimension] - other[dimension], 2);
        }
        return dist2;
    }

    double operator[](size_t dimension) const {
        return coords[dimension];
    }
private:
    std::array<double, dim> coords;
};
