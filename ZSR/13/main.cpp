//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl, std::vector, std::string;

bool imaLiBrojevaStepenaDva (const vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        int broj = 1;
        while (broj < v[i]) {
            broj *= 2;
        }
        if (broj == v[i]) return true;
    }

    return false;
}

int main() {
    cout << "Unesite broj elemenata niza: ";
    int n; cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        cout << "Unesite element [" << i + 1 << "]: ";
        int element; cin >> element;
        v.push_back(element);
    }



    if (imaLiBrojevaStepenaDva(v)) {
        cout << "U ovom vektoru: " << endl;
        for (const auto el : v) {
            cout << el << " ";
        }
        cout << endl;
        cout << "postoji barem jedan broj ciji je stepen broj 2.";

    } else {
        cout << "U ovom vektoru: " << endl;
        for (const auto el : v) {
            cout << el << " ";
        }
        cout << endl;
        cout << "ne postoji niti jedan broj ciji je stepen broj 2.";
    }
    return 0;
}