#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>


using std::cout, std::cin, std::vector, std::string, std::endl;

int main() {
    std::ofstream radniciIzlaz("radnici.txt");
    if (!radniciIzlaz) throw std::logic_error("Datoteka se ne moze citati");

    for (int i = 0; i < 4; i++) {
        string ime;
        double plata;
        std::getline(cin, ime);
        cin >> plata;
        radniciIzlaz << ime << "," << plata << endl;
        cin.ignore(10000,'\n');
    }
    radniciIzlaz.close();
    std::ifstream radniciUlaz ("radnici.txt");
    if (!radniciUlaz) throw std::logic_error("Datoteka se ne moze citati");

    string ime;
    double plata;
    double prosjecnaPlata = 0;
    int brojac = 0;
    int brojacPlataVeciOdDvijeHiljade = 0;
    while (std::getline(radniciUlaz, ime, ',') && radniciUlaz >> plata) {
        cout << "Ime: " << ime << " | Plata: " << plata << endl;
        brojac++;
        prosjecnaPlata += plata;
        if (plata > 2000) brojacPlataVeciOdDvijeHiljade++;
        radniciUlaz.ignore(10000, '\n');
    }

    cout << "Prosjecna plata: " << prosjecnaPlata / brojac << endl;
    cout << "Broj plata vecih od 2000: " << brojacPlataVeciOdDvijeHiljade << endl;
    return 0;
}