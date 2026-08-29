#include <iostream>
#include <list>
#include <algorithm>
#include <stdexcept>

using std::cin, std::cout, std::endl, std::list, std::swap, std::domain_error;

template <typename Tip>
Tip NadjiMinListu(const list<Tip> &lista) {
    if (lista.empty()) throw domain_error("Lista je prazna");
    auto it = lista.begin();
    Tip min = *it;
    for (auto it2 = lista.begin(); it2 != lista.end(); it2++) {
        if (*it2 < min) min = *it2;
    }
    return min;
}

template <typename Tip>
list<Tip> SortirajListu(list<Tip> lista) {
    for (auto it1 = lista.begin(); it1 != lista.end(); it1++) {
        for (auto it2 = it1; it2 != lista.end(); it2++) {
            if (*it2 < *it1) {
                swap(*it1, *it2);
            }
        }
    }
    return lista;
}

int main() {
    int n;
    cout << "Koliko elemenata zelite unijeti: ";
    cin >> n;

    list<double> mojaLista;
    cout << "Unesite elemente: ";
    for (int i = 0; i < n; i++) {
        double privremeni;
        cin >> privremeni;
        mojaLista.push_back(privremeni);
    }

    try {
        double min = NadjiMinListu(mojaLista);
        cout << "Minimalni element je: " << min << endl;

        list<double> sortirana = SortirajListu(mojaLista);

        cout << "Sortirana lista: ";
        for (double x : sortirana) {
            cout << x << " ";
        }
        cout << endl;
    } catch (domain_error e) {
        cout << e.what() << endl;
    }

    return 0;
}