#include <iostream>
#include<string>
#include "Map.hpp"
using namespace std;

int main() {

    Map<string, unsigned int> m;
    string rijec = "abeceda";

    for(auto& a: rijec) {
        //trebam castati char u string da ga mogu koristiti kao key
        string temp(1, a);
        m[temp] +=1;
    }

    m.print();

    return 0;
}