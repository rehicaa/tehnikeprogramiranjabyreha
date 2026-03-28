//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl, std::vector, std::string;

vector<int> vratiDjeljiveTroceifreBrojeveBrojem(const int n) {
    vector<int> rez;
    for (int i = 100; i <= 999; i++) {
        if (i % n == 0) {
            rez.push_back(i);
        }
    }

    return rez;
}

int main() {
    cout << "Unesite broj: ";
    int n; if (!(cin >> n) || n <= 0) {
        cout << "Unijeli ste pogresan podatak.";
        return 1;
    }

    const vector<int>v = vratiDjeljiveTroceifreBrojeveBrojem(n);
    for (const auto el: v) {
        cout << el << " ";
    }

    return 0;
}