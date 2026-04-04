#include <iostream>
#include <deque>
#include <iomanip>
#include <stdexcept>

typedef std::deque<std::deque<int>> matricaDekDekova;

matricaDekDekova EkspanzijaMatrice(matricaDekDekova a, int p, int q) {
    if (p <= 0 || q <= 0) {
        throw std::domain_error("Nelegalni parametri");
    }

    if (a.size() > 0) {
        int broj_kolona = a.at(0).size();
        for (int i = 1; i < a.size(); i++) {
            if (a.at(i).size() != broj_kolona) {
                throw std::domain_error("Nekorektna matrica");
            }
        }
    }

    int m = a.size();
    int n = (m == 0) ? 0 : a.at(0).size();

    matricaDekDekova rezultat(m * p, std::deque<int>(n * q));

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
    std::cout << "Unesite broj redova i kolona matrice: ";
    if (!(std::cin >> m >> n)) return 0;

    matricaDekDekova matrica(m, std::deque<int>(n));
    std::cout << "Unesite elemente matrice:" << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrica.at(i).at(j);
        }
    }

    int p, q;
    std::cout << "Unesite p i q: ";
    std::cin >> p >> q;

    try {
        matricaDekDekova ekspandirana = EkspanzijaMatrice(matrica, p, q);

        std::cout << std::endl << p << "x" << q << " ekspanzija zadane matrice glasi:" << std::endl;
        for (int i = 0; i < ekspandirana.size(); i++) {
            for (int j = 0; j < ekspandirana.at(i).size(); j++) {
                std::cout << std::setw(6) << ekspandirana.at(i).at(j);
            }
            std::cout << std::endl;
        }
    }
    catch (std::domain_error e) {
        std::cout << std::endl << "GRESKA: " << e.what() << "!" << std::endl;
    }
    return 0;
}