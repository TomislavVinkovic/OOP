#pragma once

class Triangle;

class Point {
    public:
        double x;
        double y;
        Point();
        Point(double, double);
        ~Point();

        bool isInsideTriangle(const Triangle&);
        void print(bool newLine = true) const;
};