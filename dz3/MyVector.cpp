#include "MyVector.hpp"
#include<iostream>
#include <stdexcept>
#include <exception>

MyVector::MyVector() {
    this->capacity = 1;
    this->arr = new int[this->capacity]; //automatski alociram jedan segment memorije umjesto 0 da ne moram kasnije raditi dodatne provjere
    this->size = 0;
}


MyVector::MyVector(const MyVector& v) {
    this->capacity = v.capacity;
    this->arr = new int[this->capacity];
    for(int i=0; i<v.size; i++) {
        this->arr[i] = v.arr[i];
    }
    this->size = v.size;
}


MyVector::~MyVector() {
    delete[] this->arr;
}


void MyVector::pushBack(int arg) {
    if(this->size < this->capacity) {
        this->arr[this->size] = arg;
        this->size++;
        return;
    }
    else {
        this->capacity *= 2;
        int* newArr = new int[this->capacity];
        for(int i = 0; i<this->size; i++) {
            newArr[i] = this->arr[i];
        }
        newArr[this->size] = arg;
        this->size++;

        delete[] this->arr;
        this->arr = newArr;
        return;
    }
}


void MyVector::print() {
    for(int i = 0; i<this->size; i++) {
        std::cout << this->arr[i] << " ";
    }
    std::cout << std::endl;
}

bool MyVector::empty() const {
    return this->size == 0;
}

bool MyVector::full() const {
    return this->capacity == this->size;
}

int& MyVector::at(unsigned int pos) {
    if(pos+1 <= this->size) {
        return this->arr[pos];
    }
    else {
        throw std::runtime_error("Pokusaj pristupa nepostojecem elementu vectora");
    }
}

int& MyVector::front() {
    if(!this->empty()) {
        return this->arr[0];
    }
    else {
        throw std::runtime_error("Prazan vektor!");
    }
}

int& MyVector::back() {
    if(!this->empty()) {
        return this->arr[size-1];
    }
    else {
        throw std::runtime_error("Prazan vektor!");
    }
}

unsigned int MyVector::getSize() const {
    return this->size;
};

unsigned int MyVector::getCapacity() const {
    return this->capacity;
};

int* MyVector::begin() const{
    return arr;
}

int* MyVector::end() const{
    return &arr[size-1] + 1; //vrati memorijsku adresu za jedan dalje od zadnjeg elementa
}