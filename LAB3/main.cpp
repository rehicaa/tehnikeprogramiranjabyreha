#include <iostream>
#include <vector>
#include <iomanip>

using std::vector, std::cout, std::cin, std::endl;

typedef vector<vector<int>> matrica;

matrica kreirajMatricu (int formatMatrice) {
    return matrica (formatMatrice, vector<int>(formatMatrice));
}

matrica unesiMatricu (int formatMatrice) {
    auto m = kreirajMatricu(formatMatrice);
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            cout << "Element[" << i + 1 << ", " << j + 1 << "]: ";
            cin >> m.at(i).at(j);
        }
    }

    return m;
}

void ispisiMatricu (matrica m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            cout << std::setw(7) << m.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

vector<int>vratiParnePoDijagonali(matrica m) {
    vector<int>rez;
    for (int i = 0; i < m.size(); i++) {
        int dijagEl = m.at(i).at(i);
        int suma = 0;
        while (dijagEl != 0) {
            int cifra = dijagEl % 10;
            suma+=cifra;
            dijagEl /= 10;
        }
        if (suma % 2 == 0) rez.push_back(m.at(i).at(i));
    }

    return rez;
}

int main() {
    cout << "Unesite format matrice: ";
    int n; cin >> n;
    auto m = unesiMatricu(n);

    cout << endl;

    cout << "Unesena matrica: " << endl;

    ispisiMatricu(m);

    vector<int> v = vratiParnePoDijagonali(m);
    cout << endl << "Parne sume po dijagonali: ";
    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}