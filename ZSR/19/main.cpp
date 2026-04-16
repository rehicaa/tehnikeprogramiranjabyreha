//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <deque>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error, std::deque;
typedef vector<vector<double>> matrica;
matrica kreirajMatricu (int brojRedova, int brojKolona) {
    return matrica (brojRedova, vector<double>(brojKolona));
}

matrica unesiMatricu (int brojRedova, int brojKolona) {
    auto m = kreirajMatricu(brojRedova, brojKolona);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            cout << "Unesite element[" << i + 1 << ", " << j + 1 << "]: ";
            cin >> m.at(i).at(j);
        }
        cout << endl;
    }
    return m;
}

void ispisiMatricu (const matrica &m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            cout << std::setw(6)<< m.at(i).at(j);
        }
        cout << endl;
    }
}

deque<double> transformisiMatricu (matrica &m) {
    for (int i = 0; i < m.size(); i++) {
          if (m[i].size() != m[0].size()) throw domain_error ("Parametar nema formu matrice.");
    }

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size() / 2; j++) {
            double temp = m.at(i).at(j);
            m.at(i).at(j) = m.at(i).at(m[0].size() - 1 - j);
            m.at(i).at(m[0].size() - 1 - j) = temp;
        }
    }

    deque<double> rez;
    for (int i = 0; i < m[0].size(); i++) {
        double sumaKolone = 0;
        for (int j = 0; j < m.size(); j++) {
            sumaKolone += m.at(j).at(i);
        }
        rez.push_back(sumaKolone);
    }

    return rez;
}


int main() {
    try {
        cout << "Unesite broj redova i broj kolone matrice odvojeno razmakom: ";
        int brojRedova, brojKolona; cin >> brojRedova >> brojKolona;

        auto m = unesiMatricu(brojRedova, brojKolona);
        cout << "\nTrenutna matrica: " << endl; ispisiMatricu(m);

        deque<double> sumeKolona = transformisiMatricu(m);
        cout << "\nMatrica nakon obrtanja redova: " << endl; ispisiMatricu(m);

        cout << "\nSume kolona: ";

        for (int i = 0; i < sumeKolona.size(); i++) {
            cout << "\nSuma kolone[" << i + 1 << "]: " << sumeKolona.at(i) << endl;
        }
    } catch (domain_error &e) {
        cout << "GRESKA: " << e.what() << endl;
    }
    return 0;
}