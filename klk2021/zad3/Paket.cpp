#include "Paket.hpp"

Paket::Paket(string& p, Point& adr): prezime{p}, adresa{adr} {}

Paket::Paket(const Paket& pkt) {
    prezime = pkt.prezime;
    adresa = pkt.adresa;
}

void Paket::setPrezime(string& p) {
    prezime = p;
}

void Paket::setAdresa(Point& adr) {
    adresa = adr;
}

string Paket::getPrezime() const {
    return prezime;
}

Point Paket::getAdresa() const {
    return adresa;
}