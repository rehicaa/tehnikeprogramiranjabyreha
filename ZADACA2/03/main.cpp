#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <iterator>
#include <algorithm>

using std::cout, std::cin, std::endl, std::vector, std::string, std::setw, std::left;

template <typename Kontejner1, typename Kontejner2, typename Funkcija>
auto GeneraliziraniSpoljasnjiProizvod(Kontejner1 kont1, Kontejner2 kont2, Funkcija f) {
    typedef decltype(f(*std::begin(kont1), *std::begin(kont2))) TipRezultata;
    vector<vector<TipRezultata>> matrica;

    if (std::begin(kont1) == std::end(kont1) || std::begin(kont2) == std::end(kont2)) {
        return matrica;
    }

    for (const auto &x : kont1) {
        vector<TipRezultata> red;
        for (const auto &y : kont2) {
            red.push_back(f(x, y));
        }
        matrica.push_back(red);
    }
    return matrica;
}

int main() {
    int m, n;

    cout << "Unesite broj elemenata prve sekvence: ";
    cin >> m;
    vector<string> s1(m);
    cout << "Unesite elemente prve sekvence: ";
    for (auto &s : s1) cin >> s;

    cout << "Unesite broj elemenata druge sekvence: ";
    cin >> n;
    vector<string> s2(n);
    cout << "Unesite elemente druge sekvence: ";
    for (auto &s : s2) cin >> s;

    auto rezultat = GeneraliziraniSpoljasnjiProizvod(s1, s2, [](string x, string y) {
        return x + y;
    });

    if (rezultat.empty()) return 0;

    int max_duzina = 0;
    for (const auto &red : rezultat) {
        for (const auto &s : red) {
            if (s.length() > max_duzina) max_duzina = s.length();
        }
    }

    cout << endl;
    for (const auto &red : rezultat) {
        for (const auto &s : red) {
            cout << left << setw(max_duzina + 1) << s;
        }
        cout << endl;
    }

    return 0;
}