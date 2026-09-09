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


template<typename Tip>
class Skup {
    vector<Tip> elementi;
    Skup& Sortiraj() {
        return std::sort(elementi.begin(), elementi.end());
        return *this;
    }
public:
    Skup() : elementi{}{}
    Skup(std::initializer_list<Tip> lista) {
        for (const Tip &x : lista) {
            Dodaj(x);
        }
    }
    int Velicina() const {return elementi.size();}
    Skup& Dodaj(Tip element) {
        for (int i = 0; i < elementi.size(); i++) {
            if (element == elementi[i]) return *this;
            if (element < elementi[i]) {
                elementi.insert(elementi.begin() + i, element);
                return *this;
            }
        }
        elementi.push_back(element);
        return *this;
    }
    Skup& Obrisi(Tip element) {
        for (int i = 0; i < elementi.size(); i++) {
            if (element == elementi[i]) {
                elementi.erase(elementi.begin() + i);
                return *this;
            }
        }
        return *this;
    }
    bool ImaLiGa(Tip element) const {
        for (int i = 0; i < elementi.size(); i++) {
            if (element == elementi[i]) return true;
        }
        return false;
    }
    void Ispisi() const {
        for (int i = 0; i < elementi.size(); i++) {
            cout << elementi[i] << endl;
        }
    }
};

int main() {
    Skup<int> s{5, 2, 8, 1, 2, 5};

    cout << "Pocetni skup: ";
    s.Ispisi();

    cout << "Velicina: " << s.Velicina() << endl;

    s.Dodaj(4);
    s.Dodaj(8);   // vec postoji

    cout << "Nakon dodavanja 4 i 8: ";
    s.Ispisi();

    s.Obrisi(2);
    s.Obrisi(10);   // ne postoji

    cout << "Nakon brisanja 2 i 10: ";
    s.Ispisi();

    cout << "Ima li 5? " << s.ImaLiGa(5) << endl;
    cout << "Ima li 2? " << s.ImaLiGa(2) << endl;

    return 0;
}