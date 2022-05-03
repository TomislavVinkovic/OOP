#include<iostream>
#include "MyVector.hpp"
using namespace std;

int main() {
    MyVector v, v1;

    
    for(int i = 1; i<=10; i++) {
        v.pushBack(i);
    }

    for(int i = 10; i>=1; i--) {
        v1.pushBack(i);
    }

    v.print();
    v1.print();

    
    cout << "Jednaki? " << (v == v1) << endl;
    cout << "Razliciti? " << (v != v1) << endl;

    cout << "v += v1 ";
    (v += v1).print();
    cout << endl;

    MyVector v3 = v + v1;
    cout << "v3: ";
    v3.print();
    cout << endl;

    cout << "Skalarni produkt: " << (v * v1) << endl;

    cout << "4. element v3: " << v3[3] << endl;
    
    return 0;
}