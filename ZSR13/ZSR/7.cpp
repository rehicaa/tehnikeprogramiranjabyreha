#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Knjiga {
    int evidencijski_broj;
    string naslov, pisac, zanr;
    int godina_izdanja;
    int clanski_broj;
    int dana_na_citanju;
    virtual void Ispisi(std::ostream &tok) const {
        tok << "Naslov: " << DajNaslov() << " | Pisac: " << DajPisca() << " | Zanr: " << DajZanr() << " | Godina izdanja: " << DajGodinuIzdanja() << endl;
    }
public:
    Knjiga(int evBroj, string naslov, string pisac, string zanr, int godina_izdanja) :
        evidencijski_broj(evBroj), naslov(naslov), pisac(pisac), zanr(zanr), godina_izdanja(godina_izdanja),
        clanski_broj(0), dana_na_citanju(0){}
    virtual ~Knjiga() = default;

    int DajEvBroj() const {return evidencijski_broj;}
    string DajNaslov() const {return naslov;}
    string DajPisca() const {return pisac;}
    string DajZanr() const {return zanr;}
    int DajGodinuIzdanja() const {return godina_izdanja;}
    int DajClanskiBroj() const {return clanski_broj;}
    int DajDanaNaCitanju() const {return dana_na_citanju;}

    void ZaduziKnjigu (int clanski_broj) {
        if (clanski_broj <= 0) throw std::logic_error("Clanski broj manji ili jednak 0");
        this->clanski_broj = clanski_broj;
        dana_na_citanju = 0;
    }
    void RazduziKnjigu () {
        clanski_broj = 0;
    }
    bool operator!() const {
        return (clanski_broj != 0);
    }
    Knjiga operator++(int) {
        Knjiga stari = (*this);
        if (!(*this)) {
            dana_na_citanju++;
            return stari;
        }
        return stari;
    }
    Knjiga &operator++() {
        if (!(*this)){
            dana_na_citanju++;
        }
        return *this;
    }

    friend bool operator==(const Knjiga &k1, const Knjiga &k2);
    friend bool operator!=(const Knjiga &k1, const Knjiga &k2);

    friend std::ostream &operator<<(std::ostream &tok, const Knjiga &k);

};

bool operator==(const Knjiga &k1, const Knjiga &k2) {
    return (k1.DajNaslov() == k2.DajNaslov() && k1.DajGodinuIzdanja() == k2.DajGodinuIzdanja() && k1.DajPisca() == k2.DajPisca() && k1.DajZanr() == k2.DajZanr());
}
bool operator!=(const Knjiga &k1, const Knjiga &k2) {
    return (k1.DajNaslov() != k2.DajNaslov() || k1.DajGodinuIzdanja() != k2.DajGodinuIzdanja() || k1.DajPisca() != k2.DajPisca() || k1.DajZanr() != k2.DajZanr());
}

std::ostream &operator<<(std::ostream &tok, const Knjiga &k) {
    k.Ispisi(tok);
    return tok;
}


class Udzbenik : public Knjiga {
    string predmet;
    void Ispisi(std::ostream &tok) const override {
        tok << "Naslov: " << DajNaslov()
            << " | Pisac: " << DajPisca()
            << " | Zanr: " << DajZanr()
            << " | Godina izdanja: " << DajGodinuIzdanja()
            << " | Predmet: " << DajPredmet()
            << endl;
    }
public:
    Udzbenik(int evBroj, string naziv, string pisac, string zanr, int godina_izdanja, string predmet) :
        Knjiga (evBroj, naziv, pisac, zanr, godina_izdanja), predmet(predmet){}
    string DajPredmet() const {return predmet;}
};

