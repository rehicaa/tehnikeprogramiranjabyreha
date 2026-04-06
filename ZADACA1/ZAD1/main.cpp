#include <iostream>
#include <vector>
#include <array>
#include <stdexcept>

using std::cin, std::cout, std::endl, std::vector, std::array, std::domain_error;

enum class TretmanNegativnih {IgnorirajZnak, Odbaci, PrijaviGresku};
typedef array<vector<long long int>, 10> matrica;

int MultiplikativniDigitalniKorijen(long long int n, int baza) {
    if (baza < 2) throw domain_error("Neispravna baza");
    if (n < 0) n = -n;
    while (n >= baza) {
        long long int proizvod = 1;
        long long int pomocni = n;
        if (pomocni == 0) proizvod = 0;

        while (pomocni > 0) {
            proizvod *= (pomocni % baza);
            pomocni /= baza;
        }
        n = proizvod;
    }
    return static_cast<int>(n);
}

matrica RazvrstajBrojeve(vector<long long int> v, TretmanNegativnih tretman) {
    matrica rezultat;

    for (int i = 0; i < v.size(); i++) {
        long long int broj = v.at(i);

        if (broj < 0) {
            if (tretman == TretmanNegativnih::Odbaci) {
                continue;
            }
            if (tretman == TretmanNegativnih::PrijaviGresku) {
                throw domain_error("Nije predvidjeno razvrstavanje negativnih brojeva");
            }
            if (tretman == TretmanNegativnih::IgnorirajZnak) {
                broj = -broj;
            }
        }
        int korijen = MultiplikativniDigitalniKorijen(broj, 10);
        rezultat.at(korijen).push_back(v.at(i));
    }
    return rezultat;
}

int main() {
    cout << "Unesite brojeve (bilo koji ne-broj oznacava kraj): ";
    vector<long long int> unos;
    long long int privremeni;

    while (cin >> privremeni) {
        unos.push_back(privremeni);
    }
    cin.clear();
    cin.ignore(10000, '\n');

    try {
        matrica razvrstani = RazvrstajBrojeve(unos, TretmanNegativnih::PrijaviGresku);

        cout << "\nRezultati razvrstavanja po multiplikativnom digitalnom korijenu:" << endl;
        for (int i = 0; i < razvrstani.size(); i++) {
            if (razvrstani.at(i).size() > 0) {
                cout << i << ": ";
                for (int j = 0; j < razvrstani.at(i).size(); j++) {
                    cout << razvrstani.at(i).at(j) << (j == razvrstani.at(i).size() - 1 ? "" : " ");
                }
                cout << endl;
            }
        }
    }
    catch (const domain_error &) {
        cout << "\nNije podrzano razvrstavanje negativnih brojeva!" << endl;
    }
    return 0;
}