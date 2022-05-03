#pragma once
#include <vector>
#include <algorithm>
#include "Paket.hpp"

using namespace std;

class Dostavljac{
    private:
        vector<Paket> paketi;
    public:
        Dostavljac() {};
        Dostavljac(vector<Paket>&);
        bool dodajPaket(Paket&);
        bool makniPaket(Point&);
        void napraviRutu();
        const vector<Paket>& getPaketi() const;
        void ispisPaketa() const;
};