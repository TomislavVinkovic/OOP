#include "MyVector.hpp"
#include<iostream>
#include <stdexcept>
#include <exception>

MyVector::MyVector() {
    capacity = 1;
    arr = new int[this->capacity]; //automatski alociram jedan segment memorije umjesto 0 da ne moram kasnije raditi dodatne provjere
    this->size = 0;
}


MyVector::MyVector(const MyVector& v) {
    std::cout << "Copy!" << std::endl;
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

//operatori
MyVector& MyVector::operator=(const MyVector& v) {

    //pobrisi sve elemente iz arraya, ako postoje
    if(size > 0) delete[] arr;
    
    capacity = v.capacity;
    arr = new int[capacity];
    for(int i=0; i<v.size; i++) {
        arr[i] = v.arr[i];
    }
    size = v.size;

    return *this;
}

MyVector& MyVector::operator+=(const MyVector& v) {

    int limit = v.size > size ? size: v.size; //idi samo do size jer su ostale sigurno sve 0

    for(int i = 0; i<limit; i++) {
        arr[i] += v.arr[i];
    }

    return *this;
}

MyVector MyVector::operator+(const MyVector& v) {

    MyVector v1(*this); //napravi kopiju objekta koja sadrzava ovaj objekt
    v1 += v;

    return v1;
}

int MyVector::operator*(const MyVector& v) {

    int limit = v.size > size ? size: v.size;

    int sum = 0;

    for(int i = 0; i<limit; i++) {\
        sum += arr[i] * v.arr[i];
    }

    return sum;
}

bool MyVector::operator==(const MyVector& v) {
    if( size != v.size || capacity != v.capacity ) {
        return false;
    }

    for(int i = 0; i<size; i++) {
        if( arr[i] != v.arr[i] ) return false;
    }

    //ako su prosli svi uvjeti, vrati true
    return true;
}

bool MyVector::operator!=(const MyVector& v) {
    return !(*this == v);
}

const int& MyVector::operator[](int i) const {
    return arr[i]; //kao i u stl-u, neka se user brine za out of bounds :D
}

int& MyVector::operator[](int i) {
    return arr[i];
}