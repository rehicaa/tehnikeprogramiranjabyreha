#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>
using std::cout, std::cin, std::vector, std::string, std::endl;
template<typename tip>
class Skup {
    vector<tip> set;
    void Sortiraj() {
        std::sort(set.begin(), set.end());
    }
public:
    Skup() = default;
    Skup(std::initializer_list<tip> lista) {
        for (auto it = lista.begin(); it != lista.end(); it++) {
            Dodaj(*it);
        }
    }
    void Dodaj (const tip &x) {
        for (int i = 0; i < set.size(); i++) {
            if (set[i] == x) return;
        }
        set.push_back(x);
        Sortiraj();
    }
    void Izbrisi (const tip &x) {
        for (int i = 0; i < set.size(); i++) {
            if (set[i] == x) {
                set.erase(set.begin() + i);
                return;
            }
        }
    }
    bool ImaLiGa(const tip &x) const {
        for (int i = 0; i < set.size(); i++) {
            if (set[i] == x) return true;
        }
        return false;
    }

    void Ispisi() const {
        for (int i = 0; i < set.size(); i++) {
            cout << set[i] << endl;
        }
    }

};

int main() {
    Skup s{5, 6, 1, 2, 4, 3};
    s.Dodaj(10);
    s.Ispisi();
    cout << endl;
    s.Izbrisi(6);
    s.Izbrisi(4);
    s.Ispisi();
    return 0;
}