//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;
bool analyzeTheNiz (double niz[], int brojElemenata, int &brojCjelobrojnih, int &brojNecijelih) {
    brojCjelobrojnih = 0;
    brojNecijelih = 0;

    bool imaNegativanBroj = false;

    for (int i = 0; i < brojElemenata; i++) {
        if (niz[i] < 0) imaNegativanBroj = true;
        niz[i] == static_cast<int>(niz[i]) ? brojCjelobrojnih++ : brojNecijelih++;
    }

    return imaNegativanBroj;
}


int main() {
    double niz[] = {3, 4, 0.2, 0.71, 1.7, -2.4, -2, 17.3};
    int brojCjelobrojnih, brojNecijelih = 0;
    bool imaNegativnih = analyzeTheNiz(niz, 8, brojCjelobrojnih, brojNecijelih);
    cout << "\nBroj cjelobrojnih elemenata ovog niza: " << brojCjelobrojnih << "\nBroj necijelih elemenata ovog niza: " << brojNecijelih;
    imaNegativnih ? cout << "\nU nizu ima barem jedan negativan broj." : cout << "U nizu nema niti jedan negativan broj.";
    return 0;
}