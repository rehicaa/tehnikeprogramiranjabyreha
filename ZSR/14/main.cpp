//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <stdexcept>
#include <complex>
#include <iomanip>

using std::cout, std::cin, std::endl, std::vector, std::string, std::complex;
typedef vector<vector<double>> matrica;
matrica kreirajMatricu (int brojRedova, int brojKolona) {
    return matrica(brojRedova, vector<double>(brojKolona));
}

matrica unesiMatricu (int brojRedova, int brojKolona) {
    auto m = kreirajMatricu(brojRedova, brojKolona);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            cout << "Element[" << i + 1 << ", " << j + 1 << "]: ";
            cin >> m.at(i).at(j);
        }
    }
    return m;
}

void ispisiMatricu (matrica m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            cout << std::setw(5) << m.at(i).at(j);
        }
        cout << endl;
    }
}

complex<double> transformirajMatricu (matrica &m) {
    complex<double> rez;

    double min= 0, max = 0;
    int indexMax = 0, indexMin = 0;

    if (m.empty()) return {0, 0};
    for (int i = 0; i < m.size(); i++) {
        if (m[i].size() != m[0].size()) throw std::domain_error ("Matrica nema isti broj elemenata po redovima!");
    }

    for (int i = 0; i < m[0].size(); i++) {
        double proizvod = 1;
        for (int j = 0; j < m.size(); j++) {
            proizvod *= m.at(j).at(i); //proizvod finalni kolone i,j
        }
        if (i == 0) {
            min = max = proizvod;
        } else {
            if (proizvod > max) {
                indexMax = i;
                max = proizvod;
            }
            if (proizvod < min) {
                indexMin = i;
                min = proizvod;
            }
        }
        cout << "Proizvod kolone " << i + 1 << " je: " << proizvod << endl;
    }

    cout << endl;

    rez.real(min);
    rez.imag(max);

    for (int i = 0; i < m.size(); i++) {
            double temp = m.at(i).at(indexMax);
            m.at(i).at(indexMax) = m.at(i).at(indexMin);
            m.at(i).at(indexMin) = temp;
    }

    return rez;
}

int main() {
    try {
        cout << "Unesite broj redova i kolona matrice: ";
        int brRed, brKol; cin >> brRed >> brKol;

        auto m = unesiMatricu(brRed, brKol);
        ispisiMatricu(m);
        cout << transformirajMatricu(m) << endl;
        ispisiMatricu(m);
    } catch (const std::domain_error &e) {
        cout << "GRESKA: " << e.what() << endl;
    }
    return 0;
}