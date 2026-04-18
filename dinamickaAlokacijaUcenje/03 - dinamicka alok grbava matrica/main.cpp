//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

int main() {
    cout << "Unesite broj redova grbave matrice: ";
    int n; cin >> n;

    int **mat = nullptr;
    try {
        mat = new int*[n];
        for(int i = 0; i < n; i++) mat[i] = nullptr;
        
        for (int i = 0; i < n; i++) {
            mat[i] = new int[i + 1];
            for (int j = 0; j < i + 1; j++) {
                mat[i][j] = i + j;
            }
        }

        cout << "\nGrbava matrica: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                cout << std::setw(5) << mat[i][j];
            }
            cout << endl;
        }
    } catch (...) {
        cout << "Alociranje neuspjesno!";
    }
    //brisanje fragmentirane matrice mora biti u petlji
    for (int i = 0; i < n; i++) {
        delete[] mat[i];
    }
    delete[] mat;

    return 0;
}