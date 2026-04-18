//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

int **kontinualnoAlociranjeMatrice (const int brR, const int brK) {
    int **mat = nullptr;
    try {
        mat = new int* [brR];
        mat[0] = new int [brR * brK];
        for (int i = 1; i < brR; i++) {
            mat[i] = mat[i - 1] + brK;
        }
        for (int i = 0; i < brR; i++) {
            for (int j = 0; j < brK; j++) {
                mat[i][j] = i + j;
            }
        }
        return mat;

    } catch (std::bad_alloc &e) {
        cout << "Neuspjesna alokacija!";
        delete[] mat;
        throw;
    }
}

int main() {
    cout << "Unesite broj redova i kolona matrice: ";
    int brR, brK; cin >> brR >> brK;
    int **mat = nullptr;
    try {
        mat = kontinualnoAlociranjeMatrice(brR, brK);
        for (int i = 0; i < brR; i++) {
            for (int j = 0; j < brK; j++) {
                cout << std::setw(4) << mat[i][j];
            }
            cout << endl;
        }
        delete mat[0];
        delete mat;

    } catch (...) {
        cout << "Problem sa memorijom.";
    }
    return 0;
}