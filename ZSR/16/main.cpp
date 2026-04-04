//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <complex>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error, std::complex;
typedef vector<vector<double>> matrica;

matrica kreirajMatricu (int brRedova, int brKolona) {
    return matrica (brRedova, vector<double>(brKolona));
}

matrica unesiMatricu (int brRedova, int brKolona) {
    auto m = kreirajMatricu(brRedova, brKolona);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            cout << "Element[" << i + 1 << ", " << j + 1 << "]: ";
            cin >> m.at(i).at(j);
        }
    }
    return m;
}

void ispisiMatricu (matrica m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            cout << std::setw(6) << m.at(i).at(j);
        }
        cout << endl;
    }
}

matrica modifikujMatricu (matrica &m, complex<double>&x) {
    double min = 0, max = 0;
    int indexMin = 0, indexMax = 0;

    if (m.empty()) return {{0, 0}, {0, 0}};
    for (int i = 0; i < m.size(); i++) {
        if (m[i].size() != m[0].size()) throw domain_error("Matrica nema isti broj elemenata u redovima!");
    }

    for (int i = 0; i < m.size(); i++) {
        double suma = 0;
        for (int j = 0; j < m[0].size(); j++) {
            suma += m.at(i).at(j);
        }
        cout << "Suma reda " << i + 1 << " je: " << suma << endl;
        if (i == 0) {
            min = max = suma;
        } else {
            if (suma > max) {
                max = suma;
                indexMax = i;
            }
            if (suma < min) {
                min = suma;
                indexMin = i;
            }
        }
    }
    x.real(max); x.imag(min);

    for (int i = 0; i < m[0].size(); i++) {
        double temp = m.at(indexMax).at(i);
        m.at(indexMax).at(i) = m.at(indexMin).at(i);
        m.at(indexMin).at(i) = temp;
    }
    return m;
}

int main() {
    try {
        cout << "Unesite broj redova i kolone matrice respektivno: ";
        int brRed, brKol; cin >> brRed >> brKol;
        auto m = unesiMatricu(brRed, brKol);
        ispisiMatricu(m);
        complex<double> x;
        modifikujMatricu(m, x);
        cout << endl;
        ispisiMatricu(m);
        cout << x.real() << " " << x.imag() << endl;
    } catch (const domain_error &e) {
        cout << "GRESKA: " << e.what() << endl;
    }
    return 0;
}