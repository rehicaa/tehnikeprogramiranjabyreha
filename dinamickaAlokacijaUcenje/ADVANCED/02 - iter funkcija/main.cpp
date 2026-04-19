//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;
template <typename iterTip>
double sumaDjeljivih (iterTip pocetak, iterTip kraj, int n) {
    double suma = 0;
    while (pocetak != kraj) {
        if (*pocetak % n == 0) suma += *pocetak;
        pocetak++;
    }
    return suma;
}


int main() {
    cout << "Unesite parametar: ";
    int n; cin >> n;

    vector<int>v = {2, 6, 3, 7, 22, 14, 12, 16, 20, 2};
    double suma = sumaDjeljivih(v.begin(), v.end(), n);
    cout << "\nSuma brojeva iz vektora koji su djeljivi sa " << n << " je " << suma << endl;
    return 0;
}