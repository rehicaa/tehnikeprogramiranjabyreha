#include <iostream>
using std::cout, std::cin, std::endl;

bool daLiJeSimetrican(int n) {
    int kopijaN = n;
    int noviBroj = 0;
    bool jeSimetrican = false;
    while (kopijaN > 0) {
        int zadnjaCifra = kopijaN % 10;
        noviBroj = noviBroj * 10 + zadnjaCifra;
        kopijaN /= 10;
    }
    if (noviBroj == n) jeSimetrican = true;

    return jeSimetrican;
}

int main() {
    for (;;) {
        cout << "Unesite broj: ";
        int n; cin >> n;

        if (n == 0) break;

        if (daLiJeSimetrican(n)) {
            cout << "Broj koji ste unijeli je simetrican.";
        } else cout << "Broj koji ste unijeli nije simetrican.";
        cout << endl;
    }

    return 0;
}