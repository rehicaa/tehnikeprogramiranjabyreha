#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

int main() {
    std::ifstream dat ("BROJEVI.TXT");
    if (!dat) throw std::logic_error("Datoteka se ne moze procitati");
    int broj;
    int suma = 0;
    while (dat >> broj) {
        suma +=broj;
    }

    if (dat.fail() && !dat.eof()) {
        throw std::logic_error("Neispravni podaci u datoteci");
    }

    cout << "Suma brojeva je: " << suma;

    return 0;
}