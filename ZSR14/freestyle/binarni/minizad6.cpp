#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>


using std::cout, std::cin, std::vector, std::string, std::endl;

int main() {
    cout << "Unesite broj elemenata binarne datoteke: "; int brEl; cin >> brEl; cout << endl;
    std::ofstream izlaz("brojevi.dat", std::ios::binary);
    if (!izlaz) throw std::logic_error("Datoteka se ne moze procitat");
    for (int i = 0; i < brEl; i++) {
        double broj; cin >> broj;
        izlaz.write(
            reinterpret_cast<char*>(&broj),
            sizeof broj
        );
    }
    izlaz.close();

    std::ifstream dat("brojevi.dat", std::ios::binary);
    if (!dat) throw std::logic_error("Datoteka se ne moze procitat");
    double broj;
    for (int i = brEl - 1; i >= 0; i--) {
        dat.seekg(static_cast<std::streamoff>(i) * sizeof(double), std::ios::beg);
        dat.read(reinterpret_cast<char*>(&broj), sizeof broj);
        if (!dat) throw std::logic_error("Greska pri citanju datoteke");
        cout << broj << endl;
    }


    return 0;
}