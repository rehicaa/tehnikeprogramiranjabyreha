#include <iostream>
#include <stdexcept>
#include <iomanip>

using std::cout, std::cin, std::endl, std::domain_error;

int** generirajPascalovTrougaoKontinualno(int n) {
    if (n <= 0) throw domain_error("Broj redova mora biti pozitivan");

    int** matrica = nullptr;

    try {
        matrica = new int*[n]{};
        matrica[0] = new int[n * (n + 1) / 2];

        for (int i = 1; i < n; i++) {
            matrica[i] = matrica[i - 1] + i;
        }

        for (int i = 0; i < n; i++) {
            matrica[i][0] = 1;
            matrica[i][i] = 1;
            for (int j = 1; j < i; j++) {
                matrica[i][j] = matrica[i - 1][j - 1] + matrica[i - 1][j];
            }
        }
    } 
    catch (std::bad_alloc &e){
        delete[] matrica[0];
        delete[] matrica;
        throw;
    }
    return matrica;
}

int main() {
    cout << "Unesite broj redova: ";
    int n; cin >> n;

    try {
        int** trougao = generirajPascalovTrougaoKontinualno(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cout << std::setw(5) << trougao[i][j];
            }
            cout << endl;
        }

        delete[] trougao[0];
        delete[] trougao;

    } 
    catch (std::exception &e) {
        cout << "IZUZETAK: " << e.what() << endl;
    }

    return 0;
}