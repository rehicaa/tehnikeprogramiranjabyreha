//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string;

vector<double> kreirajVektorElemenata (const vector<double> &A, const vector<int> &B) {
    vector<double> C;
    for (int i = 0; i < B.size(); i++) {
        if (B[i] >= A.size()) throw std::range_error ("Van opsega!");
        C.push_back(A[B[i]]);
    }

    return C;
}

int main() {
    const vector<double> A = {2.1, 4.1, 3.7, 6.9, 8.2, 4.5, 1.2, 1.7, 12.7};
    const vector<int> B = {0, 9, 3};

    const vector<double> C = kreirajVektorElemenata(A, B);

    for (const double x : C) {
        cout << x << " ";
    }


    return 0;
}