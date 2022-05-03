#include "List.hpp"
#include<iostream>

using namespace std;

List::List() {}
List::~List() {
    if(!empty()) {
        Node* it = head;
        do {
            Node* temp = it->next;
            delete it;
            it = temp;
        } while(it != nullptr);
    }   
}

bool List::empty() const{
    return head == nullptr;
}

void List::push_front(int a) {
    //novi node ciji je next trenutni head ako lista nije prazna
    //inace je njegov next nullptr, a value a
    Node* n = new Node(a, empty()? nullptr: head);
    head = n;
}

void List::display() {
    if(empty()) {
        cout << "Empty list" << endl;
    }
    cout << endl << "----------------------------------" << endl;
    Node* it = head;
    while(it != nullptr) {
        cout << it->value;
        if(it->next != nullptr) cout << "->";
        it = it->next;
    }
    cout << endl << "----------------------------------" << endl;
}

void List::reverse() {
    if(empty() || head->next == nullptr) {
        return; //lista s jednim elementom i prazna lista su trivijalno inverzibilne
    }

    Node* it = head;
    Node* old_next = head->next;
    Node* prev = head;
    Node* temp;
    while(old_next != nullptr) {
        if(it == head) {
            it->next = nullptr;
            it = old_next;
        }
        else {
            temp = it;
            old_next = old_next->next;
            it->next = prev;
            it = old_next;
            prev = temp;
        }
    }
    head = temp;
}

double List::avg() {
    if(empty()) return 0;
    
    double sum = 0;
    int count = 0;
    Node* it = head;
    while(it != nullptr) {
        sum += it->value;
        count++;
        it = it->next;
    }

    return sum / (double)count; //avg
}

Node* List::max() {
    if(empty()) return nullptr;

    Node* it = head;
    Node* max = head;
    while(it != nullptr) {
        if(it->value > max->value) max = it;
        it = it->next;
    }
    return max;
}

Node* List::min() {
    if(empty()) return nullptr;

    Node* it = head;
    Node* min = head;
    while(it != nullptr) {
        if(it->value < min->value) min = it;
        it = it->next;
    }
    return min;
}

void List::deleteBelowAverage() {
    // lista prazna - nema sta obrisati
    // lista ima 1 node: njegova vrijednost je sigurno jednaka
    // avg vrijednosti jer je jedini u listi :)
    if(!empty() && head->next != nullptr) {
        double avg = this->avg();

        Node* it = head;
        Node* prev = head;

        while(it != nullptr) {
            if((double)it->value < avg) {

                if(it == head) {
                    head = it->next;
                    delete it;
                    it = head;
                    prev = head;
                }

                else {
                    prev->next = it->next;
                    delete it;
                    it = prev->next;
                }

            }

            else {
                prev = it; //pomakni prev na trenutni it
                it = it->next; //pomakni it na sljedeci element
            }
        }
    }
}