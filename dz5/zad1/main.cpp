#include <iostream>
#include<array>
#include<list>

using namespace std;

double sum(list<double>& l) {
    if(l.empty()) return 0;

    double x = 0;
    for(const auto& a: l) {
        x += a;
    }
    return x;
}

double prod(list<double>& l) {
    if(l.empty()) return 0;

    double x = 1;
    for(const auto& a: l) {
        x *= a;
    }
    return x;
}

double min(list<double>& l) {
    if(l.empty()) return -1;
    
    double min = *l.begin();
    for(const auto& a: l) {
        if(a<min) min = a;
    }
    return min;
}

double max(list<double>& l) {
    if(l.empty()) return -1;

    double max = *l.begin();
    for(const auto& a: l) {
        if(a>max) max = a;
    }
    return max;
}

int main() {
    array<double, 7> arr{59.9, 13.7, 10.0, 98.44, 16.7, 20.269, 1.5};
    list<double> l(arr.begin(), arr.end());

    cout << "Suma: " << sum(l) << endl;
    cout << "Produkt: " << prod(l) << endl;
    cout << "Minimum: " << min(l) << endl;
    cout << "Maksimum: " << max(l) << endl;

    return 0;
}