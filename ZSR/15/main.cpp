#include <iostream>
using std::cout, std::cin, std::endl;

int izbaciNule (int n) {
    int trenutniBroj = n;
    int noviBroj = 0;
    int multiplikator = 1;
    while (trenutniBroj > 0) {
        int zadnjaCifra = trenutniBroj % 10;
        if (zadnjaCifra != 0) {
            noviBroj += zadnjaCifra * multiplikator;
             multiplikator *= 10;
        }
        trenutniBroj /= 10;
    }

    return noviBroj;
}

int main () {
    int broj;
    do {
        cout << "Unesite broj: ";
        cin >> broj;
        cout << izbaciNule(broj);
        cout << endl;
    } while (broj != 0);

    return 0;
}