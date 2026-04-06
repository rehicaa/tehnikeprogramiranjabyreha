#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica MedijanskiFilter(Matrica m, int n) {
    if (n < 0) throw std::domain_error("Neispravan red filtriranja");

    Matrica rezultat(m.size());
    for (int i = 0; i < m.size(); i++) {
        rezultat.at(i).resize(m.at(i).size());
    }

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.at(i).size(); j++) {

            std::vector<double> prozor;
            for (int r = i - n; r <= i + n; r++) {
                if (r < 0 || r >= m.size()) continue;

                for (int c = j - n; c <= j + n; c++) {
                    if (c < 0 || c >= m.at(r).size()) continue;
                    prozor.push_back(m.at(r).at(c));
                }
            }

            for (int k = 0; k < prozor.size(); k++) {
                for (int l = k + 1; l < prozor.size(); l++) {
                    if (prozor.at(l) < prozor.at(k)) {
                        double pomocna = prozor.at(k);
                        prozor.at(k) = prozor.at(l);
                        prozor.at(l) = pomocna;
                    }
                }
            }

            double medijan;
            int vel = prozor.size();
            if (vel % 2 != 0) {
                medijan = prozor.at(vel / 2);
            } else {
                medijan = (prozor.at(vel / 2 - 1) + prozor.at(vel / 2)) / 2.0;
            }
            rezultat.at(i).at(j) = medijan;
        }
    }
    return rezultat;
}

int main() {
    int redova, kolona;
    std::cout << "Unesite broj redova i kolona matrice: ";
    if (!(std::cin >> redova >> kolona)) return 0;

    Matrica m(redova, std::vector<double>(kolona));
    std::cout << "Unesite elemente matrice: " << std::endl;
    for (int i = 0; i < redova; i++) {
        for (int j = 0; j < kolona; j++) {
            std::cin >> m.at(i).at(j);
        }
    }

    int n;
    std::cout << "Unesite red filtriranja: ";
    std::cin >> n;

    try {
        Matrica filtrirana = MedijanskiFilter(m, n);
        std::cout << std::endl << "Matrica nakon filtriranja:" << std::endl;
        for (int i = 0; i < filtrirana.size(); i++) {
            for (int j = 0; j < filtrirana.at(i).size(); j++) {
                std::cout << std::setw(7) << std::fixed << std::setprecision(2) << filtrirana.at(i).at(j);
            }
            std::cout << std::endl;
        }
    }
    catch (std::domain_error &e) {
        std::cout << std::endl << "GRESKA: " << e.what() << "!" << std::endl;
    }
    return 0;
}