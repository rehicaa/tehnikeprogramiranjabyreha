//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;
typedef vector<vector<double> > matrica;

matrica unesiMatricu() {
    cout << "Unesite broj redova: ";
    int brRedova;
    cin >> brRedova;
    matrica mat(brRedova);
    for (int i = 0; i < brRedova; i++) {
        cout << "Koliko elemenata ima u redu[" << i + 1 << "]: ";
        int brKolona;
        cin >> brKolona;
        for (int j = 0; j < brKolona; j++) {
            cout << "Element[" << i + 1 << ", " << j + 1 << "]: ";
            double element;
            cin >> element;
            mat[i].push_back(element);
        }
    }
    return mat;
}

void ispisiMatricu(const matrica &m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            cout << std::setw(5) << m.at(i).at(j);
        }
        cout << endl;
    }
}

bool daLiJeCirkulatorna(const matrica &m) {
    if (m.empty()) return true;
    if (m.size() != m[0].size()) return false;
    for (int i = 1; i < m.size(); i++) {
        if (m[i].size() != m[0].size()) return false;
    }

    for (int i = 1; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            if (j == 0) {
                if (m.at(i).at(0) != m.at(i - 1).at(m.size() - 1)) return false;
            } else {
                if (m.at(i).at(j) != m.at(i - 1).at(j - 1)) return false;
            }
        }
    }
    return true;
}

int main() {
    matrica mat = unesiMatricu();
    ispisiMatricu(mat);
    daLiJeCirkulatorna(mat) ? cout << "\nMatrica je cirkulantna!" : cout << "\nMatrica nije cirkulantna!";
    return 0;
}
