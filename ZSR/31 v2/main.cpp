//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

int main() {
    cout << "Unesite neki karakter: ";
    char c; cin >> c;
    cout << "ASCII sifra karaktera " << c << " je: " << static_cast<int>(c);
    cout << endl << "A njegovi prethodnici su: " << endl;
    for (int i = c - 1; i >= 0; i--) {
        cout << static_cast<char>(i) << " ";
    }
    return 0;
}