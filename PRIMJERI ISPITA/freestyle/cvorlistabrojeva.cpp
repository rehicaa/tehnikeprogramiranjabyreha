#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

struct Cvor {
    int broj;
    Cvor *sljedeci;
};

class ListaBrojeva {
    Cvor *pocetak;
public:
    ListaBrojeva() : pocetak(nullptr){}
    void DodajNaPocetak(int broj) {
        Cvor *novi = new Cvor{broj, pocetak};
        pocetak = novi;
    }
    void DodajNaKraj(int broj) {
        Cvor *novi = new Cvor{broj, nullptr};

        if (pocetak == nullptr) {
            pocetak = novi;
            return;
        }

        Cvor *it = pocetak;

        while (it->sljedeci != nullptr) {
            it = it->sljedeci;
        }

        it->sljedeci = novi;
    }
};

int main() {
    return 0;
}