//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;
template <typename tip>
void kompaktifikuj (tip** &mat, int brRed, int brKol) {
    tip** matKont = new tip* [brRed]{};
    try {
        matKont[0] = new tip [brRed * brKol];
        for (int i = 1; i < brRed; i++) {
            matKont[i] = matKont[i - 1] + brKol;
        }
        for (int i = 0; i < brRed; i++) {
            for (int j = 0; j < brKol; j++) {
                matKont[i][j] = mat[i][j];
            }
        }
        for (int i = 0; i < brRed; i++) {
            delete[] mat[i];
        }
        delete[] mat;
        mat = matKont;
    } catch (std::bad_alloc &e) {
        delete[] matKont[0];
        delete[] matKont;
        cout << "Neuspjesna alokacija!";
        throw;
    }
}

int main() {
    cout << "Unesite broj redova i broj kolona matrice: ";
    int brRed, brKol; cin >> brRed >> brKol;
    int** mat = nullptr;
    try {
        mat = new int *[brRed]{};
        for (int i = 0; i < brRed; i++) {
            mat[i] = new int[brKol];
            for (int j = 0; j < brKol; j++) {
                mat[i][j] = i + j;
            }
        }
    } catch (...) {
        for (int i = 0; i < brRed; i++) {
            delete[] mat[i];
        }
        delete[] mat;
        cout << "Neuspjesna alokacija!";
    }

    cout << "\nVasa matrica (fragmentirana): " << endl;
    for (int i = 0; i < brRed; i++) {
        for (int j = 0; j < brKol; j++) {
            cout << std::setw(5) << mat[i][j];
        }
        cout << endl;
    }

    kompaktifikuj(mat, brRed, brKol);
    cout << "\nVasa matrica (kontinualna): " << endl;
    for (int i = 0; i < brRed; i++) {
        for (int j = 0; j < brKol; j++) {
            cout << std::setw(5) << mat[i][j];
        }
        cout << endl;
    }


    delete[] mat[0];
    delete[] mat;

    return 0;
}