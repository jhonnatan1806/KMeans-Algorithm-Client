#include "../include/gather.hpp"

Gather::Gather() : x(0), y(0), size(0) {
    // Constructor
}

int Gather::getX() const {
    return x;
}

int Gather::getY() const {
    return y;
}

int Gather::getSize() const {
    return size;
}

void Gather::collectData(int x, int y) {
    this->x += x;
    this->y += y;
    this->size += 1;
}
