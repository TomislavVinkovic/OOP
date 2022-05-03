#include <iostream>
#include "Queue.hpp"

using namespace std;

int main() {

    int a;
    Queue q(10);

    //popuni queue

    for(int i = 10; i>0; i--) {
        q.enqueue(i);
    }

    //isprazni ga
    for(int i = 0; i<15; i++) {
        try {
            a = q.dequeue();
            std::cout << "The throwavay number is: " << a << std::endl;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
            break;
        }
    }

    //ponovno ga napuni
    for(int i = 10; i>0; i--) {
        q.enqueue(i);
    }

    //ispisi ga
    q.print();

    return 0;
}