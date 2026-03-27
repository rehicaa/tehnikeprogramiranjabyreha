//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl, std::vector, std::string;

vector<int>vratiStepeneBrojaDva (const int n) {
    vector<int>rez;
        int broj = 1;
        while (broj < n) {
            rez.push_back(broj);
            broj *= 2;
        }
    return rez;
}

int main() {

    cout << "Unesite broj: ";
    int n;
    if (!(cin >> n) || n <= 0) {
        cout << "Unijeli ste pogresan podatak." << endl;
        return 0;
    }

    vector<int> v = vratiStepeneBrojaDva(n);
    for (auto x: v) {
        cout << x << " ";
    }
    return 0;
}