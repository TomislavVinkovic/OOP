#include "PositionVector.hpp"
#include <iostream>
#include<cmath>

PositionVector::PositionVector() {
    x = 0;
    y = 0;
}

PositionVector::PositionVector(double x, double y) {
    this->x = x;
    this->y = y;
}

PositionVector::PositionVector(const PositionVector& v) {
    x = v.x;
    y = v.y;
}

double PositionVector::norm() const {
    return sqrt( pow(x, 2) + pow(y, 2) );
}

void PositionVector::print() const {
    std::cout << "(" << x << ", " << y << ", " << norm() << ") ";
}