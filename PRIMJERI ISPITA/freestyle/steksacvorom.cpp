#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>


using std::cout, std::cin, std::vector, std::string, std::endl;

template<typename tip>
struct Cvor {
    tip element;
    Cvor *veza;
};
template<typename tip>
class Stek {
    Cvor<tip> *vrh;
public:
    Stek() : vrh(nullptr){}
    void DodajNaVrh(tip element, Cvor ) {
        Cvor<tip> *novi = new Cvor<tip>{element, nullptr};

        if (vrh == nullptr) {
            vrh = novi;
        } else {
            vrh->veza = novi;
            vrh = novi;
        }
    }
    tip DajVrh() {
        if (vrh == nullptr) throw std::logic_error("Stek je prazan");
        return vrh->element;
    }
    tip SkiniSaVrha() {
        if (vrh == nullptr) throw std::logic_error("Stek je prazan");

    }
    void Ispisi() {
    }
};

int main() {
    Cvor<int> *pocetak = nullptr;
    Stek<int> s;
    s.DodajNaVrh(4);
    s.DodajNaVrh(5);
    s.DodajNaVrh(7);


    return 0;
}