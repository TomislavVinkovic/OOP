#include <iostream>
#include <stdexcept>
#include <exception>
#pragma once

template<typename T, std::size_t S>
class Queue {
    public:
        T* head;
        T* tail;
        T container [S + 1];

        Queue();
        ~Queue();
        Queue(const Queue&);

        bool full() const;
        bool empty() const;

        void enqueue(const T&);
        T dequeue();

        void print() const;
};

template<typename T, std::size_t S>
Queue<T, S>::Queue() {
    head = container;
    tail = container;
}

template<typename T, std::size_t S>
Queue<T, S>::Queue(const Queue& q) {
    for(int i = 0; i<S+1; i++) {
        container[i] = q.container[i];
    }
}

template<typename T, std::size_t S>
Queue<T, S>::~Queue() {}

template<typename T, std::size_t S>
bool Queue<T, S>::empty() const {
    return head == tail;
}

template<typename T, std::size_t S>
bool Queue<T, S>::full() const {
    auto container_size = sizeof(container)/sizeof(T);
    if(tail + 1 == head) {
        //ako je sljedeca adresa adresa od heada
        return true;
    }
    if(&container[container_size-1] == tail && container == head) {
        //specijalan slucaj, ako je adresa od taila na kraju containera
        //provjeri je li adresa od heada na pocetku
        //ako je znaci da je pun
        return true;
    }
    return false;
}

template<typename T, std::size_t S>
void Queue<T, S>::enqueue(const T& val) {
    auto container_size = sizeof(container)/sizeof(T);
    if(full()) {
        std::cout << "Queue je pun" << std::endl;
        return;
    }
    *tail = val;
    if(tail == &container[container_size-1]) {
        //specijalan slucaj: ako je tail na kraju
        //a na pocetku ima mjesta, pomakni ga na pocetak
        tail = container;
        return;
    }
    //inace ga samo pomakni za jedno mjesto
    tail = tail+1;
}

template<typename T, std::size_t S>
T Queue<T, S>::dequeue() {
    auto container_size = sizeof(container)/sizeof(T);
    if(empty()) {
        throw std::runtime_error("Queue empty!");
    }
    T retVal = *head;
    if(head == &container[container_size-1]) {
        head = container;
    }
    else {
        head = head + 1;
    }
    return retVal;

}

template<typename T, std::size_t S>
void Queue<T, S>::print() const{
    
    auto container_size = sizeof(container)/sizeof(T);
    //postavi i na head, i idi po containeru dok god ne dodes do taila
    for(auto i = head; i != tail; ) {
        std::cout << "|" << (*i) << "|" << " ";
        //ako dodes do kraja, postavi i na prvi element
        if(i == &container[container_size-1]) {
            i -= (container_size-1);
        }
        else {
            // inace, samo ga pomakni za 1
            i++;
        }
    }
    std::cout << std::endl;
}