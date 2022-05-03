#pragma once
#include "Node.hpp"

class CDLL {
    protected:
        Node* head;
        Node* tail;
    
    public:
        CDLL();
        CDLL(const CDLL& c);
        ~CDLL();

        bool empty() const;

        //postavi vrijednost na pocetak
        void prepend(double);

        //postavi vrijednost na kraj
        void append(double);

        //ukloni cvor s pocetka i vrati nj. vrijednost
        double removeFromHead();

        //makni cvor s kraja i vrati nj. vrijednost
        double removeFromTail();

        void print() const;
        void sort(); //sortiraj vrijednosti
};