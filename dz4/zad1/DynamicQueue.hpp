#pragma once
#include "CSLL.hpp"

class DynamicQueue {
    protected:
        CSLL* container;
    public:
        DynamicQueue();
        DynamicQueue(const DynamicQueue&);
        ~DynamicQueue();
        bool empty() const;
        void enqueue(double);
        double dequeue();
        void print() const;
};