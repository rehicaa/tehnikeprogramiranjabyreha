#include <iostream>
#include <vector>
using std::cout, std:: cin, std::endl, std::vector;

bool imaLiJednakihCifara (int n) {
    bool vidjeneCifre[10] = {false};
    while (n > 0) {
        int zadnjaCifra = n % 10;
        if (vidjeneCifre[zadnjaCifra] == true) {
            return true;
        }

        vidjeneCifre[zadnjaCifra] = true;
        n /= 10;
    }

    return false;
}


int main() {
    cout << "Unesite broj: ";
    int n; cin >> n;

    if (imaLiJednakihCifara(n)) {
        cout << "Broj sadrzi barem dvije jednake cifre.";
    } else {
        cout << "Broj ne sadrzi niti jednu jednaku cifru.";
    }

    return 0;
}