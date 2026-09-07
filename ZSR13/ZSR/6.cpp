#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define PI (std::atan(1) * 4)
using std::cout, std::cin, std::vector, std::string, std::endl;

class Lik {
    string naziv;
    int brojac;
public:
    Lik(string naziv) : naziv(naziv), brojac(1){}
    string DajNaziv() const {return naziv;}
    int DajVrijednostBrojaca() const {return brojac;}
    virtual double DajObim() const = 0;
    friend std::ostream &operator <<(std::ostream &tok, const Lik &l);

    bool operator<(const Lik &l) const {
        return this->DajObim() < l.DajObim();
    }
    bool operator>(const Lik &l) const {
        return this->DajObim() > l.DajObim();
    }

    Lik &operator++() {
        this->brojac++;
        return *this;
    }

    virtual ~Lik() = default;
};
std::ostream &operator <<(std::ostream &tok, const Lik &l) {
    tok << "Lik: " << l.DajNaziv() << " Obim: " << l.DajObim();
    return tok;
}

class Krug : public Lik {
    double r;
public:
    Krug(double r) :
        Lik("Krug"), r(r){}
    double DajObim() const override {
        return (2 * r * PI);
    }
};

class Pravougaonik : public Lik {
    double a, b;
public:
    Pravougaonik(double a, double b) :
        Lik("Pravougaonik"), a(a), b(b){}
    double DajObim() const override {
        return (2*a + 2*b);
    }
};

class Trougao : public Lik {
    double a, b, c;
public:
    Trougao(double a, double b, double c) :
        Lik("Trougao"), a(a), b(b), c(c){}
    double DajObim() const override {
        return (a + b + c);
    }
};

class KontejnerLikova {
    Lik** likovi;
    int broj_likova;
    const int kapacitet;
    int* brojac;
    void ValidirajDodavanje() const {
        if (broj_likova >= kapacitet) throw std::range_error("Kolekcija je popunjena");
    }
    void ValidirajPrazan() const {
        if (broj_likova == 0) throw std::logic_error("Kolekcija je prazna");
    }
public:
    explicit KontejnerLikova(int kapacitet) :
        kapacitet(kapacitet), broj_likova(0), likovi(new Lik *[kapacitet]{}){brojac = new int(1);}
    KontejnerLikova(const KontejnerLikova &drugi) :
        kapacitet(drugi.kapacitet),broj_likova(drugi.broj_likova), brojac(drugi.brojac), likovi(drugi.likovi) {
        (*brojac)++;
    }
    KontejnerLikova &operator=(const KontejnerLikova &drugi) = delete;
    ~KontejnerLikova() {
        if (--(*brojac) == 0) {
          for (int i = 0; i < broj_likova; i++) delete likovi[i];
          delete[] likovi;
          delete brojac;
        }
    }
    KontejnerLikova& DodajKrug(double r) {
        ValidirajDodavanje();
        likovi[broj_likova] = new Krug(r);
        broj_likova++;
        return *this;
    }
    KontejnerLikova& DodajPravougaonik (double a, double b) {
        ValidirajDodavanje();
        likovi[broj_likova] = new Pravougaonik(a, b);
        broj_likova++;
        return *this;
    }
    KontejnerLikova& DodajTrougao (double a, double b, double c) {
        ValidirajDodavanje();
        likovi[broj_likova] = new Trougao(a, b, c);
        broj_likova++;
        return *this;
    }
    int DajBrojLikova() const {return broj_likova;}
    Lik& NajveciObim () {
        ValidirajPrazan();
        Lik* najveciObim = nullptr;
        for (int i = 0; i < broj_likova; i++) {
            if (najveciObim == nullptr || likovi[i]->DajObim() > najveciObim->DajObim()) {
                najveciObim = likovi[i];
            }
        }
        return *najveciObim;
    }
    int DajBrojKrugova() {
        int brojacKrugova = 0;
        for (int i = 0; i < broj_likova; i++) {
            if (likovi[i]->DajNaziv() == "Krug") brojacKrugova++;
        }
        return brojacKrugova;
    }

    KontejnerLikova& SortirajPoObimu() {
        std::sort(likovi, likovi + broj_likova, [](Lik *a, Lik *b) {
            return a->DajObim() < b->DajObim();
        });
        return *this;
    }

    bool operator!() {
        return broj_likova == 0;
    }

    friend std::ostream &operator<<(std::ostream &tok, const KontejnerLikova &c);

    const Lik &operator[](int indeks) const {
        if (indeks < 0 || indeks >= broj_likova)
            throw std::logic_error("Indeks van niza");
        return *likovi[indeks];
    }

};

std::ostream &operator<<(std::ostream &tok, const KontejnerLikova &c) {
    c.ValidirajPrazan();
    for (int i = 0; i < c.broj_likova; i++) {
        tok << *c.likovi[i] << endl;
    }
    return tok;
}

int main() {
    KontejnerLikova k(4);

    k.DodajKrug(4);
    k.DodajPravougaonik(3, 5);
    k.DodajTrougao(4, 5, 7);
    k.DodajKrug(7);


    cout << k;

    cout << "Broj likova u kontejneru: " << k.DajBrojLikova() << endl;
    cout << "Broj krugova u kontejneru: " << k.DajBrojKrugova() << endl;


    cout << "\nNajveci obim:\n";
    cout << k.NajveciObim() << endl;

    cout << "\nPrije sortiranja:\n";
    cout << k;

    k.SortirajPoObimu();

    cout << "\nPoslije sortiranja:\n";
    cout << k;

    cout << "\nLik na indeksu 1:\n";
    cout << k[1] << endl;

    cout << "\nJe li prazan: " << !k << endl;
    return 0;
}