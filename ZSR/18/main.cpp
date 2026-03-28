//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl, std::vector, std::string;

vector<int> sortirajParnePaNeparne (int niz[], int brojElemenata) {
    vector<int>rez;
    for (int i = 0; i < brojElemenata; i++) {
        if (niz[i] % 2 == 0) {
            rez.push_back(niz[i]);
        }
    }
    for (int i = 0; i < brojElemenata; i++) {
        if (niz[i] % 2 != 0) {
            rez.push_back(niz[i]);
        }
    }

    return rez;
}

int main() {

    const int brEl = 10;

    int niz[brEl];

    for (int i = 0; i < brEl; i++) {
        cout << "Unesite element[" << i + 1 << "]: ";
        if (!(cin >> niz[i])) {
            cout << "Pogresan unos podataka!.";
            return 1;
        }

    }

    vector<int>v = sortirajParnePaNeparne(niz, brEl);
    for (auto x: v) {
        cout << x << " ";
    }


    return 0;
}