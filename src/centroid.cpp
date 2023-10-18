#include "../include/centroid.hpp"

Centroid::Centroid(int x, int y) : x(x), y(y) {
    // Constructor
}

int Centroid::getX() const {
    return x;
}

int Centroid::getY() const {
    return y;
}
