//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;


int main() {
    cout << "Unesite recenicu: ";
    string s; std::getline(cin, s);
    int i = s.length() - 1;
    while (i >= 0 && s.at(i) == ' ') {
        i--;
    }

    if (i < 0) {
        return 0;
    }

    int kraj = i;

    while (i >= 0 && s[i] != ' ') {
        i--;
    }
    int pocetak = i + 1;
    string zadnjaRijec = s.substr(pocetak, kraj - pocetak + 1);
    cout << "Posljednja rijec u recenici je: " << zadnjaRijec;
    return 0;
}