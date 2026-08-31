#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>

using std::cout, std::cin, std::vector, std::string, std::endl;

struct Cvor {
    int element;
    Cvor *veza;
};

int main() {

    Cvor *pocetak = nullptr;
    Cvor *prethodni = nullptr;

    for (int i = 0; i < 3; i++) {
        int broj; cin >> broj;

        Cvor *novi = new Cvor{broj, nullptr};
        if (pocetak == nullptr) {
            pocetak = novi;
        } else {
            prethodni->veza = novi;
        }
        prethodni = novi;
    }

    for (Cvor *p = pocetak; p != nullptr; p = p->veza) {
        cout << p->element << " ";
    }

    while (pocetak != nullptr) {
        Cvor *sljedeci = pocetak->veza;
        delete pocetak;
        pocetak = sljedeci;
    }
    return 0;
}