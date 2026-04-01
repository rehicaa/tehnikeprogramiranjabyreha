//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl, std::vector, std::string;

vector<int> vratiNajmanjuCifruElementaVektora(vector<int> &v) {
    vector<int> rez;
    for (int i = 0; i < v.size(); i++) {
        int minCifra = 9;
        int broj = v[i];
        if (broj < 0) broj = -broj;
        do {
            int trenutnaCifra = broj % 10;
            if (trenutnaCifra < minCifra) {
                minCifra = trenutnaCifra;
            }
            broj /= 10;
        } while (broj != 0);
        rez.push_back(minCifra);
    }

    return rez;
}

int main() {
    cout << "Unesite broj elemenata vektora: ";
    int x; if (!(cin >> x) || x <= 0) {
        cout << "Neispravan unos!";
        return 1;
    }

    vector<int>v1;
    for (int i = 0; i < x; i++) {
        cout << "Unesite element[" << i + 1 << "]: ";
        int element; cin >> element; v1.push_back(element);
    }

    vector<int> v2 = vratiNajmanjuCifruElementaVektora(v1);
    for (auto x : v2) {
        cout << x << " ";
    }

    return 0;
}