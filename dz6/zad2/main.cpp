#include<iostream>
#include "SquareMatrix.hpp"

using namespace std;

int main() {

    const int m = 10;

    SquareMatrix MT(2);
    SquareMatrix MT2(2);

    
    SquareMatrix M1(m);
    for(int i = 0; i<m; i++) {
        M1[i][i] = i+1;
    }
    
    SquareMatrix M2(m);
    M2 = 1;
    M1 += M2;


    M1.print();

    SquareMatrix M3(m);
    M3 = M1;

    M3.print();
    M3 /= 10;
    M3.print();

    return 0;
}