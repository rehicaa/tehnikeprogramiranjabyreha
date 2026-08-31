#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>

using std::cout, std::cin, std::vector, std::string, std::endl;

struct Koordinata {
    double x, y;
    Koordinata *sljedeci;
};

Koordinata* KreirajListu (vector<std::pair<double, double>> &v) {
    Koordinata *pocetak = nullptr;
    Koordinata *prethodni = nullptr;
    for (int i = 0; i < v.size(); i++) {
        Koordinata *novi = new Koordinata;
        novi->x = v[i].first;
        novi->y = v[i].second;
        if (pocetak == nullptr) {
            pocetak = novi;
        } else {
            prethodni->sljedeci = novi;
        }
        prethodni = novi;
    }
    if (prethodni != nullptr) {
        prethodni->sljedeci = pocetak;
    }
    return pocetak;
}

int main() {
    return 0;
}