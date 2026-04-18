//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

int main() {
    cout << "Unesite broj elemenata niza: ";
    int n; cin >> n;

    int *niz = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Unesite element[" << i + 1 << "]: ";
        cin >> niz[i];
    }

    int suma = 0; int brojac = 0;
    cout << "Niz obrnuto: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << niz[i] << " ";
        brojac++;
        suma += niz[i];
    }
    delete[] niz;


    double prosjekNiza = static_cast<double>(suma) / brojac;
    cout << "\nProsjek niza je: " << prosjekNiza;

    return 0;
}