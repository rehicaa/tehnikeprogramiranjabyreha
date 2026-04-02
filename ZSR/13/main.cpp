//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;
typedef vector<vector<bool>> Matrica;
Matrica kreirajMatricu (int brojRedova, int brojKolona) {
    return Matrica(brojRedova, vector<bool>(brojKolona));
}
Matrica unesiMatricu (int brojRedova, int brojKolona) {
    auto m = kreirajMatricu(brojRedova, brojKolona);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            cout << "Element[" << i + 1 << ", " << j + 1 << "] (0 za false, 1 za true): ";
            int unos; cin >> unos;
            m.at(i).at(j) = (unos != 0);
        }
    }
    return m;
}

bool provjeriTranzitivnostMatrice (Matrica m) {
    for (int i = 0; i < m.size(); i++) {
        if (m.at(i).size() != m.size()) {
            throw domain_error("Parametar nije kvadratna matrica");
        }
    }
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m.size(); j++) {
                if (m.at(i).at(j)) {
                    for (int k = 0; k < m.size(); k++) {
                        if (m.at(j).at(k) && !m.at(i).at(k)) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

void ispisiMatricu (Matrica m, int sirinaIspisa) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            cout << std::setw(sirinaIspisa) << std::boolalpha << m.at(i).at(j);
        }
        cout << endl;
    }
}

int main() {
    try {
        cout << "Unesite kvadratnu matricu oblika n x n: ";
        int n; cin >> n; int m; cin >> m;
        auto m1 = unesiMatricu(n, m);
        cout << endl;

        ispisiMatricu(m1, 6);

        provjeriTranzitivnostMatrice(m1) ? cout << "Matrica je tranzitivna." : cout << "Matrica nije tranzitivna.";
    } catch (domain_error &e) {
        cout << "Greska: " << e.what() << endl;
    }
    return 0;
}