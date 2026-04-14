#include <iostream>
#include <cctype>
using std::cout, std::cin, std::endl, std::vector;

void sumaCifara (int n, int &s_par, int &s_nepar) {
    int broj = std::abs(n);
    while (broj != 0) {
        int cifra = broj % 10;
        if (cifra % 2 == 0) {
            s_par += cifra;
        } else {
            s_nepar += cifra;
        }
        broj /= 10;
    }
}

int main() {
    int n;
    do {
        cout << "\nUnesite broj: "; cin >> n;
        if (n < 0) break;
        int sumaParnih = 0, sumaNeparnih = 0;
        sumaCifara(n, sumaParnih, sumaNeparnih);
        cout << "\nSuma parnih cifara broja je: " << sumaParnih;
        cout << "\nSuma neparnih cifara broja je: " << sumaNeparnih;
    } while (n != 0);
    return 0;
}