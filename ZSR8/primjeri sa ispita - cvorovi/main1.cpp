#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <complex>
#include <list>

using std::cout, std::cin, std::vector, std::string, std::endl;

struct Kompleksni {
    double re, im;
    Kompleksni *sljedeci;
};

Kompleksni* KreirajListu(std::list<std::complex<double>> &lista) {
    Kompleksni *pocetak = nullptr;
    Kompleksni *prethodni = nullptr;
    for (auto it = lista.begin(); it != lista.end(); it++) {
        Kompleksni* novi = new Kompleksni;
        novi->re = (*it).real();
        novi->im = (*it).imag();
        novi->sljedeci = nullptr;
        if (pocetak == nullptr) {
            pocetak = novi;
        } else {
            prethodni->sljedeci = novi;
        }
        prethodni = novi;
    }
    return pocetak;
}

int main() {
    return 0;
}