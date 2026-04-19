//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;
int multOtp (int n) {
    int broj = std::abs(n);
    int koraci = 0;
    while (broj >= 10) {
        int proizvodCifara = 1;
        while (broj != 0) {
            int cifra = broj % 10;
            proizvodCifara *= cifra;
            broj /= 10;
        }
        broj = proizvodCifara;
        koraci++;
    }
    return koraci;
}
vector<int> izdvojiElementeMulitplOtpornosti (vector<int> v, int prag) {
    vector<int>rez;
    for (int i = 0; i <v.size(); i++) {
        if (multOtp(v[i]) == prag) rez.push_back(v[i]);
    }
    return rez;
}

int main() {
    vector<int>v = {2432, 421, 23412, 4213, 23};
    vector<int>rez = izdvojiElementeMulitplOtpornosti(v, 3);
    for (auto x : rez) {
        cout << x << " ";
    }
    return 0;
}