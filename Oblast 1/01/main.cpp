//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

long long obrniBroj (long long n) {
    long long obrnuti = 0;
    while (n != 0) {
        obrnuti = obrnuti * 10 + (n % 10);
        n /= 10;
    }
    return obrnuti;
}

bool daLiJePalindrom (long long n) {
    if (n < 0) n = -n;
    return (n == obrniBroj(n));
}

vector<int>vratiPalindromskeOtpornosti(vector<int> v) {
    vector<int> rez;
    for (int i = 0; i < v.size(); i++) {
        long long broj = v[i];
        int brojac_koraka = 0;
        while (!daLiJePalindrom(broj)) {
            broj += obrniBroj(broj);
            brojac_koraka++;

            if (brojac_koraka > 100) break;
        }
        rez.push_back(brojac_koraka);
    }
    return rez;
}

int main() {
    vector<int> v1 = {195, 124, 256};
    vector<int> rez = vratiPalindromskeOtpornosti(v1);

    cout << "\nPalindromske otpornosti brojeva iz vektora: " << endl;
    for (int x : rez) {
        cout << x << " ";
    }
    return 0;
}