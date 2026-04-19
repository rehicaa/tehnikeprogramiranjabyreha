//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;
typedef vector<vector<double>> matrica;
matrica unesiMatricu() {
    cout << "Unesite broj redova: ";
    int brRedova; cin >> brRedova;
    matrica mat(brRedova);
    for (int i = 0; i < brRedova; i++) {
        cout << "Koliko elemenata u redu[" << i + 1 << "]: ";
        int brKolona; cin >> brKolona;
        for (int j = 0; j < brKolona; j++) {
            cout << "Unesite element[" << i + 1 << ", " << j + 1 << "]: ";
            double element; cin >> element;
            mat[i].push_back(element);
        }
    }
    return mat;
}

void ispisiMatricu (const matrica &m) {
    cout << "\nVasa matrica: " << endl;
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            cout << std::setw(5) << m.at(i).at(j);
        }
        cout << endl;
    }
}

vector<double> transformisiMatricu (matrica &m) {
    if (m.empty()) throw domain_error ("Matrica je prazna.");
    for (int i = 1; i < m.size(); i++) {
        if (m[i].size() != m[0].size()) throw domain_error ("Matrica nema pravilnu formu!");
    }
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size() / 2; j++) {
            double temp = m.at(i).at(j);
            m.at(i).at(j) = m.at(i).at(m[i].size() - 1 - j);
            m.at(i).at(m[i].size() - 1 - j) = temp;
        }
    }

    vector<double>rez;
    for (int j = 0; j < m[0].size(); j++) {
        double suma = 0;
        for (int i = 0; i < m.size(); i++) {
            suma += m.at(i).at(j);
        }
        rez.push_back(suma);
    }
    return rez;
}
int main() {
    try {
        matrica mat = unesiMatricu();
        ispisiMatricu(mat);
        vector<double> sumaKolona = transformisiMatricu(mat);
        ispisiMatricu(mat);

        cout << "\nSume kolona: " << endl;
        for (auto x : sumaKolona) {
            cout << x << " ";
        }
    } catch (std::domain_error &e) {
        cout << "Greska: " << e.what() << endl;
    }
    return 0;
}