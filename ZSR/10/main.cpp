//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl, std::vector, std::string;

bool imaLiPotpunihKvadrata (const vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 1; j * j <= v[i]; j++) {
            if (j * j == v[i]) return true;
        }
    }

    return false;
}

int main() {
    cout << "Unesite velicinu niza: ";
    int velNiza; cin >> velNiza;
    vector<int>v1;
    for (int i = 0; i < velNiza; i++) {
        cout << "Unesite element niza: ";
        int elementNiza; cin >> elementNiza;

        v1.push_back(elementNiza);
    }

    if (imaLiPotpunihKvadrata(v1)) {
        cout << "U unesenom nizu ima barem jedan potpuni kvadrat.";
    } else {
        cout << "U unesenom nizu nema niti jedan potpuni kvadrat.";
    }

    return 0;
}