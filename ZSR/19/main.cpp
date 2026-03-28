//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl, std::vector, std::string;

vector<int> vratiBrojCifaraElemenata (vector<int> &v) {
    vector<int>rez;
    for (int i = 0; i < v.size(); i++) {
        int brojacCifara = 0;
        int broj = v[i];
        do {
            brojacCifara++;
            broj /= 10;
        } while (broj != 0);
        rez.push_back(brojacCifara);
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

    vector<int>v2 = vratiBrojCifaraElemenata(v1);

    for (int x : v2) {
        cout << x << " ";
    }


    return 0;
}