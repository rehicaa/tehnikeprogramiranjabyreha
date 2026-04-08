//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

int main() {
    cout << "Unesite neki cijeli broj: ";
    int n; cin >> n;

    cout << "Znak koji ima ASCII sifru " << n << " je znak " << static_cast<char>(n);
    return 0;
}