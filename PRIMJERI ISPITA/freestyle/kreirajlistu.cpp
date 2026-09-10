#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <list>

using std::cout, std::cin, std::vector, std::string, std::endl;
struct Tacka {
    double x, y;
    Tacka *sljedeci;
};

Tacka* KreirajListu(std::list<std::pair<double, double>> &lista) {
    Tacka *pocetak = nullptr;
    Tacka *prethodni = nullptr;
    for (const auto& par : lista) {
        Tacka *novi = new Tacka;
        novi->x = par.first;
        novi->y = par.second;
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