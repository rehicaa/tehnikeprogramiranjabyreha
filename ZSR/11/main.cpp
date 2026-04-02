//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string;

vector<int> vratiBrojrCifaraElemenataVektora (const vector<long long int> &v) {
    vector<int> rez;

    for (int i = 0; i < v.size(); i++) {
        long long int broj = v[i];
        if (broj < 0) throw std::domain_error("Broj ne smije biti negativan!");
        int brojac = 0;
        do {
            brojac++;
            broj /= 10;
        } while (broj != 0);
        rez.push_back(brojac);
    }

    return rez;
}

int main() {
    try {
        vector<long long int> v;
        for (int i = 0; i < 10; i++) {
            cout << "Unesite element[" << i + 1 << "]: ";
            long long int element; cin >> element; v.push_back(element);
        }

        vector<int>rez = vratiBrojrCifaraElemenataVektora(v);

        cout << endl;
        cout << "Rezultatni vektor: ";

        for (auto x : rez) {
            cout << x << " ";
        }


    } catch (std::domain_error &e) {
        cout << "Greska: " << e.what();
    }
    return 0;
}