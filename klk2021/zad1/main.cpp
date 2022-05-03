#include<iostream>
#include "Complex.hpp"

using namespace std;

int main()
{
    
    Complex c1{2,M_PI};
    c1.print();
    Complex c2{1,1.5*M_PI};
    c2.print();
    c2*=c1;
    c2.print();
    Complex c3 = c2.potencija(-3);
    c3.print();
    c3/=c1;
    c3.print();
    cout << (c1 == c2) << endl;
    cout << (c1 != c2) << endl;
    Complex c4 = c2/c3;
    c4.print();
    Complex c5 = c3 * c4;
    c5.print();
    return 0;
}
