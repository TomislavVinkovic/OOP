#include "MyVector.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>

MyVector::MyVector() {
    //stavio sam da defaultni kapacitet mora biti 1, da ne moram raditi provjere je li vektor prazan
    //kod alokacije prvog elementa
    this->capacity = 1; 
    this->size = 0;
    this->arr = new int[this->capacity];
}

MyVector::MyVector(const MyVector &V) {
    this->capacity = V.capacity;
    this->size = V.size;
    this->arr = new int[this->capacity];
    for(int i = 0; i<this->size; i++) {
        this->arr[i] = V.arr[i];
    }
}

MyVector::~MyVector() {
    delete[] this->arr;
}

void MyVector::pushBack(int a) {
    if(this->size == this->capacity) {
        this->capacity *= 2;
        int* newArr = new int[this->capacity];

        for(int i = 0; i<this->size; i++) {
            newArr[i] = this->arr[i];
        }
        newArr[this->size] = a;
        this->size++;
        delete[] this->arr;
        this->arr = newArr;
    }

    else {
        this->arr[this->size] = a;
        this->size++;
    }
}

int MyVector::popBack() {
    //ako vektor nije prazan...
    if(!this->empty()) {
        //dohvati zadnji element
        int retVal = this->arr[this->size-1];

        //pobrisi pola arraya ako je potrebno
        if(this->size == this->capacity/2 + 1) {
            int* newArr;
            if(this->capacity == 1) {
                newArr = new int [1];
            }
            else {
                newArr = new int [this->capacity/2];
                this->capacity = this->capacity/2;
            }
            
            for(int i = 0; i<this->size-1; i++) {
                newArr[i] = this->arr[i];
            }
            this->size--;
            delete[] this->arr;
            this->arr = newArr;
        } //ovdje se brise memorija ako je pola arraya prazno

        else {
            //inace samo smanji size za 1 i ucini element nedostupnim
            this->size--;
        }

        return retVal;
    }
    else throw std::runtime_error("Prazan vektor!");
}

unsigned int MyVector::getSize() const{
    return this->size;
}

unsigned int MyVector::getCapacity() const{
    return this->capacity;
}

void MyVector::print() {
    for(int i = 0; i<this->size; i++) {
        std::cout << this->arr[i] << " ";
    }
    std::cout << std::endl;
}

bool MyVector::empty() const{
    return this->size == 0;
}

bool MyVector::full() const{
    return this->size == this->capacity;
}

int& MyVector::at(unsigned int pos) {
    if(pos > this->size - 1) {
        throw std::runtime_error("Prekoracen limit vektora!");
    }
    else {
        return this->arr[pos];
    }
}

int& MyVector::front() {
    if (this->empty()) {
        throw std::runtime_error("Vektor je prazan!");
    }
    else return this->arr[0];
}

int& MyVector::back() {
    if (this->empty()) {
        throw std::runtime_error("Vektor je prazan!");
    }
    else return this->arr[this->size-1];
}