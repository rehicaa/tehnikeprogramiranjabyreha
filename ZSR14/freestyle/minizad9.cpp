#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

int main() {
    std::ofstream studentiIzlaz("studenti.txt");
    if (!studentiIzlaz) throw std::logic_error("Datoteka se ne moze procitati");
    for (int i = 0; i < 2; i++) {
        string ime;
        int brIndexa;
        double prosjek;
        std::getline(cin, ime);
        cin >> brIndexa >> prosjek;
        studentiIzlaz << ime << "," << brIndexa << "," << prosjek << endl;
        cin.ignore(10000,'\n');
    }
    studentiIzlaz.close();

    std::ifstream studentiUlaz("studenti.txt");
    if (!studentiUlaz) throw std::logic_error("Datoteka se ne moze procitati");
    string ime; int brIndexa; double prosjek; char zarez;
    while (std::getline(studentiUlaz, ime, ',') && (studentiUlaz >> brIndexa) && (studentiUlaz >> zarez) && (studentiUlaz >> prosjek)) {
        if (zarez != ',') throw std::logic_error("Neispravni podaci u datoteci");
        cout << "Ime: " << ime << " | Broj indeksa: " << brIndexa << " | Prosjek: " << prosjek << endl;
        studentiUlaz.ignore(10000, '\n');
    }
    if (!studentiUlaz.eof())
        throw std::logic_error("Neispravni podaci u datoteci");

    return 0;
}