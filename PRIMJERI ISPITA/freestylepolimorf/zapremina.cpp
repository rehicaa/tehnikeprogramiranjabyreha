#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <memory>

using std::cout, std::cin, std::vector, std::string, std::endl;
class Predmet {
    double specificna_tezina;
public:
    explicit Predmet(double tezina_predmeta) : specificna_tezina(tezina_predmeta){}
    virtual double DajZapreminu() const = 0;
    double DajTezinu() {
        return specificna_tezina * DajZapreminu();
    }
    virtual ~Predmet() = default;
};

class Kocka : public Predmet {
    double duzina_stranice;
public:
    Kocka(double specificna_tezina, double duzina_stranice) : Predmet(specificna_tezina), duzina_stranice(duzina_stranice){}
    double DajZapreminu() const override {
        return duzina_stranice * duzina_stranice * duzina_stranice;
    }
};

class Valjak : public Predmet {
    double r;
    double h;
public:
    Valjak(double specificna_tezina, double r, double h) : Predmet(specificna_tezina), r(r), h(h){}
    double DajZapreminu() const override {
        return h * r * r * (std::atan(1) * 4);
    }
};

int main() {
    std::ofstream izlaz("Predmeti.txt");
    if (!izlaz) throw std::logic_error("Datoteka se ne moze procitat");
    cout << "Unesite koliko hocete predmeta: ";
    int brPrem; cin >> brPrem;
    for (int i = 0; i < brPrem; i++) {
        cout << "Zelite li kocku ili valjak (1 - Kocka, 2 - Valjak): ";
        int odabir; cin >> odabir; cout << endl;
        if (odabir < 1 || odabir > 2) throw std::logic_error("Ilegalan odabir");
        if (odabir == 1) {
            cout << "Unesite specificnu tezinu predmeta: "; double spec_tez; cin >> spec_tez; cout << endl;
            cout << "Unesite duzinu stranice: "; double a; cin >> a; cout << endl;
            Kocka k(spec_tez, a) ;
            izlaz << "K" << k.DajTezinu() << " " << a << endl;
        } else {
            cout << "Unesite specificnu tezinu predmeta: "; double spec_tez; cin >> spec_tez; cout << endl;
            cout << "Unesite visinu: "; double h; cin >> h; cout << endl;
            cout << "Unesite poluprecnik: "; double r; cin >> r; cout << endl;
            Valjak v(spec_tez, r, h);
            izlaz << "V" << v.DajTezinu() << " " << r << h << endl;
        }
    }
    izlaz.close();
    std::ifstream ulaz("Predmeti.txt");
    if (!ulaz) throw std::logic_error("Datoteka se ne moze procitat");
    vector<std::shared_ptr<Predmet>> v;
    char vrsta;
    while (ulaz >> vrsta) {
        if (vrsta == 'K') {
            double spec_tez, a;
            ulaz >> spec_tez >> a;
            v.push_back(std::make_shared<Kocka>(spec_tez, a));
        }
        else if (vrsta == 'V') {
            double spec_tez, r, h;
            ulaz >> spec_tez >> r >> h;
            v.push_back(std::make_shared<Valjak>(spec_tez, r, h));
        }
    }
}