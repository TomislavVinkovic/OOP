#include "Point.hpp"
#include "Triangle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <exception>

using namespace std;


double Triangle::a() const{
    return sideLength(this->A, this->B);
}

double Triangle::b() const{
    return sideLength(this->A, this->C);
}

double Triangle::c() const{
    return sideLength(this->B, this->C);
}

Triangle::Triangle(const Point& A, const Point& B, const Point& C) {
    
    this->A = A;
    this->B = B;
    this->C = C;

    if(c() >= a()+b() || a() >= b()+c() || b() >= a()+c()) throw runtime_error("The provided points cannot form a triangle!");
}
Triangle::~Triangle() {}

void Triangle::print() const{
    this->A.print(false);
    this->B.print(false);
    this->C.print(false);
    cout << endl;
}


double Triangle::sideLength(const Point& A, const Point& B) const{
    double x = A.x - B.x;
    double y = A.y - B.y;
    return sqrt( pow(x, 2) + pow(y, 2) );
}

double Triangle::triangleCircumference() const {

    return a()+b()+c();
}

double Triangle::triangleArea() const {

    double s = this->triangleCircumference()/2;
    double area = sqrt(s * (s-a()) * (s-b()) * (s-c()));
    return area;
}

int Triangle::triangleType() const {

    if(a() == b() || a() == c() || b() == c()) {
        return 1;
    }

    if(a() == b() && a() == c() && b() == c()) {
        return 2;
    }

    else return 3;
}