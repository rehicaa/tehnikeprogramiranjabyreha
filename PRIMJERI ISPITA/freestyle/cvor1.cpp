#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>


using std::cout, std::cin, std::vector, std::string, std::endl;

struct Cvor {
    int ocjena;
    Cvor *sljedeci;
};

class ListaOcjena {
    Cvor *pocetak;
public:
    ListaOcjena() : pocetak(nullptr){}
    void DodajNaPocetak(int ocjena) {
        Cvor *novi = new Cvor{ocjena, nullptr};
        novi->sljedeci = pocetak;
        pocetak = novi;
    }
    void DodajNaKraj(int ocjena) {
        Cvor *novi = new Cvor{ocjena, nullptr};
        if (pocetak == nullptr) {
            pocetak = novi;
            return;
        }
        Cvor *p = pocetak;
        while (p->sljedeci != nullptr) {
            p = p->sljedeci;
        }
        p->sljedeci = novi;
    }
    int BrojOcjena() const {
        int brojac = 0;
        for (auto it = pocetak; it != nullptr; it = it->sljedeci) {
            brojac++;
        }
        return brojac;
    }
    int DajNajvecuOcjenu() const {
        int najvecaOcjena = INT_MIN;
        for (auto it = pocetak; it != nullptr; it = it->sljedeci) {
            if (it->ocjena > najvecaOcjena) najvecaOcjena = it->ocjena;
        }
        return najvecaOcjena;
    }

    void ObrisiPrvu() {
        Cvor *za_brisanje = pocetak;
        pocetak = pocetak->sljedeci;
        delete za_brisanje;
    }

    void ObrisiPrvuPojavu(int ocjena) {
        if (pocetak != nullptr && pocetak->ocjena == ocjena) {
            Cvor *za_brisanje = pocetak;
            pocetak = pocetak->sljedeci;
            delete za_brisanje;
            return;
        }
        Cvor *prije = pocetak;
        
    }

};

int main() {
    return 0;
}