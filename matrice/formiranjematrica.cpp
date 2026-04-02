//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using std::cout, std::cin, std::endl, std::vector, std::string;
typedef vector<vector<double>> Matrica;

Matrica kreirajMatricu (int broj_redova, int broj_kolona) {
    return Matrica (broj_redova, vector<double>(broj_kolona));
}
Matrica unesiMatricu (int broj_redova, int broj_kolona) {
    auto m = kreirajMatricu(broj_redova, broj_kolona);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            cout << "Unesite element[" << i + 1 << ", " << j + 1 << "]: ";
            cin >> m.at(i).at(j);
        }
    }

    return m;
}

void ispisiMatricu (Matrica m, int sirinaIspisa) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            cout << std::setw(sirinaIspisa) << m.at(i).at(j);
        }
            cout << endl;
    }
}

int main() {
    cout << "Unesite format matrice a x b: ";
    int brojRedova, brojKolona; cin >> brojRedova >> brojKolona;
    Matrica m = unesiMatricu(brojRedova, brojKolona);
    cout << endl;

    ispisiMatricu(m, 3);


    return 0;
}