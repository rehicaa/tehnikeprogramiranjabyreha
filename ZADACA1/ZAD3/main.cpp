#include <iostream>
#include <deque>
#include <iomanip>
#include <stdexcept>

using std::cin, std::cout, std::endl, std::deque, std::setw, std::domain_error;

typedef deque<deque<int>> matricaDekDekova;

matricaDekDekova EkspanzijaMatrice(matricaDekDekova a, int p, int q) {
    if (p <= 0 || q <= 0) {
        throw domain_error("Nelegalni parametri");
    }

    if (a.size() > 0) {
        int broj_kolona = a.at(0).size();
        for (int i = 1; i < a.size(); i++) {
            if (a.at(i).size() != broj_kolona) {
                throw domain_error("Nekorektna matrica");
            }
        }
    }

    int m = a.size();
    int n = (m == 0) ? 0 : a.at(0).size();

    matricaDekDekova rezultat(m * p, deque<int>(n * q));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int vrijednost = a.at(i).at(j);

            for (int r = i * p; r < (i + 1) * p; r++) {
                for (int c = j * q; c < (j + 1) * q; c++) {
                    rezultat.at(r).at(c) = vrijednost;
                }
            }
        }
    }

    return rezultat;
}

int main() {
    int m, n;
    cout << "Unesite broj redova i kolona matrice: ";
    if (!(cin >> m >> n)) return 0;

    matricaDekDekova matrica(m, deque<int>(n));
    cout << "Unesite elemente matrice:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrica.at(i).at(j);
        }
    }

    int p, q;
    cout << "Unesite p i q: ";
    cin >> p >> q;

    try {
        matricaDekDekova ekspandirana = EkspanzijaMatrice(matrica, p, q);

        cout << endl << p << "x" << q << " ekspanzija zadane matrice glasi:" << endl;
        for (int i = 0; i < ekspandirana.size(); i++) {
            for (int j = 0; j < ekspandirana.at(i).size(); j++) {
                cout << setw(6) << ekspandirana.at(i).at(j);
            }
            cout << endl;
        }
    }
    catch (const domain_error &e) {
        cout << endl << "GRESKA: " << e.what() << "!" << endl;
    }
    return 0;
}