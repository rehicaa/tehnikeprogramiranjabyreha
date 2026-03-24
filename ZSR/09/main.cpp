//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl, std::vector, std:: string;

bool imaLiParnihBrojeva (const vector<int> &v) { //CONST REFERNCE SU KORISNE JER NAM GARANTUJU DA NECEMO PROMIJENITI NISTA U VEKTORU
    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 0) return true;
    }

    return false;
}

int main() {

    cout << "Unesite zeljenu velicinu niza: ";
    int velicinaNiza; cin >> velicinaNiza;

    vector<int> v1;
    for (int i = 0; i < velicinaNiza; i++) {
        cout << "Unesite element niza: ";
        int element; cin >> element;
        v1.push_back(element);
    }

    if (imaLiParnihBrojeva(v1)) {
        cout << "U unesenom nizu postoji barem jedan parni broj.";
    } else {
        cout << "U unesenom nizu ne postoji niti jedan parni broj.";
    }

    return 0;
}