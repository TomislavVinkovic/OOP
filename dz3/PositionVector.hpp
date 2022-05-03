#pragma once

struct PositionVector {
    double x, y;

    PositionVector();
    PositionVector(double, double);
    PositionVector(const PositionVector&);

    double norm() const;
    void print() const;
};
