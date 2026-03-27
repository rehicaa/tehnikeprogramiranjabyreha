//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl, std::vector, std::string;

vector<int> vratiPotpuneKvadrateDoParametra (int n) {
    vector<int>rez;
    for (int i = 1; i * i < n; i++) {
        rez.push_back(i * i);
    }

    return rez;
}

int main() {
    cout << "Unesite broj: ";
    int n; cin >> n;

    vector<int>v = vratiPotpuneKvadrateDoParametra(n);
    for (const int x: v) {
        cout << x << " ";
    }
    return 0;
}