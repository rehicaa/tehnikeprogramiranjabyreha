//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

template<typename iterTip, typename funkTip>
double sumaPoUslovu (iterTip pocetak, iterTip kraj, funkTip uslov) {
    double suma = 0;
    while (pocetak != kraj) {
        if (uslov(*pocetak)) suma += *pocetak;
        ++pocetak;
    }
    return suma;
}

int main() {
    vector<int>v1 = {2, 4, 3, 1 , 17, 23, 13, 14, 15};
    double suma1 = sumaPoUslovu(v1.begin(), v1.end(), [](int n) {
        return n % 2 == 0;
    });
    cout << "\nSuma parnih brojeva je: " << suma1;

    double suma2 = sumaPoUslovu(v1.begin(), v1.end(), [](int n) {
        return n > 15;
    });
    cout << "\nSuma brojeva koji su veci od 15 je: " << suma2;

    return 0;
}