#include <iostream>
#include <vector>
#include "Node.hpp"
#include "CSLL.hpp"
#include "DynamicQueue.hpp"
#include <stdexcept>
#include <exception>

using namespace std;

int main() {

    CSLL* c1 = new CSLL;
    c1->print(); //prazna lista

    vector<double> v{59.9, 13.7, 10.0, 98.44, 16.7, 20.269, 1.5};

    for(auto &a: v) {
        c1->append(a);
    }
    c1->print();

    CSLL* c2 = new CSLL(*c1);
    c2->print();


    DynamicQueue* d1 = new DynamicQueue;
    d1->print();
    for(auto &a: v) {
        d1->enqueue(a);
    }
    d1->print();

    DynamicQueue* d2 = new DynamicQueue(*d1);
    d2->print();

    delete c1;
    delete c2;
    delete d1;
    delete d2;


    return 0;
}