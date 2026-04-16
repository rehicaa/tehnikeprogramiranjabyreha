//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <cctype>


using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

string ispraviRecenicu (const string &s, char c) {
    string rez;
    for (int i = 0; i < s.size(); i++) {
        char trenutni = s.at(i);
        if (!std::isspace(trenutni)) {
            rez.push_back(trenutni);
        } else {
            if (!rez.empty() && rez.back() != c) {
                rez.push_back(c);
            }
        }
    }
    if (!rez.empty() && rez.back() == c) {
        rez.pop_back();
    }
    return rez;
}

int main() {
    cout << "Unesite recenicu: ";
    string s; std::getline(cin, s);
    string sRez = ispraviRecenicu(s, ',');
    cout << "\nIspravljena recenica: " << sRez;
    return 0;
}