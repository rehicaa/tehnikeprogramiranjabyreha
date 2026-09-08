#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Spremnik {
public:
    virtual double DajTezinu() const = 0;
    virtual double DajUkupnuTezinu() const = 0;
    virtual ~Spremnik() = default;
    virtual Spremnik *DajKopiju() const = 0;
    virtual void Ispisi() const = 0;
};

class Sanduk : public Spremnik {
    int tezina_sanduka;
    string naziv_predmeta;
    int broj_predmeta;
    int tezina_predmeta;
public:
    double DajTezinu() const override {
        return tezina_sanduka;
    }
    double DajUkupnuTezinu() const override {
        return tezina_sanduka + broj_predmeta * tezina_predmeta;
    }
    Spremnik *DajKopiju() const override {
        return (new Sanduk(*this));
    }
    Sanduk(int tezina_sanduka, string naziv_predmeta, int broj_predmeta, int tezina_predmeta) :
        tezina_sanduka(tezina_sanduka), naziv_predmeta(naziv_predmeta), broj_predmeta(broj_predmeta), tezina_predmeta(tezina_predmeta){}
    void Ispisi() const override {
        cout << "Vrsta: Sanduk" << endl
        << " Tezina: " << tezina_sanduka << endl
        << "Naziv: " << naziv_predmeta << endl
        << "Broj predmeta: " << broj_predmeta << endl
        << "Tezina predmeta: " << tezina_predmeta << endl;
    }
};

class Bure : public Spremnik {
    double tezina_bureta;
    string naziv_tecnosti;
    double tezina_tecnosti;
public:
    double DajTezinu() const override {
        return tezina_bureta;
    }
    double DajUkupnuTezinu() const override {
        return tezina_bureta + tezina_tecnosti;
    }
    Spremnik *DajKopiju() const override {
        return (new Bure(*this));
    }
    Bure(double tezina_bureta, string naziv_tecnosti, double tezina_tecnosti) : tezina_bureta(tezina_bureta), naziv_tecnosti(naziv_tecnosti), tezina_tecnosti(tezina_tecnosti){}
    void Ispisi() const override {
        cout << "Vrsta: Bure" << endl
        << " Tezina: " << tezina_bureta << endl
        << "Naziv tecnosti: " << naziv_tecnosti << endl
        << "Tezina tecnosti: " << tezina_tecnosti << endl;
    }
};

