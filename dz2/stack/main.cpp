#include<iostream>
using namespace std;

class Stack{
    private:
        int top;
        unsigned int size;
        int* container;
    public:
        Stack(unsigned int);
        Stack(const Stack&);
        ~Stack();
        bool empty() const;
        bool full() const;
        void push(int);
        int pop();
        void print() const;
};

Stack::Stack(unsigned int n) {
    this->top = -1;
    this->size = n;
}

Stack::Stack(const Stack& S) {
    this->top = S.top;
    this->size = S.size;
    if(!S.empty()) {
        
        for(int i = 0; i<S.top; i++) {
            this->container[i] = S.container[i];
        }
    }
    else return;
}

Stack::~Stack() {
    delete[] this->container;
}

bool Stack::empty() const {
    return this->top == -1;
}

bool Stack::full() const {
    return this->top == this->size-1;
}

void Stack::push(int a) {
    if(!this->full()) {
        this->top++;
        this->container[top] = a;
    }
}

int Stack::pop() {
    if(!this->empty()) {
        int val = this->container[this->top];
        return val;
    }
    return 0; //ovo treba fixat kasnije
}

int main() {

    
    return 0;
}