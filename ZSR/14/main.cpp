//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl, std::vector, std::string;

vector<int> vratiDjelioceBroja (int n) {
    vector<int>rezultat;
    for (int i = 1; i <= n; i++) {
        if (n % i ==0) {
            rezultat.push_back(i);
        }
    }

    return rezultat;
}

int main() {

    cout << "Unesite broj kojem zelite pronaci djelioce: ";
    int n; cin >> n;

    const vector<int> v = vratiDjelioceBroja(n);

    for (const auto element: v) {
        cout << element << " ";
    }

    return 0;
}