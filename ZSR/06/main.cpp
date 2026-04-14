#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

void vratiSumuCifaraVeceManjeOdPet (int n, int &manjeOdPet, int &veceOdPet) {
    int broj = std::abs (n);
    manjeOdPet = 0;
    veceOdPet = 0;
    while (broj != 0) {
        int cifra = broj % 10;
        if (cifra < 6) {
            manjeOdPet += cifra;
        } else {
            veceOdPet += cifra;
        }
        broj /= 10;
    }
}

int main () {
    cout << "Unesite broj: ";
    int n; cin >> n;

    int manjeOdPet = 0, veceOdPet = 0;
    vratiSumuCifaraVeceManjeOdPet(n, manjeOdPet, veceOdPet);
    cout << "\nSuma cifara koje su manje od pet je: " << manjeOdPet;
    cout << "\nSuma cifara koje su vece od pet je: " << veceOdPet;
    return 0;
}