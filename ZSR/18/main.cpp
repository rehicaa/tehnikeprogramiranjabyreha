//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;
typedef vector<vector<int>> matrica;

matrica kreirajMatricu (const int parametarMatrice) {
    return matrica (parametarMatrice, vector<int>(parametarMatrice));
}

matrica unesiMatricu (const int parametarMatrice) {
    auto m = kreirajMatricu(parametarMatrice);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            cout << "Element[" << i + 1 << ", " << j + 1 << "]: ";
            cin >> m.at(i).at(j);
        }
    }
    return m;
}

void ispisiMatricu (const matrica &m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            cout << std::setw(6) << m.at(i).at(j);
        }
        cout << endl;
    }
}

bool daLiJeMatricaSavrseniMagicniKvadrat (matrica &m) {
    if (m.empty()) return true;
    if (m.size() != m[0].size()) return false;
    for (int i = 0; i < m.size(); i++) {
        if (m[i].size() != m[0].size()) return false;
    }
    const int velicinaMatrice = m.size();
    const int maksCifara = velicinaMatrice * velicinaMatrice;
    vector<bool>cifreMatrice;
    for (int i = 0; i < (maksCifara); i++) {
         cifreMatrice.push_back(false);
     }

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            if (m.at(i).at(j) < 1 || m.at(i).at(j) > maksCifara) return false;
            if (cifreMatrice[m.at(i).at(j) - 1] == true) return false;
            cifreMatrice[m.at(i).at(j) - 1] = true;
        }
    }
    int magicnaSuma = 0;
    for (int i = 0; i < m.size(); i++) {
        magicnaSuma += m.at(0).at(i);
    }
    for (int i = 1; i < m.size(); i++) {
        int sumaTrenutnogReda = 0;
        for (int j = 0; j < m.size(); j++) {
            sumaTrenutnogReda += m.at(i).at(j);
        }
        if (sumaTrenutnogReda != magicnaSuma) return false;
    }

    for (int i = 0; i < m.size(); i++) {
        int sumaTrenutneKolone = 0;
        for (int j = 0; j < m.size(); j++) {
            sumaTrenutneKolone += m.at(j).at(i);
        }
        if (sumaTrenutneKolone != magicnaSuma) return false;
    }
    int sumaDijagonale = 0;
    for (int i = 0; i < m.size(); i++) {
        sumaDijagonale += m.at(i).at(i);
    }
    if (sumaDijagonale != magicnaSuma) return false;

    int sumaSporedneDijagonale = 0;
    for (int i = 0; i < m.size(); i++) {
        sumaSporedneDijagonale += m.at(i).at(m.size() - 1 - i);
    }
    if (sumaSporedneDijagonale != magicnaSuma) return false;

    return true;
}


int main() {
    cout << "Unesite parametar za matricu n x n: ";
    int n; cin >> n;
    matrica m = unesiMatricu(n);
    cout << endl << "Vasa matrica: " << endl;
    ispisiMatricu(m);
    cout << endl;
    daLiJeMatricaSavrseniMagicniKvadrat(m) ? cout << "Matrica je savrseni magicni kvadrat." : cout << "Matrica nije savrseni magicni kvadrat.";
    return 0;
}