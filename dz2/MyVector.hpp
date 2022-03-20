#pragma once

class MyVector {
    private:
        unsigned int size, capacity;
        int* arr;
    public:
        MyVector();
        MyVector(const MyVector&);
        ~MyVector();

        void pushBack(int);
        int popBack();

        unsigned int getSize() const;
        unsigned int getCapacity() const;

        void print();

        bool empty() const;
        bool full() const;

        int &at(unsigned int pos);
        int& front();
        int& back();

};