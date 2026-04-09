//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

int brojRijeciRecenice (const string &s) {
    int brojacRijeci = 0;
    bool unutarRijeci = false;
    for (int i = 0; i < s.size(); i++) {
        char c = s.at(i);
        if (c != ' ') {
            if (!unutarRijeci) {
                brojacRijeci++;
                unutarRijeci = true;
            }
        } else {
            if (unutarRijeci) {
                unutarRijeci = false;
            }
        }
    }
    return brojacRijeci;
}

int main() {
    cout << "Unesite recenicu: ";
    string s; std::getline(cin, s);
    cout << "Broj rijeci u ovoj recenici je: " << brojRijeciRecenice(s);
    return 0;
}