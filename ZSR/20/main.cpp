//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl, std::vector, std::string;

vector<int> vratiVektorCijiSuElementiSumeCifaraVektora(vector<int> &v) {
    vector<int>rez;
    for (int i = 0; i < v.size(); i++) {
        int finalnaCifra = 0;
        int broj = v[i];
        do {
            int trenutnaCifra = broj % 10;
            finalnaCifra += trenutnaCifra;
            broj /= 10;
        } while (broj != 0);
        rez.push_back(finalnaCifra);
    }

    return rez;
}

int main() {
    cout << "Unesite broj elemenata vektora: ";
    int brojElemenata; if (!(cin >> brojElemenata) || brojElemenata <= 0) {
        cout << "Netačan unos podataka.";
        return 1;
    }
    vector<int>v1;
    for (int i = 0; i < brojElemenata; i++) {
        cout << "Element[" << i + 1 << "]: ";
        int elementVektora; cin >> elementVektora;
        v1.push_back(elementVektora);
    }

    vector<int>v2 = vratiVektorCijiSuElementiSumeCifaraVektora(v1);

    for (int el: v2) {
        cout << el << " ";
    }
    return 0;
}