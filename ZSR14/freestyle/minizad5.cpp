#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>


using std::cout, std::cin, std::vector, std::string, std::endl;

int main() {
    std::ifstream brojevi("BROJEVI.TXT");
    if (!brojevi) throw std::logic_error("Datoteka se ne moze otvoriti");
    int broj;
    int brojacParnih = 0;
    int suma = 0;
    while (brojevi >> broj) {
        if (broj % 2 == 0) brojacParnih++;
        suma+=broj;
    }

    cout << "Suma brojeva je: " << suma << endl;
    cout << "Broj parnih: " << brojacParnih << endl;

    return 0;
}