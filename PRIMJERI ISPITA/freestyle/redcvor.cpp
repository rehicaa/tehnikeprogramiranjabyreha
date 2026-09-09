#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

template<typename Tip>
struct Cvor {
    Tip element;
    Cvor* sljedeci;
};

template<typename Tip>
class Red {
    Cvor<Tip> *pocetak;
    Cvor<Tip> *kraj;
public:
    Red() : pocetak(nullptr), kraj(nullptr){}
    void Stavi (const Tip &element) {
        Cvor<Tip> *novi = new Cvor<Tip>{element, nullptr};
        if (pocetak == nullptr) {
            pocetak = novi;
        } else {
            kraj->sljedeci = novi;
        }
        kraj = novi;
    }
    bool Prazan () {
        return pocetak == nullptr;
    }
    int BrojElemenata() {
        int brojElemenata = 0;
        for (auto it = pocetak; it != nullptr; it = it->sljedeci) brojElemenata++;
        return brojElemenata;
    }
    Tip &Celo() {
        if (Prazan())
            throw std::domain_error("Prazan red");

        return pocetak->element;
    }
    Tip Skini() {
        if (Prazan()) throw std::domain_error("Prazan red");
        Cvor<Tip> *za_brisanje = pocetak;
        Tip element = pocetak->element;

        pocetak = pocetak->sljedeci;
        delete za_brisanje;

        if (pocetak == nullptr) kraj = nullptr;

        return element;
    }
    ~Red() {
        while (pocetak != nullptr) {
            Cvor<Tip> *za_brisanje = pocetak;
            pocetak = pocetak->sljedeci;
            delete za_brisanje;
        }
    }
    Red(const Red &) = delete;
    Red &operator=(const Red &) = delete;

};

int main() {
    return 0;
}