class Biblioteka {
    int broj_knjiga;
    const int kapacitet;
    Knjiga** knjige;
    void ValidirajKapacitet() const {
        if (broj_knjiga >= kapacitet) throw std::logic_error("Kapacitet biblioteke je popunjen.");
    }
public:
    explicit Biblioteka(int kapacitet) :
        kapacitet(kapacitet), broj_knjiga(0), knjige(new Knjiga*[kapacitet]{}){}
    Biblioteka &operator = (const Biblioteka &b) = delete;
    ~Biblioteka() {
        for (int i = 0; i < broj_knjiga; i++) {
            delete knjige[i];
        }
        delete[] knjige;
    }
    Biblioteka& DodajKnjigu(int evBroj, string naziv, string pisac, string zanr, int godina_izdanja) {
        ValidirajKapacitet();
        knjige[broj_knjiga] = new Knjiga (evBroj, naziv, pisac, zanr, godina_izdanja);
        broj_knjiga++;
        return *this;
    }
    Biblioteka& DodajUdzbenik(int evBroj, string naziv, string pisac, string zanr, int godina_izdanja, string predmet) {
        ValidirajKapacitet();
        knjige[broj_knjiga] = new Udzbenik (evBroj, naziv, pisac, zanr, godina_izdanja, predmet);
        broj_knjiga++;
        return *this;
    }
    void ZaduziKnjigu (int evBroj, int clanski_broj) {
        for (int i = 0; i < broj_knjiga; i++) {
            if (knjige[i]->DajEvBroj() == evBroj) {
                knjige[i]->ZaduziKnjigu(clanski_broj);
                return;
            }
        }
        throw std::logic_error("Knjiga ne postoji");
    }
    void RazduziKnjigu (int evBroj) {
        for (int i = 0; i < broj_knjiga; i++) {
            if (knjige[i]->DajEvBroj() == evBroj) {
                knjige[i]->RazduziKnjigu();
                return;
            }
        }
        throw std::logic_error("Knjiga ne postoji");
    }
    bool JeLiZaduzena(int evBroj) const {
        for (int i = 0; i < broj_knjiga; i++) {
            if (knjige[i]->DajEvBroj() == evBroj) {
                return !(*(knjige[i]));
            }
        }
        throw std::logic_error("Knjiga ne postoji");
    }
    int DajClanskiBroj (int evBroj) const {
        for (int i = 0; i < broj_knjiga; i++) {
            if (knjige[i]->DajEvBroj() == evBroj) {
                return knjige[i]->DajClanskiBroj();
            }
        }
        throw std::logic_error("Knjiga ne postoji");
    }
    void IspisiSlobodneKnjige() const {
        for (int i = 0; i < broj_knjiga; i++) {
            if (!(!(*knjige[i]))) {
                cout << *knjige[i];
            }
        }
    }
    void IspisiZaduzeneKnjige() const {
        for (int i = 0; i < broj_knjiga; i++) {
            if (!(*knjige[i])) {
                cout << *knjige[i];
            }
        }
    }
    void IspisiKnjigeDuzeOd (int n) const {
        for (int i = 0; i < broj_knjiga; i++) {
            if (knjige[i]->DajDanaNaCitanju() > n) {
                cout << *knjige[i];
            }
        }
    }
    Biblioteka& sortirajPoDanimaCitanja() {
        std::sort(knjige, broj_knjiga + knjige,[](Knjiga *a, Knjiga *b) {
            if (a->DajDanaNaCitanju() == b->DajDanaNaCitanju()) {
                return a->DajNaslov() < b->DajNaslov();
            } else {
                return a->DajDanaNaCitanju() > b->DajDanaNaCitanju();
            }
        });
        return *this;
    }
    Knjiga &operator[](int evBroj) const {
        for (int i = 0; i < broj_knjiga; i++) {
            if (knjige[i]->DajEvBroj() == evBroj) {
                return *knjige[i];
            }
        }
        throw std::range_error("Knjiga ne postoji");
    }
    Biblioteka &operator++() {
        for (int i = 0; i < broj_knjiga; i++) {
            ++(*knjige[i]);
        }
        return *this;
    }
};

