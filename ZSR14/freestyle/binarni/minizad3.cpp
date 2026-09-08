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
    for (int i = 0; i < 6; i++) {
        double broj; cin >> broj;
        izlaz.write(reinterpret_cast<char*>(&broj), sizeof broj);
    }

    izlaz.close();

    std::fstream dat("brojevi.dat", std::ios::binary |std::ios::in | std::ios::out);
    if (!dat) throw std::logic_error("Datoteka se ne moze otvoriti");
    double a, b;
    dat.seekg(1 * sizeof(double), std::ios::beg);
    dat.read(reinterpret_cast<char*>(&a), sizeof a);

    dat.seekg(4 * sizeof(double), std::ios::beg);
    dat.read(reinterpret_cast<char*>(&b), sizeof b);

    dat.seekp(1 * sizeof(double), std::ios::beg);
    dat.write(reinterpret_cast<char*>(&b), sizeof b);

    dat.seekp(4 * sizeof(double), std::ios::beg);
    dat.write(reinterpret_cast<char*>(&a), sizeof a);

    dat.close();

    std::ifstream ulaz("brojevi.dat", std::ios::binary);
    if (!ulaz) throw std::logic_error("Datoteka se ne moze procitati");
    double broj;
    while (ulaz.read(reinterpret_cast<char*>(&broj), sizeof broj)) {
        cout << broj << endl;
    }
    if (!ulaz.eof()) throw std::logic_error("Greska pri citanju datoteke");

    return 0;
}