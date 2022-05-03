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
    length = c.length;
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
    length++;
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
        length--;
        return retVal;
    }
    else throw std::runtime_error("Trying to remove an element from an empty list!");
}

void CSLL::append(double value) {
    prepend(value);
    length++;
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

void CSLL::addKth(int k,int x) {
    if(k>=length) {
        append(x);
    }
    if(k == 0) {
        prepend(x);
    }
    else {
        Node* n = new Node(x);
        int count = 0;
        Node* it = head;
        while(count < k) {
            it = it->next;
            count ++;
        }
        Node* temp = it->next;
        it->next = n;
        n->next = temp;
    }
}

void CSLL::eraseAll(int x) {
    if(!empty()) {
        Node* it = head;
        Node* prev = nullptr;
        do {
            if(it->value == x) {
                Node* toDelete = it;
                it = it->next;
                if(toDelete == head) {
                    removeFromHead();
                }
                else {
                    delete toDelete;
                    prev->next = it;
                }
            }
            else {
                Node* temp = it;
                it = it->next;
                prev = temp;
            }
        }while(it->next != head);
    }
}

void CSLL::eraseDuplicates() {
    if(head->next == head) return;
    Node* it = head;
    do {
        print();
        Node* it2 = it->next;
        Node* prev = it;
        Node* temp = nullptr;
        double val = it->value;
        do {
            if(it2->value == val) {
                prev->next = it2->next;
                delete it2;
                it2 = prev->next;
            }
            else {
                temp = it2;
                it2 = it2->next;
                prev = temp;
            }
        }while(it2 != head);

        it = it->next;

    } while(it->next != head);
}