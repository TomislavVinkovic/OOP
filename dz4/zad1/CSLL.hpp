#pragma once
#include "Node.hpp"

class CSLL {
    private:
        Node* head{};

    public:
        CSLL();
        CSLL(const CSLL&);
        ~CSLL();

        bool empty() const;
        void prepend(double value);
        void append(double value);

        double removeFromHead();

        void print() const;
};