#pragma once
#include "Node.hpp"

class CSLL {
    private:
        int length{};
        Node* head{};

    public:
        CSLL();
        CSLL(const CSLL&);
        ~CSLL();

        bool empty() const;
        void prepend(double value);
        void append(double value);

        void addKth(int k,int x);
        void eraseAll(int x);
        void eraseDuplicates();

        double removeFromHead();

        void print() const;
};