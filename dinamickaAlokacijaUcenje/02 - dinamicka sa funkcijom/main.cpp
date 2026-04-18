//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

int *spojiNizove (int *n1, int vel1, int *n2, int vel2) {

    int *finalniNiz = new int[vel1 + vel2];
    try {
        for (int i = 0; i < vel1; i++) {
            finalniNiz[i] = n1[i];
        }
        for (int i = vel1; i < vel1 + vel2; i++) {
            finalniNiz[i] = n2[i - vel1];
        }
    } catch (std::bad_alloc &e) {
        delete[] finalniNiz;
        cout << "Alociranje memorije neuspjesno!";
    }

    return finalniNiz;
}

int main() {
    cout << "Unesite velicine nizova respektivno: ";
    int n1, n2; cin >> n1 >> n2;
    try {
        int *niz1 = new int[n1];
        int *niz2 = new int[n2];
        cout << "\nUnesite elemente prvog niza: ";
        for (int i = 0; i < n1; i++) {
            cout << "\nElement[" << i + 1 << "]: ";
            cin >> niz1[i];
        }

        cout << "\nUnesite elemente drugog niza: ";
        for (int i = 0; i < n2; i++) {
            cout << "\nElement[" << i + 1 << "]: ";
            cin >> niz2[i];
        }

        int *finalniNiz = spojiNizove(niz1, n1, niz2, n2);
        cout << "\nFinalni niz spojeni: ";
        for (int i = 0; i < n1 + n2; i++) {
            cout << finalniNiz[i] << " ";
        }

        delete[] niz1;
        delete[] niz2;
        delete[] finalniNiz;
    } catch (std::bad_alloc &e) {
        cout << "GRESKA: " << e.what() << endl;
    }
    return 0;
}