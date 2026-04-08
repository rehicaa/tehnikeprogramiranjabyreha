//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <cctype>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

void Ocisti() {
    std::cin.clear();
    std::cin.ignore('\n', 10000);
}

bool daLiJeSuglasnik (char c) {
    c = std::tolower(c);
    if (!std::isalpha(c)) return false;
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool daLiJeRijecKorektna(const string &s) {
    if (s.size() <= 2) return true;
    int brojac = 0;
    for (int i = 0; i < s.size(); i++) {
        if (daLiJeSuglasnik(s.at(i))) {
            brojac++;
            if (brojac > 2) return false;
        } else {
            brojac = 0;
        }
    }
    return true;
}


int main() {
    cout << "Unesite rijec: ";
    string s; std::getline(cin, s);
    daLiJeRijecKorektna(s) ? cout << "Rijec je korektna!" : cout << "Rijec nije korektna!";
    return 0;
}