#include "Queue.hpp"
#include <iostream>
#include<string>

using namespace std;

int main() {

    Queue<int, 5> q;
    for(int i = 1; i<=5; i++) {
        q.enqueue(i*2);
    }
    q.print();
    q.dequeue();
    q.print();

    for(int i = 1; i<=3; i++) {
        q.dequeue(); //ostavi samo zadnji element
    }
    for(int i = 1; i<=4; i++) {
        q.enqueue(i*2);
    }
    q.print();

    Queue<string, 5> q2;
    for(int i = 1; i<=5; i++) {
        string s = "";
        for(int j = 0; j<=i; j++) {
            s += "a";
        }
        q2.enqueue(s);
    }
    
    q2.print();
    q2.dequeue();
    q2.print();

    return 0;
}