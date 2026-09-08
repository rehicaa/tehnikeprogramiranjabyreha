#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <climits>
#include <limits>

using std::cout, std::cin, std::vector, std::string, std::endl;

int main() {
    std::ofstream izlaz("brojevi.dat", std::ios::binary);
    if (!izlaz) throw std::logic_error("Datoteka se ne moze procitati");
    for (int i = 0; i < 7; i++) {
        double broj; cin >> broj;
        izlaz.write(reinterpret_cast<char*>(&broj), sizeof broj);
    }

    izlaz.close();

    std::ifstream ulaz("brojevi.dat", std::ios::binary);
    if (!ulaz) throw std::logic_error("Datoteka se ne moze procitati");
    double broj;
    double suma = 0;
    int brojPozitivnih = 0;
    double najveci = std::numeric_limits<double>::lowest();
    while (ulaz.read(reinterpret_cast<char*>(&broj), sizeof broj)) {
        suma += broj;
        if (broj > 0) brojPozitivnih++;
        if (broj > najveci) najveci = broj;
    }
    cout << suma << endl;
    cout << brojPozitivnih << endl;
    cout << najveci << endl;
    return 0;
}