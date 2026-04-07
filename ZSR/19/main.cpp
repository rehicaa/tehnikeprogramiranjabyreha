//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;
typedef vector<vector<int>> matrica;

matrica kreirajMatricu (int brRedova, int brKolona) {
    return matrica (brRedova, vector<int>(brKolona));
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

void ispisiMatricu (const matrica &m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            cout << std::setw(6) << m.at(i).at(j);
        }
        cout << endl;
    }
}

bool jeLiMatricaIdempotentna (const matrica &m) {
    if (m.empty()) return true;
    if (m.size() != m[0].size()) return false;
    for (int i = 0; i < m.size(); i++) {
        if (m[i].size() != m[0].size()) return false;
    }

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            int suma = 0;
            for (int k = 0; k < m.size(); k++) {
                suma += m.at(i).at(k) * m.at(k).at(j);
            }
            if (suma != m.at(i).at(j)) return false;
        }
    }
    return true;
}


int main() {
    cout << "Unesite parametre matrice n x m (mora biti kvadratna): ";
    int n, m; cin >> n >> m;
    const auto m1 = unesiMatricu(n, n);
    cout << endl << "Vasa matrica: " << endl;
    ispisiMatricu(m1);
    cout << endl;
    jeLiMatricaIdempotentna(m1) ? cout << "Matrica je idempotentna." : cout << "Matrica nije idempotentna.";

    return 0;
}