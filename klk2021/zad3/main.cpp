#include "Dostavljac.hpp"
#include "Paket.hpp"

int main() {
    string prezime = "Horvat";
    Point adresa{2,5};
    Paket p1{prezime, adresa};
    string prezime2 = "Ivanov";
    Point adresa2{-1,2};
    Paket p2{prezime2, adresa2};
    string prezime3 = "Lovric";
    Point adresa3{1,3};
    Paket p3{prezime3, adresa3};
    string prezime4 = "Horvatic";
    Point adresa4{2,5};
    Paket p4{prezime4, adresa4};
    string prezime5 = "Bilic";
    Point adresa5{3,1};
    Paket p5{prezime5, adresa5};
    string prezime6 = "Nakic";
    Point adresa6{13,2};
    Paket p6{prezime6, adresa6};
    Dostavljac d{};
    cout << d.dodajPaket(p1) << endl;
    cout << d.dodajPaket(p2) << endl;
    cout << d.dodajPaket(p3) << endl;
    cout << d.dodajPaket(p4) << endl;
    cout << d.dodajPaket(p5) << endl;
    cout << d.dodajPaket(p6) << endl;
    d.ispisPaketa();
    Point adresa_makni1{-2,3};
    Point adresa_makni2{3,1};
    cout << d.makniPaket(adresa_makni1) << endl;
    cout << d.makniPaket(adresa_makni2) << endl;
    cout << "-------------------------"<< endl;
    d.ispisPaketa();;
    cout << "-------------------------"<< endl;
    d.napraviRutu();
    d.ispisPaketa();
    return 0;
}