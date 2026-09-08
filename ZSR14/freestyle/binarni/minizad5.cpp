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

    std::ifstream ulaz("brojevi.dat", std::ios::binary);
    if (!ulaz) throw std::logic_error("Datoteka se ne moze procitat");
    ulaz.seekg(0, std::ios::end);
    std::streamoff velicina = ulaz.tellg();
    int ukupnoElemenata = velicina / sizeof(double);
    cout << "Ukupno bajtova: " << velicina << endl;
    cout << "Ukupno elemenata: " << ukupnoElemenata << endl;
    ulaz.seekg(0, std::ios::beg);
    double broj;
    while (ulaz.read(reinterpret_cast<char*>(&broj), sizeof broj)) {
        cout << broj << endl;
    }

    if (!ulaz.eof()) throw std::logic_error("Greska pri citanju datoteke");
    
    return 0;
}