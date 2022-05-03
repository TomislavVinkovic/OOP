#pragma once
#include <string>
#include "Point.hpp"

using namespace std;

class Paket{
    private:
        string prezime;
        Point adresa;
    public:
        Paket(string&, Point&);
        Paket(const Paket&);
        void setPrezime(string&);
        void setAdresa(Point&);
        string getPrezime() const;
        Point getAdresa() const;
        void print() const{
            cout << prezime << ": ";
            adresa.print();
        }
};