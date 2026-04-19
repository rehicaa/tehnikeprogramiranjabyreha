//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;
typedef vector<vector<double>> matrica;
matrica unesiMatricu () {
    cout << "Unesite broj redova matrice: ";
    int brojRedova; cin >> brojRedova;
    matrica mat(brojRedova);
    for (int i = 0; i < brojRedova; i++) {
        cout << "Broj elemenata kolone[" << i + 1 << "]: ";
        int brojKolona; cin >> brojKolona;
        for (int j = 0; j < brojKolona; j++) {
            cout << "Element[" << i + 1 << ", " << j + 1 << "]: ";
            int element; cin >> element;
            mat.at(i).push_back(element);
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

bool jeLiMatricaIspravna (const matrica &m) {
    if (m.empty()) return false;
    for (int i = 1; i < m.size(); i++) {
        if (m[0].size() != m[i].size()) return false;
    }
    return true;
}

matrica kronekerovProizvod (matrica A, matrica B) {
    if (!jeLiMatricaIspravna(A) || !jeLiMatricaIspravna(B)) throw domain_error("Matrica je neispravna!");
    int m = A.size();
    int n = A[0].size();
    int p = B.size();
    int q = B[0].size();

    matrica C (m * p, vector<double>(n * q));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                for (int l = 0; l < q; l++) {
                    C.at(i * p + k).at(j * q + l) = A.at(i).at(j) * B.at(k).at(l);
                }
            }
        }
    }
    return C;
}

int main() {
    matrica A = unesiMatricu(); cout << endl;
    ispisiMatricu(A);
    matrica B = unesiMatricu(); cout << endl;
    ispisiMatricu(B);


    matrica C = kronekerovProizvod(A, B);
    ispisiMatricu(C);
    return 0;
}