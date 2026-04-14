#include <iostream>
#include <cmath>
using std::cin, std::cout, std::endl;

void razdvojiCifre (int n, int &parni, int &neparni) {
    int broj = std::abs(n);
    parni = 0;
    neparni = 0;
    int stepenParni = 1;
    int stepenNeparni = 1;
    while (broj != 0) {
        int cifra = broj % 10;
        if (cifra % 2 == 0) {
            parni += (cifra * stepenParni);
            stepenParni *= 10;
        } else {
            neparni += (cifra * stepenNeparni);
            stepenNeparni *= 10;
        }
        broj /= 10;
    }
}

int main() {
    cout << "Unesite broj: ";
    int n; cin >> n;

    int parni = 0, neparni = 0;
    razdvojiCifre(n, parni, neparni);
    cout << "\nNovi broj od parnih cifara: " << parni;
    cout << "\nNovi broj od neparnih cifara: " << neparni;

    return 0;
}