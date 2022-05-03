#include<iostream>
#include "MyVector.hpp"


int main() {

    MyVector V1;
    for(int i = 1; i<=10; i++) {
        V1.pushBack(10);
    }
    V1.print();

    MyVector V2 = V1;
    V2.print();
    std::cin.get();

    return 0;
}