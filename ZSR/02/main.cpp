#include <iostream>
#include <vector>

using std::cout, std::cin, std::endl, std::vector;

bool daLiImaJednakihCifara (int n) {
    vector<int>cifre;
    while (n > 0) {
        cifre.push_back(n % 10);
        n /= 10;
    }

    for (int i = 0; i < cifre.size(); i++) {
        for (int j = i + 1; j < cifre.size(); j++) {
            if (cifre[i] == cifre[j]) return true;
        }
    }

    return false;
}

int main() {

    cout << "Unesite broj: ";
    int n; cin >> n;

    if (daLiImaJednakihCifara(n)) {
        cout << "Broj koji ste unijeli sadrzi barem dvije jednake cifre.";
    } else cout << "Broj koji ste unijeli ne sadrzi niti jednu jednaku cifru.";
}