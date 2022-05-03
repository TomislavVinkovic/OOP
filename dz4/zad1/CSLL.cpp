#include "CSLL.hpp"
#include<iostream>
#include <stdexcept>
#include <exception>

CSLL::CSLL() {}

// objasnjenje: napravi novi node pointer koji pointa na istu memorijsku lokaciju kao c.head
// zatim, do-while petljom setaj po elementima od c dok se ne vratis na pocetak. Sve vrijeme, radi kopije tih podataka
CSLL::CSLL(const CSLL& c) {
    Node* it = c.head;
    do {
        append(it->value);
        it = it->next;
    } while(it != c.head);
}

CSLL::~CSLL() {
    while(!empty()) {
        removeFromHead();
    }
}

bool CSLL::empty() const{
    return head == nullptr;
}

void CSLL::prepend(double value) {
    Node* n = new Node{value};
    if(!empty()) {
        Node* it = head;
        while(it->next != head) {
            it = it->next;
        }
        n->next = head; //postavi next od novog nodea na head
        it->next = n; //postavi next od zadnjeg na novi head
        head = n; //postavi novi head na n
    }
    else {
        head = n;
        n->next = n;
    }
}

double CSLL::removeFromHead() {
    if(!empty()) {
        int retVal = head->value;
        //ako head nije jedini preostali element
        if(head->next != head) {
            Node* it = head;
            while(it->next != head) {
                it = it->next;
            }
            Node* newHead = head->next;
            delete head;
            head = newHead;
            it->next = head;
        }
        else {
            delete head;
            head = nullptr;
        }
        return retVal;
    }
    else throw std::runtime_error("Trying to remove an element from an empty list!");
}

void CSLL::append(double value) {
    prepend(value);
    head = head->next;
}

void CSLL::print() const {
    if(!empty()) {
        Node* it = head;
        do {
            if(it->next != head) {
                std::cout << it->value << "->";
            }else {
                std::cout << it->value;
            }
            
            it = it->next;
        } while(it != head);
        std::cout << std::endl;
    }
    else {
        std::cout << "Empty list" << std::endl;
    }
    
}