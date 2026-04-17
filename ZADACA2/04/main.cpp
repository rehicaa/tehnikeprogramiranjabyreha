#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cout, std::cin, std::endl, std::vector;

template <typename TipElemenata>
TipElemenata IzracunajProizvod(const vector<TipElemenata> &v) {
    if (v.empty()) return TipElemenata(0);
    TipElemenata p = v[0];
    for (int i = 1; i < v.size(); i++) p *= v[i];
    return p;
}

template <typename TipElemenata>
bool Kriterij(const vector<TipElemenata> &v1, const vector<TipElemenata> &v2) {
    TipElemenata p1 = IzracunajProizvod(v1);
    TipElemenata p2 = IzracunajProizvod(v2);
    if (p1 != p2) return p1 < p2;
    return v1 < v2;
}

template <typename TipElemenata>
void SortirajPoProizvoduRedova(vector<vector<TipElemenata>> &mat) {
    std::sort(mat.begin(), mat.end(), Kriterij<TipElemenata>);
}

int main() {
    vector<vector<int>> matrica;
    cout << "Unesite elemente (* za kraj reda, * na pocetku reda za kraj unosa):" << endl;

    for (;;) {
        vector<int> red;
        int broj;
        while (cin >> broj) red.push_back(broj);
        cin.clear();
        char c;
        cin >> c;
        if (red.empty()) break;
        matrica.push_back(red);
    }

    SortirajPoProizvoduRedova(matrica);

    cout << endl << "Matrica nakon sortiranja:" << endl;
    for (const auto &red : matrica) {
        for (int i = 0; i < red.size(); i++) {
            cout << red[i] << " ";
        }
        cout << endl;
    }

    cout << endl << "Unesite elemente sekvence koja se trazi (* za kraj reda): ";
    vector<int> trazi;
    int broj;
    while (cin >> broj) trazi.push_back(broj);
    cin.clear();
    char c;
    cin >> c;

    auto it = std::lower_bound(matrica.begin(), matrica.end(), trazi, Kriterij<int>);

    if (it != matrica.end() && *it == trazi) {
        cout << "Trazena sekvenca se nalazi u " << (int(it - matrica.begin()) + 1) << ". redu (nakon sortiranja)" << endl;
    } else {
        cout << "Trazena sekvenca se ne nalazi u matrici" << endl;
    }

    return 0;
}