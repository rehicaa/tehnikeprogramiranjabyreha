#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <deque>

using std::cout, std::cin, std::vector, std::string, std::endl, std::deque;

struct Cvor {
    long broj;
    Cvor *veza;
};

bool jeLiParan (long n) {
    return n % 2 == 0;
}

int BrojParnih (Cvor *pocetak) {
    if (pocetak == nullptr) return 0;
    int brojac = 0;
    Cvor *trenutni = pocetak;
    do {
        if (jeLiParan(trenutni->broj)) brojac++;
        trenutni = trenutni->veza;
    } while (trenutni != pocetak);
    return brojac;
}

void ObrisiListu (Cvor *pocetak) {
    if (pocetak == nullptr) return;
    Cvor *it = pocetak;
    do {
        Cvor *zaBrisanje = it;
        it = it->veza;
        delete zaBrisanje;
    } while (it != pocetak);
    pocetak = nullptr;
}

Cvor *KreirajListu (deque<int> brojevi) {
    Cvor *pocetak = nullptr;
    Cvor *prethodni = nullptr;

    for (int i = 0; i < brojevi.size(); i++) {
        Cvor *novi = new Cvor;
        novi->broj = brojevi[i];
        novi->veza = nullptr;
        if (pocetak == nullptr) {
            pocetak = novi;
        } else {
            prethodni->veza = novi;
        }
        prethodni = novi;
    }
    if (prethodni != nullptr) {
        prethodni->veza = pocetak;
    }

    return pocetak;
}

int main() {
    std::deque<int> mojiBrojevi = {12, 5, 8, 3, 10, 7, 4};

    Cvor *glavaListe = KreirajListu(mojiBrojevi);

    int broj = BrojParnih(glavaListe);
    std::cout << "U listi ima " << broj << " parnih brojeva." << std::endl;

    ObrisiListu(glavaListe);

    if (glavaListe == nullptr) {
        std::cout << "Memorija uspjesno ociscena." << std::endl;
    }

    return 0;
}