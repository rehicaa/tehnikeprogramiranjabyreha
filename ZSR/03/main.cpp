#include <iostream>
#include <vector>
using std::cout, std::cin, std::endl, std::vector;

bool imaLiBaremDvijeCifreZaredom (int n) {
    int broj = n;
    vector<int> cifre;
    while (broj != 0) {
        int cifra = broj % 10;
        cifre.push_back(cifra);
        broj /= 10;
    }

    for (int i = 0; i < cifre.size() - 1; i++) {
        if (cifre[i] == cifre [i + 1]) return true;
    }


    return false;
}

int main() {

    cout << "Unesite broj: ";
    int n; cin >> n;

    if (imaLiBaremDvijeCifreZaredom(n)) {
        cout << "Broj sadrzi barem dvije jednake uzastopne cifre.";
    } else {
        cout << "Broj ne sadrzi barem dvije jednake uzastopne cifre.";
    }

    return 0;
}