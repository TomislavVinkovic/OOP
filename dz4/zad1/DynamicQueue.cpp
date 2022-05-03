#include "DynamicQueue.hpp"
#include <iostream>

DynamicQueue::DynamicQueue() {
    container = new CSLL;
}

DynamicQueue::DynamicQueue(const DynamicQueue &q) {
    container = new CSLL(*(q.container));
}
DynamicQueue::~DynamicQueue() {
    delete container;
}

bool DynamicQueue::empty() const {
    return container->empty();
}

void DynamicQueue::enqueue(double a) {
    container->append(a); //dodajemo na kraj jer radimo na principu first in, first out
}

double DynamicQueue::dequeue() {
    return container->removeFromHead(); //safety exception je vec implementiran u klasi CSLL
}

void DynamicQueue::print() const {
    if(container->empty()) {
        std::cout << "Empty queue" << std::endl;
        return;
    }
    container->print();
}