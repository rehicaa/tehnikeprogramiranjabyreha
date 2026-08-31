#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <complex>
#include <list>

using std::cout, std::cin, std::vector, std::string, std::endl;

struct Kompleksni {
    double re, im;
    Kompleksni *sljedeci;
};

Kompleksni* KreirajListu (std::list<std::complex<double>> &l) {
    Kompleksni *pocetak = nullptr;
    Kompleksni *prethodni = nullptr;

    for (auto it = l.begin(); it != l.end(); it++) {
        Kompleksni *novi = new Kompleksni;
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
    std::list<std::complex<double>> l = {
        {2, 3},
        {5, 7},
        {1, -4}
    };

    Kompleksni *pocetak = KreirajListu(l);


    return 0;
}