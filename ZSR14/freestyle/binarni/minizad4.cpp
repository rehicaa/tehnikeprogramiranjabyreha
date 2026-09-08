#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>


using std::cout, std::cin, std::vector, std::string, std::endl;

int main() {
    std::ofstream izlaz("brojevi.dat", std::ios::binary);
    if (!izlaz) throw std::logic_error("Datoteka se ne moze procitat");
    for (int i = 0; i < 6; i++) {
        double broj; cin >> broj;
        izlaz.write(reinterpret_cast<char*>(&broj), sizeof broj);
    }
    izlaz.close();

    std::fstream dat("brojevi.dat", std::ios::binary | std::ios::in | std::ios::out);
    if (!dat) throw std::logic_error("Datoteka se ne moze procitat");
    double broj;
    dat.seekg(-static_cast<std::streamoff>(sizeof(double)), std::ios::end);
    dat.read(reinterpret_cast<char*>(&broj), sizeof broj);
    cout << "Zadnji broj: " << broj << endl;
    dat.seekg(0, std::ios::beg);
    dat.read(reinterpret_cast<char*>(&broj), sizeof broj);
    cout << "Prvi broj: " << broj << endl;
    dat.seekg(sizeof(double), std::ios::cur);
    dat.read(reinterpret_cast<char*>(&broj), sizeof broj);
    cout << "Treci broj: " << broj << endl;

    dat.close();

    return 0;
}