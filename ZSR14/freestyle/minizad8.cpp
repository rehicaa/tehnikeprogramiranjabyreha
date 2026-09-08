#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>


using std::cout, std::cin, std::vector, std::string, std::endl;

int main() {
    std::ofstream elektronikaIzlaz("elektronika.txt");
    if (!elektronikaIzlaz) throw std::logic_error("Datoteka se ne moze procitati");
    for (int i = 0; i < 3; i++) {
        string naziv;
        double cijena;
        int kolicina;
        std::getline(cin, naziv); cin >> cijena >> kolicina;
        elektronikaIzlaz << naziv << "," << cijena << "," << kolicina << endl;
        cin.ignore(1000,'\n');
    }
    elektronikaIzlaz.close();

    std::ifstream elektronikaUlaz("elektronika.txt");
    if (!elektronikaUlaz) throw std::logic_error("Datoteka se ne moze procitati");
    string naziv; double cijena; int kolicina; char zarez;
    while (std::getline(elektronikaUlaz, naziv, ',') &&
        elektronikaUlaz >> cijena && elektronikaUlaz >> zarez && elektronikaUlaz >> kolicina) {
        if (zarez != ',') throw std::logic_error("Neispravni podaci");
        cout << "Ime: " << naziv << " | Cijena: " << cijena << " | Kolicina: " << kolicina << endl;
        elektronikaUlaz.ignore(10000, '\n');
    }
    if (!elektronikaUlaz.eof()) throw std::logic_error("Greska pri citanju datoteke");
    return 0;
}