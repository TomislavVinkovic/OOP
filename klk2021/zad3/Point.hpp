#pragma once
#include <cmath>
#include <iostream>

using namespace std;

class Point {
    double x, y;
    public:
        Point(): x{}, y{} {};
        Point(double x, double y): x{x}, y{y} {};
        Point(const Point& p): x{p.x}, y{p.y} {};
        void setx(double a) {x = a;}
        void sety(double b) {y = b;};
        double getx() const {return x;};
        double gety() const {return y;};
        double euclideanDistance(const Point& p) const {
            return sqrt(pow(x - p.getx(), 2.0) + pow(y - p.gety(), 2.0));
        }
        bool operator==(const Point& p) {
            return (x == p.x && y == p.y);
        }
        void print() const {
            cout << "(" << x << ", " << y << ")" << endl;
        }
};