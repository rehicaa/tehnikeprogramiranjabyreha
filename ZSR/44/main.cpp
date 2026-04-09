#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <cctype>

using std::cout, std::cin, std::endl, std::vector, std::string;

int main() {
    cout << "Unesite recenicu: ";
    string s;
    std::getline(cin, s);

    int brojacSlova = 0;
    int brojacRijeci = 0;
    bool unutarRijeci = false;

    cout << "\nRijeci u recenici:" << endl;

    for (int i = 0; i < s.size(); i++) {
        char trenutni = s.at(i);

        if (trenutni != ' ') {
            if (!unutarRijeci) {
                brojacRijeci++;
                unutarRijeci = true;
            }

            cout << trenutni;

            if (std::isalpha(trenutni)) {
                brojacSlova++;
            }
        }
        else {
            if (unutarRijeci) {
                cout << endl;
                unutarRijeci = false;
            }
        }
    }

    if (unutarRijeci) cout << endl;

    cout << "\nBrojac slova: " << brojacSlova << endl;
    cout << "Brojac rijeci: " << brojacRijeci << endl;

    return 0;
}