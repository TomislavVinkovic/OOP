#include "Queue.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>


/*
    Objasnjenje - micanje head/tail

        X - oznacava prazna/nedostupna polja

        |H/T| |X| |X| |X| || pri kreiranju containera head i tail pokazuju na isto mjesto. Container uvijek ima jedno prazno mjesto kako bismo sacuvali informaciju o tome
        je li polje prazno. Tail pokazuje na sljedecu lokaciju za upis.

        |H(E)| |E| |E| |E| |T| U ovoj situaciji polje je puno. Tail je na zadnjoj poziciji i pomicanjem istog za 1 samo bismo ga vratili na prvo mjesto(modulo operator)

        |X| |X| |H(E)| |E| |T| U ovoj situaciji, ukoliko bismo htjeli popuniti polje, to bismo napravili na poziciji taila. Bitno je da izmedu heada i taila cirkularno ima barem
        jedno polje razmaka

*/

Queue::Queue(unsigned int size): size{size+1}, head{0}, tail{0}, container {new int[size+1]} {}

Queue::Queue(const Queue& q) {
    size = q.size;
    head = q.head;
    tail = q.tail;

    container = new int[size];

    for(unsigned int i = head; i != tail; i = (i+1)%size) {
        container[i] = q.container[i];
    }
}

Queue::~Queue() {
    delete[] container;
}

bool Queue::empty() const {
    return head == tail;
}

bool Queue::full() const{
    return (tail+1) % size == head; // npr, tail 4 + 1 = 5, 5%5 = 0
}

void Queue::enqueue(int a) {
    if(!full()) {
        container[tail++] = a;
        tail = tail%size;
    }
}

int Queue::dequeue() {
    if(!empty()) {
        int retVal =  container[head++];
        head = head%size;
        return retVal;
    }
    else throw std::runtime_error("Queue empty!");
}

void Queue::print() const {
    for(unsigned int i = head; i!=tail; i = (i+1)%size) {
        std::cout << "|" << container[i] << "|" << " ";
    }
    std::cout << std::endl;
}