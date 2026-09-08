#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>


using std::cout, std::cin, std::vector, std::string, std::endl;

int main() {
    std::ofstream proizvodiIzlaz("PROIZVODI.TXT");
    if (!proizvodiIzlaz) throw std::logic_error("Datoteka se ne moze otvoriti");
    for (int i = 0; i < 3; i++) {
        double cijena;
        string naziv;
        std::getline(cin, naziv);
        cin >> cijena;

        proizvodiIzlaz << naziv << "," << cijena << endl;

        cin.ignore(10000, '\n');
    }
    proizvodiIzlaz.close();

    std::ifstream proizvodiUlaz("PROIZVODI.TXT");
    if (!proizvodiUlaz) throw std::logic_error("Datoteka se ne moze otvoriti");
    string naziv;
    double cijena;
    while (std::getline(proizvodiUlaz, naziv, ',') && proizvodiUlaz >> cijena) {
        cout << "Proizvod: " << naziv << " | Cijena: " << cijena << endl;
        proizvodiUlaz.ignore(10000,'\n');
    }


    return 0;
}