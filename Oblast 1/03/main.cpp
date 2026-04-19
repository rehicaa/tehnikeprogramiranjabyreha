//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

vector<double> vratiNajduziRasteciPodniz (vector<double> v) {
    int trenutnaDuzina = 1;
    int trenutniPocetak = 0;

    int maxDuzina = 1;
    int maxPocetak = 0;

    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1] < v[i]){
            trenutnaDuzina++;
        } else {
            trenutnaDuzina = 1;
            trenutniPocetak = i;
        }

        if (trenutnaDuzina > maxDuzina) {
            maxDuzina = trenutnaDuzina;
            maxPocetak = trenutniPocetak;
        }
    }
    vector<double>rez;
    for (int i = maxPocetak; i < maxPocetak + maxDuzina; i++) {
        rez.push_back(v[i]);
    }
    return rez;
}

int main() {
    vector<double>v = {0.2, 0.3, 0.1, 0.5, 0.7, 2.3, 1.4, 1.7, 1.8};
    vector<double>rez = vratiNajduziRasteciPodniz(v);
    for (auto x : rez) {
        cout << x << " ";
    }
    return 0;
}