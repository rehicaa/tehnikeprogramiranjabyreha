//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <iomanip>
using std::cout, std::cin, std::endl, std::vector, std::string, std::deque;
typedef deque<deque<char>> matrica;
matrica kreirajMatricu (int brojRedova, int brojKolona) {
    return matrica (brojRedova, deque<char>(brojKolona));
}

matrica unesiMatricu (int brojRedova, int brojKolona) {
    auto m = kreirajMatricu(brojRedova, brojKolona);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            cout << "Element[" << i + 1 << ", " << j + 1 << "]: ";
            cin >> m.at(i).at(j);
        }
    }
    return m;
}

void ispisiMatricu (matrica &m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            cout << std::setw(6) << m.at(i).at(j);
        }
        cout <<endl;
    }
}

bool daLiJeCirkulatorna (matrica &m) {
    if (m.empty()) return true;
    if (m.size() != m[0].size()) return false;
    for (int i = 0; i < m.size(); i++) {
        if (m[i].size() != m[0].size()) return false;
    }

    for (int i = 1; i < m.size(); i++) {
        if (m.at(i).at(0) != m.at(i - 1).at(m.size() - 1)) return false;
        for (int j = 1; j <m.size(); j++) {
            if (m.at(i).at(j) != m.at(i-1).at(j-1)) return false;
        }
    }
        return true;
}



int main() {
    cout << "Unesite format matrice: ";
    int brojRedova, brojKolona; cin >> brojRedova >> brojKolona;
    matrica m = unesiMatricu(brojRedova, brojKolona);
    cout << "\nVasa matrica: " << endl;
    ispisiMatricu(m);
    daLiJeCirkulatorna(m) ? cout << "Matrica je cirkulatorna." : cout << "Matrica nije cirkulatorna.";
    return 0;
}