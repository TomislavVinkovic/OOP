#include "DynamicStack.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>

DynamicStack::DynamicStack() {}

DynamicStack::DynamicStack(const DynamicStack &S) {
    this->container = S.container;
}

bool DynamicStack::empty() const {
    return this->container.empty();
}

void DynamicStack::push(int x) {
    this->container.push_back(x);
}

int DynamicStack::pop() {
    if(!this->empty()) {
        int retVal = this->container.back();
        this->container.pop_back();
        return retVal;
    }
    else throw std::runtime_error("Stack prazan!");
}

void DynamicStack::print() {
    for(auto &v: this->container) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}