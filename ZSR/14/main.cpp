//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;
void prebrojiElementeVektoraSaParnimNeparnimBrojemCifara (const vector<int> &v, int &brojParni, int &brojNeparni) {
    brojParni = 0;
    brojNeparni = 0;
    for (int i = 0; i < v.size(); i++) {
        int brojacCifara = 0;
        int broj = v[i];
        while (broj != 0) {
            brojacCifara++;
            broj /= 10;
        }
        if (brojacCifara % 2 == 0) {
            brojParni++;
        } else brojNeparni++;
    }
}

int main() {
    cout << "Unesite broj elemenata vektora: ";
    int n; cin >> n;
    vector<int>v;
    for (int i = 0; i < n; i++) {
        cout << "Unesite element[" << i + 1 << "]: ";
        int element; cin >> element;
        v.push_back(element);
        cout << endl;
    }

    int brojParni = 0, brojNeparni = 0;

    prebrojiElementeVektoraSaParnimNeparnimBrojemCifara(v, brojParni, brojNeparni);
    cout << "\nBroj elemenata sa parnim brojem cifara: " << brojParni;
    cout << "\nBroj elemenata sa neparnim brojem cifara: " << brojNeparni;
    return 0;
}