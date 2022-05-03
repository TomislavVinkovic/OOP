#include "CSLL.hpp"

int main() {
    CSLL L;
    L.prepend(2);
    L.prepend(-1);
    L.prepend(7);
    L.prepend(4);
    L.prepend(-1);
    L.prepend(4);
    L.prepend(7);
    L.prepend(4);
    L.print();
    L.eraseAll(4);
    L.print();
    L.addKth(2,8);
    L.addKth(0,-5);
    L.addKth(20,-7);
    L.print();
    L.eraseAll(4);
    L.print();
    L.eraseDuplicates();
    L.print();
    return 0;
}