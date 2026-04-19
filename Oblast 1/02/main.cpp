//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

bool sumaCifaraParna (int n) {
    int broj = n;
    int suma = 0;
    while (broj != 0) {
        int cifra = broj % 10;
        suma += cifra;
        broj /= 10;
    }
    return (suma % 2 == 0);
}

vector<int> izbaciElementeSaParnimSumamaCifara (vector<int> &v) {
    int j = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!sumaCifaraParna(v[i])) {
            v[j] = v[i];
            j++;
        }
    }   
    v.resize(v.size() - j);
    return v;
}

int main() {
    vector<int>v1 = {17, 23, 43, 44};
    izbaciElementeSaParnimSumamaCifara(v1);
    cout << "\nNakon modifikacije: " << endl;
    for (auto x : v1) {
        cout << x << " ";
    }
    return 0;
}