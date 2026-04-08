//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

int main() {
    cout << "Unesite prvu recenicu: ";
    string s1; std::getline(cin, s1);
    cout << endl;
    cout << "Unesite drugu recenicu: ";
    string s2; std::getline(cin, s2);


    cout << endl;
    int brojac1 = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (!std::isspace(s1.at(i))) brojac1++;
    }
    cout << "Prva recenica ima " << brojac1 << " znakova.";

    cout << endl;
    int brojac2 = 0;
    for (int i = 0; i < s2.size(); i++) {
        if (!std::isspace(s2.at(i))) brojac2++;
    }
    cout << "Druga recenica ima " << brojac2 << " znakova.";

    cout << endl;
    cout << "Spojene recenice: " << s1 + s2 << endl;

    cout << "Prva recenica unazad: ";
    for (int i = s1.length() - 1; i >= 0; i--) {
        cout << s1.at(i);
    }

    if (s1 > s2) {
        cout << "\nPo abecednom poretku, prva je recenica2.";
    } else if (s2 > s1) {
        cout << "\nPo abecednom poretku, prva je recenica1.";
    } else {
        cout << "\nRecenice su jednake po abecednom poretku.";
    }

    return 0;
}