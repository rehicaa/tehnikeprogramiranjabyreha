//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;
bool prebrojiPozitivneINegativneElementeNiza (double niz[], const int brojElemenataNiza, int &brojPozitivnih, int &brojNegativnih) {
    brojPozitivnih = 0;
    brojNegativnih = 0;
    bool imaNule = false;

    for (int i = 0; i < brojElemenataNiza; i++) {
        if (niz[i] == 0) {
            imaNule = true;
        }
        niz[i] > 0 ? brojPozitivnih++ : brojNegativnih++;
    }

    return imaNule;
}

int main() {
    double niz[] = {0.2, -1.2, -4.1, 0, 2.1, 2.3, 2.7};
    int brojP, brojN;
    bool analiziranjeNiza = prebrojiPozitivneINegativneElementeNiza(niz, 7, brojP, brojN);
    cout << "\nBroj negativnih elemenata: " << brojN << "\nBroj pozitivnih elemenata: " << brojP;
    analiziranjeNiza ? cout << "\nU nizu je barem jedan element broj nula." : cout << "\nU nizu nema nijedan element koji je broj nula.";
    return 0;
}