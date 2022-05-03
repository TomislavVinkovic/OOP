#pragma once
#include "Node.hpp"

class List {

    private:
        Node* head{};
    public:
        List();
        ~List();
        void push_front(int);
        bool empty() const;
        void display();
        void reverse();

        double avg();
        Node* max();
        Node* min();
        void deleteBelowAverage();
        bool erase(int);
};