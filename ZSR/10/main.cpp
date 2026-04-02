//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string;

vector<bool> vratiTrueNaMjestuPerfektnogKuba(const vector<int> &x) {
    vector<bool>rez;

    for (int i = 0; i < x.size(); i++) {
        if (x[i] < 0) throw std::domain_error ("Broj ne smije biti negativan!");
        int broj = x[i];
        bool jePerfektanKub = false;

        long long j = 0;
        while (j*j*j <= broj) {
            if (j*j*j == broj) {
                jePerfektanKub = true;
            }
            j++;
        }

        rez.push_back(jePerfektanKub);
    }

    return rez;
}

int main() {
    try {
        vector<int> x = {7, 125, 3, 5, 216};
        vector<bool>y = vratiTrueNaMjestuPerfektnogKuba(x);

        for (bool el : y) {
            cout << std::boolalpha << el << " ";
        }
    } catch (const std::domain_error &e) {
        cout << "Greshka: " << e.what();
    }

    return 0;
}