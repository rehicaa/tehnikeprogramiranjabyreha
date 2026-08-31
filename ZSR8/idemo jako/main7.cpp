#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>

using std::cout, std::cin, std::vector, std::string, std::endl;

template <typename TipElementa>
struct Matrica {
    char imeMatrice;
    int brRedova, brKolona;
    TipElementa **elementi = nullptr;
};

int main() {
    Matrica<int> m1;
    m1.imeMatrice = 'A';
    m1.brRedova = 3;
    m1.brKolona = 4;

    Matrica<int> m2;
    m2.imeMatrice = 'B';
    m2.brRedova = 4;
    m2.brKolona = 6;

    cout << "Matrica [" << m1.imeMatrice << "] " << "ima " << m1.brRedova << " redova i " << m1.brKolona << " kolona." << endl;
    cout << "Matrica [" << m2.imeMatrice << "] " << "ima " << m2.brRedova << " redova i " << m2.brKolona << " kolona." << endl;

    return 0;
}