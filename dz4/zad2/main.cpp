#include <iostream>
#include<vector>
#include "CDLL.hpp"
#include "Node.hpp"

using namespace std;


int main() {
    
    vector<double> v {59.9, 13.7, 10.0, 98.44, 16.7, 20.269, 1.5};
    
    CDLL* c1 = new CDLL;
    c1->print();

    for(const auto& a: v) {
        c1->append(a);
    }
    c1->print();

    CDLL* c2 = new CDLL(*c1);
    c2->sort();
    c2->print();

    delete c1;
    delete c2;
}