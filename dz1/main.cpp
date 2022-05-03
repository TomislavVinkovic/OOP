#include <iostream>
#include "Triangle.hpp"
#include "Point.hpp"

using namespace std;

int main() {

    Point A(1,1);
    Point B(3,4);
    Point C(5,1);

    A.print();

    Point D(3,2);
    Point E(6,9);

    Triangle triangle(A, B, C);

    cout << "Opseg: " << triangle.triangleCircumference() << endl;
    cout << "Tip: " << triangle.triangleType() << endl;
    
    triangle.print();
    cout << "D u trokutu: " << D.isInsideTriangle(triangle) << endl;
    cout << "E u trokutu: " << E.isInsideTriangle(triangle) << endl;

    return 0;
}