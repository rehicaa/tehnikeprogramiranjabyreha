#include <iostream>
#include <vector>
#include <array>
#include <stdexcept>

enum class TretmanNegativnih { IgnorirajZnak, Odbaci, PrijaviGresku };
typedef std::array<std::vector<long long int>, 10> matrica;

int MultiplikativniDigitalniKorijen(long long int n, int baza) {
    if (baza < 2) throw std::domain_error("Neispravna baza");
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

matrica RazvrstajBrojeve(std::vector<long long int> v, TretmanNegativnih tretman) {
    matrica rezultat;

    for (int i = 0; i < v.size(); i++) {
        long long int broj = v.at(i);

        if (broj < 0) {
            if (tretman == TretmanNegativnih::Odbaci) {
                continue;
            }
            if (tretman == TretmanNegativnih::PrijaviGresku) {
                throw std::domain_error("Nije predvidjeno razvrstavanje negativnih brojeva");
            }
        }
        int korijen = MultiplikativniDigitalniKorijen(broj, 10);
        rezultat.at(korijen).push_back(broj);
    }
    return rezultat;
}

int main() {
    std::cout << "Unesite brojeve (bilo koji ne-broj oznacava kraj): ";
    std::vector<long long int> unos;
    long long int privremeni;

    while (std::cin >> privremeni) {
        unos.push_back(privremeni);
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');

    try {
        matrica razvrstani = RazvrstajBrojeve(unos, TretmanNegativnih::PrijaviGresku);

        std::cout << "\nRezultati razvrstavanja po multiplikativnom digitalnom korijenu:" << std::endl;
        for (int i = 0; i < razvrstani.size(); i++) {
            if (razvrstani.at(i).size() > 0) {
                std::cout << i << ": ";
                for (int j = 0; j < razvrstani.at(i).size(); j++) {
                    std::cout << razvrstani.at(i).at(j) << (j == razvrstani.at(i).size() - 1 ? "" : " ");
                }
                std::cout << std::endl;
            }
        }
    }
    catch (std::domain_error) {
        std::cout << "\nNije podrzano razvrstavanje negativnih brojeva!" << std::endl;
    }
    return 0;
}