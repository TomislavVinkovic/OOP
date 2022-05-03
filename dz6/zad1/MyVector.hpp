#pragma once

class MyVector {
    protected:
        unsigned int capacity;
        unsigned int size;
        int* arr;
    public:
        MyVector();
        MyVector(int);
        MyVector(const MyVector&);

        unsigned int getSize() const;
        unsigned int getCapacity() const;

        void pushBack(int);
        int popBack(); //ovo moram implementirati

        bool empty() const;
        bool full() const;

        int& at(unsigned int pos);
        int& front();
        int& back();

        int* begin() const;
        int* end() const;

        void print();
        ~MyVector();

        MyVector& operator=(const MyVector&);
        MyVector& operator+=(const MyVector&);
        MyVector operator+(const MyVector&);
        int operator*(const MyVector&);
        bool operator==(const MyVector&);
        bool operator!=(const MyVector&);

        const int& operator[](int) const;
        int& operator[](int);
};