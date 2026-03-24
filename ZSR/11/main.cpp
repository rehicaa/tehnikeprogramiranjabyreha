//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl, std::vector, std::string;

vector<double> obrniNizIVratiUFormiVektora (double niz[], const int brojElemenata) {
    vector<double>rezultat;
    for (int i = brojElemenata - 1; i >= 0; i--) {
        rezultat.push_back(niz[i]);
    }

    return rezultat;
}

int main() {
    const int kapacitetNiza = 10;
    double niz1[kapacitetNiza];
    for (int i = 0; i < kapacitetNiza; i++) {
        cout << "Unesite element niza: ";
        cin >> niz1[i];
    }

    cout << "Originalni niz: " << endl;

    for (int i = 0; i < kapacitetNiza; i++) {
        cout << niz1[i] << " ";
    }

    cout << endl;

    cout << "Obrnuti vektor: " << endl;
    vector<double> v1 = obrniNizIVratiUFormiVektora(niz1, kapacitetNiza);
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }

    cout << endl;


    return 0;
}