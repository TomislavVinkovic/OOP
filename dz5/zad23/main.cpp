#include<iostream>
#include "List.hpp"

using namespace std;

int main() {

    //zad 2
    List* l = new List;
    for(int i = 1; i<=10; i++) {
        l->push_front(i);
    }

    l->display();
    l->reverse();
    l->display();


    //zad 3
    cout << l->avg() << endl;
    cout << l->min()->value << endl;
    cout << l->max()->value << endl;
    
    l->deleteBelowAverage();
    l->display();

    delete l;

    return 0;
}