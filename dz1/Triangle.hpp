#pragma once
#include "Point.hpp"

class Triangle {
    public:
        Point A;
        Point B;
        Point C;
        Triangle(const Point&, const Point&, const Point&);
        ~Triangle();

        void print() const;
        double sideLength(const Point&, const Point&) const;
        int triangleType() const;
        double triangleCircumference() const;
        double triangleArea() const;
        double a() const;
        double b() const;
        double c() const;
        
};