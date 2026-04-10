#include <iostream>

using std::cin, std::cout, std::endl;
int main() {

    char recenica[1000];
    cout << "Unesite recenicu (do 1000 znakova): ";
    std::cin.getline(recenica, sizeof recenica);

    char *p = recenica;
    int brojRijeci = 0;

    while (*p != '\0') {
        while (*p == ' ') p++;
        if (*p != '\0'){
            brojRijeci++;
            while (*p != '\0' && *p != ' ') p++;
        }
    }

    brojRijeci == 0 ? cout << "Recenica ne sadrzi niti jednu rijec!" : cout << "Broj rijeci: " << brojRijeci;
    cout << endl;
    p = recenica;

    int trenutnaRijec = 0;
    int srednjaRijec = (brojRijeci + 1) / 2;

    while (*p != '\0') {
        while (*p == ' ') p++;
        if (*p != '\0') {
            trenutnaRijec++;
            if (trenutnaRijec == srednjaRijec) {
                cout << "Srednja rijec je: ";
                while (*p != '\0' & *p != ' ') {
                    cout << *p;
                    p++;
                }
                cout << endl;
                break;
            }
            while (*p != '\0' && *p != ' ') p++;
        }
    }

    return 0;
}