#include <iostream>
using std::cout, std::cin, std::endl;

int multOtpornost (int n) {
    int brojac = 0;

    while (n >= 10) {
        int noviBroj = 1;
        int pomocniBroj = n;
        while (pomocniBroj > 0) {
            int cifra = pomocniBroj % 10;
            noviBroj *= cifra;
            pomocniBroj /= 10;
        }
        n = noviBroj;
        brojac++;
    }
    return brojac;
}

int main() {
cout << "Unesite granice a i b: ";
    int a, b; cin >> a >> b;
    cout << "Unesite trazenu otpornost: ";
    int otpornost; cin >> otpornost;
    for (int i = a; i <=b; i++) {
        if (multOtpornost(i) == otpornost) {
            cout << i << " ";
        }
    }

    return 0;
}