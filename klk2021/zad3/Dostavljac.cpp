#include "Dostavljac.hpp"

Dostavljac::Dostavljac(vector<Paket>& vp) : paketi{vp} {}

bool Dostavljac::dodajPaket(Paket& p) {
    for(const auto&a : paketi) {
        if(a.getAdresa() == p.getAdresa()) return false;
    }
    paketi.push_back(p);
    return true;
}   

bool Dostavljac::makniPaket(Point& adr) {
    for(auto i = paketi.begin(); i != paketi.end();) {
        if( (*i).getAdresa() == adr ) {
            paketi.erase(i);
            return true;
        }
        else i = i+1;
    }
    return false;
}

void Dostavljac::napraviRutu() {
    sort(paketi.begin(), paketi.end(), [&](Paket a, Paket b){
        if(a.getAdresa().getx() != b.getAdresa().getx()) {
            return a.getAdresa().getx() < b.getAdresa().getx();
        }
        else {
            return a.getAdresa().euclideanDistance(getPaketi().back().getAdresa()) < b.getAdresa().euclideanDistance(getPaketi().back().getAdresa());
        }
    });
}

const vector<Paket>& Dostavljac::getPaketi() const {
    return paketi;
}

void Dostavljac::ispisPaketa() const {
    for(auto& a : paketi) {
        a.print();
    }
}