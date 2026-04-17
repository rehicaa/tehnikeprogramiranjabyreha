#include <iostream>
#include <stdexcept>
#include <iomanip>

using std::cout, std::cin, std::endl, std::domain_error;

int** generirajPascalovTrougaoFragmentirano (int n) {
    if (n <= 0) throw domain_error ("Broj redova mora biti pozitivan");

    int** matrica = nullptr;
    try {
        matrica = new int*[n]{};
        for (int i = 0; i < n; i++) {
            matrica[i] = new int[i + 1];
            matrica[i][0] = 1;
            matrica [i][i] = 1;
            for (int j = 1; j < i; j++) {
                matrica[i][j] = matrica[i - 1][j - 1] + matrica[i - 1][j];
            }
        }
    } catch (...) {
        for (int i = 0; i < n; i++) delete[] matrica[i];
        delete[] matrica;
        throw;
    }
    return matrica;
}

int main () {
    cout << "Unesite broj redova: ";
    int n; cin >> n;

    try {
        int ** trougaoPaskalov = generirajPascalovTrougaoFragmentirano(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cout << std::setw(5) << trougaoPaskalov[i][j];
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++) delete[] trougaoPaskalov[i];
        delete[] trougaoPaskalov;

    } catch (std::exception &e) {
        cout << "IZUZETAK: " << e.what() << endl;
    }

    return 0;
}