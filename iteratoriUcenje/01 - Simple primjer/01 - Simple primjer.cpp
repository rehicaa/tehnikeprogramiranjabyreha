//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

int main() {
    vector<int> v = {1, 2, 8, 3, 5, 5, 4};
    for (auto it = v.begin(); it != v.end(); ++it) {
        *it % 2 == 0 ? *it /= 2 : *it *= 2;
    }
    cout << "Modifikovani niz: " << endl;
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        cout << *it << " ";
    }
    return 0;
}