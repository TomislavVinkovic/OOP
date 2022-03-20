#pragma once
#include<vector>

class DynamicStack{
    private:
        std::vector<int> container;
    public:
        DynamicStack();
        DynamicStack(const DynamicStack&);
        bool empty() const;
        void push(int);
        int pop();
        void print();
};