#include "CDLL.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>

CDLL::CDLL(): head{nullptr}, tail{nullptr} {}

CDLL::CDLL(const CDLL& c) {
    head = nullptr;
    tail = nullptr;
    Node* it = c.head;
    do {
        append(it->value);
        it = it->next;
    }while(it != c.head);
}

CDLL::~CDLL() {
    while(!empty()) {
        removeFromTail();
    }
}

bool CDLL::empty() const {
    return head == nullptr;
}

void CDLL::prepend(double value) {
    Node* n = new Node(value);
    if(empty()) {
        head = n;
        tail = n;
        n->prev = n;
        n->next = n;
    }
    else {
        n->next = head;
        n->prev = tail;
        tail->next = n;
        head->prev = n;
        head = n;
    }
}


void CDLL::append(double value) {
    if(empty()) {
        prepend(value);
    }
    else {
        //znam da sam i ovo mogao rjesiti preko prependa, ali ovako sam siguran u rjesenje :)
        Node* n = new Node(value);
        n->prev = tail;
        n->next = head;
        tail->next = n;
        head->prev = n;
        tail = n;
    }
}


double CDLL::removeFromHead() {
    if(!empty()) {
        double retVal = head->value;
        //ako lista ima samo jedan element, resetiraj je na praznu listu
        if(head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* newHead = head->next;
            tail->next = newHead; // sljedeci element poslije taila je sada novi head
            newHead->prev = tail; //prethodni element novog heada je sad tail (postigli smo krug)
            delete head;
            head = newHead;
        }
        return retVal;
    }
    else {
        throw std::runtime_error("Trying to remove an element from an empty list!");
    }
}

double CDLL::removeFromTail() {
    if(!empty()) {
        double retVal = tail->value; //dohvati vrijednost taila
        //ako lista ima samo jedan element, resetiraj je na praznu listu
        if(head == tail) {
            retVal = tail->value;
            delete tail;
            head = nullptr;
            tail = nullptr;
            return retVal;
        }
        else {
            Node* newTail = tail->prev;
            head->prev = newTail;
            newTail->next = head;
            delete tail;
            tail = newTail;
        }
        return retVal;
    }
    else {
        throw std::runtime_error("Trying to remove an element from an empty list!");
    }
}

void CDLL::print() const{
    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "Head at: " <<  head << ", tail at: " << tail << std::endl;

    if(!empty()) {
        std::cout << "-----------------------------------------------------------" << std::endl;
        Node* it = head;
        do {
            it->print();
            it = it->next;
        } while(it != head);
    }
    else {
        std::cout << "";
    }
    std::cout << "-----------------------------------------------------------" << std::endl;
    
}

void CDLL::sort() {
    //implementacija insertion sorta
    Node* it = head;
    do {
        //ako it nije bas prvi element, udi u petlju
        if(it != head) {
            Node* it_cmp = it;

            //dok ne dodes do prvog elementa i prethodna vrijednost je veca od trenutne, zamijeni 2 nodea
            while(it_cmp != head && it_cmp->prev->value >= it_cmp->value) {
                it_cmp->swap( *(it_cmp->prev) );
                it_cmp = it_cmp->prev;
            }
        }

        //prijedi na sljedeci element
        it = it->next;

    } while(it!= head); //radi ovo dok cirkularno ne dodes opet do glave
}