int main() {
    try {
        Biblioteka b(10);

        // Dodavanje običnih knjiga i udžbenika
        b.DodajKnjigu(
            101,
            "Na Drini cuprija",
            "Ivo Andric",
            "Roman",
            1945
        );

        b.DodajKnjigu(
            102,
            "Tvrdjava",
            "Mesa Selimovic",
            "Roman",
            1970
        );

        b.DodajUdzbenik(
            201,
            "Programiranje u C++",
            "Neki Autor",
            "Informatika",
            2025,
            "Tehnike programiranja"
        );

        b.DodajUdzbenik(
            202,
            "Diskretna matematika",
            "Neki Profesor",
            "Matematika",
            2024,
            "Diskretna matematika"
        );


        cout << "=== SVE KNJIGE PREKO operator[] ===" << endl;

        cout << b[101];
        cout << b[102];
        cout << b[201];
        cout << b[202];


        cout << "\n=== ZADUZIVANJE ===" << endl;

        b.ZaduziKnjigu(101, 5001);
        b.ZaduziKnjigu(201, 5002);
        b.ZaduziKnjigu(202, 5003);


        cout << "\n=== PROVJERA ZADUZENJA ===" << endl;

        cout << "101 zaduzena: "
             << (b.JeLiZaduzena(101) ? "DA" : "NE") << endl;

        cout << "102 zaduzena: "
             << (b.JeLiZaduzena(102) ? "DA" : "NE") << endl;

        cout << "201 zaduzena: "
             << (b.JeLiZaduzena(201) ? "DA" : "NE") << endl;


        cout << "\n=== CLANSKI BROJEVI ===" << endl;

        cout << "Knjiga 101: "
             << b.DajClanskiBroj(101) << endl;

        cout << "Knjiga 102: "
             << b.DajClanskiBroj(102) << endl;

        cout << "Udzbenik 201: "
             << b.DajClanskiBroj(201) << endl;


        cout << "\n=== SLOBODNE KNJIGE ===" << endl;
        b.IspisiSlobodneKnjige();


        cout << "\n=== ZADUZENE KNJIGE ===" << endl;
        b.IspisiZaduzeneKnjige();


        // jedan dan
        ++b;

        // drugi dan
        ++b;

        // sada su 101, 201 i 202 zadužene 2 dana

        // Razdužimo 202
        b.RazduziKnjigu(202);

        // još tri dana
        ++b;
        ++b;
        ++b;

        // 101 i 201 su sada 5 dana na čitanju


        cout << "\n=== KNJIGE DUZE OD 3 DANA ===" << endl;
        b.IspisiKnjigeDuzeOd(3);


        cout << "\n=== DIREKTAN PRISTUP PREKO [] ===" << endl;

        cout << "Knjiga 101 je na citanju "
             << b[101].DajDanaNaCitanju()
             << " dana." << endl;

        cout << "Udzbenik 201 je na citanju "
             << b[201].DajDanaNaCitanju()
             << " dana." << endl;


        cout << "\n=== TEST PREFIKSNOG ++ ZA POJEDINACNU KNJIGU ==="
             << endl;

        ++b[101];

        cout << "Knjiga 101 nakon ++: "
             << b[101].DajDanaNaCitanju()
             << " dana." << endl;


        cout << "\n=== RAZDUZIVANJE ===" << endl;

        b.RazduziKnjigu(101);

        cout << "101 zaduzena: "
             << (b.JeLiZaduzena(101) ? "DA" : "NE") << endl;


        cout << "\n=== SORTIRANJE ===" << endl;

        b.sortirajPoDanimaCitanja();

        cout << "Sortiranje zavrseno." << endl;


        cout << "\n=== TEST IZUZETKA ===" << endl;

        // knjiga 999 ne postoji
        cout << b[999];

    }
    catch (const std::exception &e) {
        cout << "IZUZETAK: " << e.what() << endl;
    }

    return 0;
}