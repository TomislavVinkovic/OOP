#include "Point.hpp"
#include "Triangle.hpp"
#include <iostream>

using namespace std;

Point::Point(){};
Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}
Point::~Point(){}

bool Point::isInsideTriangle(const Triangle& triangle){
    Triangle t1(*(this), triangle.B, triangle.C);
    Triangle t2(*(this), triangle.A, triangle.B);
    Triangle t3(*(this), triangle.A, triangle.C);

    double area = t1.triangleArea() + t2.triangleArea() + t3.triangleArea();

    return area == triangle.triangleArea();
}
void Point::print(bool newLine) const{

    cout << "(" << this->x << "," << this->y << ")";
    if(newLine) {
        cout << endl;
    }
}