#include "MyVector.hpp"
#include "DynamicStack.hpp"
#include <iostream>

int main() {
    MyVector* v = new MyVector;
    for(int i = 1; i<=10; i++) {
        v->pushBack(i);
    }
    std::cout << "Vektor 1: "; v->print();

    MyVector* v2 = new MyVector(*v);

    int a;
    for(int i = v2->getSize()-1; i>=0; i--) {
        a = v2->popBack();
        //std::cout << "Kapacitet nakon popBacka: " << v2->getCapacity() << ", a = " << a << std::endl;
        std::cout << "Vektor 2: "; v2->print();
    }

    DynamicStack* s1 = new DynamicStack;
    
    
    for(int i = 1; i<=10; i++) {
        s1->push(i);
    }
    std::cout<< "Stack 1: ";
    s1->print();
    
    DynamicStack* s2 = new DynamicStack(*s1);
    while(!s2->empty()) {
        std::cout<< "Stack 2: ";
        s2->print();
        s2->pop();
    }

    delete s1;
    delete s2;
    delete v;
    delete v2;
    
}