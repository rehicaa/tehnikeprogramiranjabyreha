//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <cctype>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

string ispraviRecenicu (const string &s) {
    string rez;
    for (int i = 0; i < s.size(); i++) {
        char c = s.at(i);
        if (c != ' ') {
            rez.push_back(c);
        } else {
            if (rez.length() > 0 && rez.back() != ' ') {
                rez += ' ';
            }
        }
    }
    if (rez.length() > 0 && rez.back() == ' ') {
        rez.pop_back();
    }

    return rez;
}

int main() {
    cout << "Unesite recenicu: ";
    string s; std::getline(cin, s);
    string s2 = ispraviRecenicu(s);

    cout << "\nIspravljena recenica: "<< endl << s2;
    return 0;
}