class Skladiste {
    int maks_kolicina;
    int broj_spremnika;
    Spremnik** spremnici;
public:
    explicit Skladiste (int maks_kolicina) : maks_kolicina(maks_kolicina), broj_spremnika(0), spremnici(new Spremnik *[maks_kolicina]{}){}
    ~Skladiste() {
        for (int i = 0; i < broj_spremnika; i++) {
            delete spremnici[i];
        }
        delete[] spremnici;
    }
    Skladiste(const Skladiste &s) : maks_kolicina(s.maks_kolicina), broj_spremnika(s.broj_spremnika),
    spremnici(new Spremnik *[s.maks_kolicina]{}) {
        try {
            for (int i = 0; i < s.broj_spremnika; i++) {
                spremnici[i] = s.spremnici[i]->DajKopiju();
            }
        } catch (...) {
            for (int i = 0; i < broj_spremnika; i++) {
                delete spremnici[i];
            }
            delete[] spremnici;
            throw;
        }
    }
    Skladiste &operator=(const Skladiste &s) {
        Spremnik** novi = new Spremnik*[s.maks_kolicina]{};
        try {
            for (int i = 0; i < s.broj_spremnika; i++) {
                novi[i] = s.spremnici[i]->DajKopiju();
            }
        }
        catch (...) {
            for (int i = 0; i < s.broj_spremnika; i++) {
                delete novi[i];
            }
            delete[] novi;
            throw;
        }
        for (int i = 0; i < broj_spremnika; i++) {
            delete spremnici[i];
        }
        delete[] spremnici;
        spremnici = novi;
        broj_spremnika = s.broj_spremnika;
        maks_kolicina = s.maks_kolicina;

        return *this;
    }
    Skladiste& DodajBure(double tezina_bureta, string naziv_tecnosti, double tezina_tekucine) {
        if (broj_spremnika >= maks_kolicina) throw std::domain_error("Kapacitet skladista je popunjen");
        spremnici[broj_spremnika] = new Bure (tezina_bureta, naziv_tecnosti, tezina_tekucine);
        broj_spremnika++;
        return *this;
    }
    Skladiste& DodajSanduk(int tezina_sanduka, string naziv_predmeta, int broj_predmeta, int tezina_predmeta) {
        if (broj_spremnika >= maks_kolicina) throw std::domain_error("Kapacitet skladista je popunjen");
        spremnici[broj_spremnika] = new Sanduk (tezina_sanduka, naziv_predmeta, broj_predmeta, tezina_predmeta);
        broj_spremnika++;
        return *this;
    }
    Spremnik& DajNajlaksi() {
        if (broj_spremnika == 0) throw std::logic_error("Skladiste je prazno");
        Spremnik *novi = nullptr;
        for (int i = 0; i < broj_spremnika; i++) {
            if (novi == nullptr || novi->DajTezinu() >= spremnici[i]->DajTezinu()) novi = spremnici[i];
        }
        return *novi;
    }
    Spremnik& DajNajtezi() {
        if (broj_spremnika == 0) throw std::logic_error("Skladiste je prazno");
        Spremnik *novi = nullptr;
        for (int i = 0; i < broj_spremnika; i++) {
            if (novi == nullptr || novi->DajTezinu() <= spremnici[i]->DajTezinu()) novi = spremnici[i];
        }
        return *novi;
    }
    int DajTeziOd(double n) {
        if (broj_spremnika == 0) throw std::logic_error("Skladiste je prazno");
        int brojac = 0;
        for (int i = 0; i < broj_spremnika; i++) {
            if (spremnici[i]->DajUkupnuTezinu() > n) brojac++;
        }
        return brojac;
    }
    void Ispisi() {
        Skladiste novi = *this;
        std::sort(novi.spremnici, novi.spremnici + novi.broj_spremnika,[](Spremnik *a, Spremnik*b) {
            return (a->DajUkupnuTezinu() > b->DajUkupnuTezinu());
        });
        for (int i = 0; i < novi.broj_spremnika; i++) {
            novi.spremnici[i]->Ispisi();
        }
    }
};

int main() {
    try {
        int kapacitet;
        cout << "Unesite maksimalni kapacitet skladista: ";
        cin >> kapacitet;

        Skladiste skladiste(kapacitet);

        int broj;
        cout << "Unesite broj spremnika: ";
        cin >> broj;

        for (int i = 0; i < broj; i++) {
            int izbor;
            cout << "\n1 - Sanduk\n2 - Bure\nIzbor: ";
            cin >> izbor;

            if (izbor == 1) {
                int tezina_sanduka, broj_predmeta, tezina_predmeta;
                string naziv_predmeta;

                cout << "Tezina sanduka: ";
                cin >> tezina_sanduka;

                cout << "Naziv predmeta: ";
                cin >> naziv_predmeta;

                cout << "Broj predmeta: ";
                cin >> broj_predmeta;

                cout << "Tezina jednog predmeta: ";
                cin >> tezina_predmeta;

                skladiste.DodajSanduk(tezina_sanduka, naziv_predmeta,
                                      broj_predmeta, tezina_predmeta);
            }
            else if (izbor == 2) {
                double tezina_bureta, tezina_tecnosti;
                string naziv_tecnosti;

                cout << "Tezina bureta: ";
                cin >> tezina_bureta;

                cout << "Naziv tecnosti: ";
                cin >> naziv_tecnosti;

                cout << "Tezina tecnosti: ";
                cin >> tezina_tecnosti;

                skladiste.DodajBure(tezina_bureta, naziv_tecnosti,
                                    tezina_tecnosti);
            }
            else {
                cout << "Neispravan izbor!" << endl;
                i--;
            }
        }

        cout << "\nNajlaksi spremnik:" << endl;
        skladiste.DajNajlaksi().Ispisi();

        cout << "\nNajtezi spremnik:" << endl;
        skladiste.DajNajtezi().Ispisi();

        double tezina;
        cout << "\nUnesite tezinu za provjeru: ";
        cin >> tezina;

        cout << "Broj spremnika ukupne tezine vece od "
             << tezina << ": " << skladiste.DajTeziOd(tezina) << endl;

        cout << "\nSadrzaj skladista sortiran po ukupnoj tezini:" << endl;
        skladiste.Ispisi();
    }
    catch (const std::exception &e) {
        cout << "Greska: " << e.what() << endl;
    }

    return 0;
}