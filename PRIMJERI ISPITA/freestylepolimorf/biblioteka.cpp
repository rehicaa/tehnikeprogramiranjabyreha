#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <algorithm>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Knjiga {
    int evBroj;
    string puniNaziv;
    int clanskiBroj;
    int danaNaPosudbi;
public:
    Knjiga(int evBroj, string puniNaziv) : evBroj(evBroj), puniNaziv(puniNaziv), clanskiBroj(0), danaNaPosudbi(0){}
    int dajEvBroj() const {return evBroj;}
    string dajPuniNaziv() const {return puniNaziv;}
    int dajClanskiBroj() const {return  clanskiBroj;}
    int dajDanaNaPosudbi() const {return danaNaPosudbi;}
    void ZaduziKnjigu(int clanskiBroj) {
        this->clanskiBroj = clanskiBroj;
        danaNaPosudbi = 0;
    }
    void RazduziKnjigu() {
        clanskiBroj = 0;
    }
    bool JeLiZaduzena() const {
        return clanskiBroj != 0;
    }
    virtual std::ostream& Ispisi(std::ostream &tok) const {
        tok << "Evidencijski broj: " << evBroj << endl
        << "Puni naziv: " << puniNaziv << endl;
        return tok;
    }
    virtual bool JeLiUdzbenik() const {
        return false;
    }
    virtual ~Knjiga() = default;
};

class Udzbenik : public Knjiga {
    string predmet;
    std::ostream& Ispisi(std::ostream &tok) const override {
        Knjiga::Ispisi(tok);
        tok << "Predmet: " << predmet << endl;
        return tok;
    }
    bool JeLiUdzbenik() const override {
        return true;
    }
public:
    string DajPredmet() const {return predmet;}
    Udzbenik(int evBroj, string puniNaziv, string predmet) : Knjiga(evBroj, puniNaziv), predmet(predmet){}
    friend class Biblioteka;
};

class Biblioteka {
    int broj_knjiga;
    int kapacitet;
    Knjiga** knjige;
public:
    explicit Biblioteka(int kapacitet) : broj_knjiga(0), kapacitet(kapacitet), knjige(new Knjiga*[kapacitet]{}){}
    ~Biblioteka() {
        for (int i = 0; i < kapacitet; i++) {
            delete knjige[i];
        }
        delete[] knjige;
    }
    Biblioteka(const Biblioteka &b) : broj_knjiga(b.broj_knjiga), kapacitet(b.kapacitet), knjige(new Knjiga*[kapacitet]{}) {
        try {
            for (int i = 0; i < b.broj_knjiga; i++) {
                if (b.knjige[i]->JeLiUdzbenik()) {
                    knjige[i] = new Udzbenik(*dynamic_cast<const Udzbenik *>(b.knjige[i]));
                } else {
                    knjige[i] = new Knjiga(*b.knjige[i]);
                }
            }
        } catch (...) {
            for (int i = 0; i < broj_knjiga; i++) {
                delete knjige[i];
            }
            delete[] knjige;
            throw;
        }
    }
    Biblioteka &operator =(const Biblioteka &b) {
        if (&b == this) return *this;
        Knjiga** novi = nullptr;
        try {
            novi = new Knjiga *[b.kapacitet];
            for (int i = 0; i < b.broj_knjiga; i++) {
                if (b.knjige[i]->JeLiUdzbenik()) {
                    novi[i] = new Udzbenik(*dynamic_cast<const Udzbenik*>(b.knjige[i]));
                } else {
                    novi[i] = new Knjiga(*b.knjige[i]);
                }
            }
        } catch (...) {
            for (int i = 0; i < b.kapacitet; i++) {
                delete novi[i];
            }
            delete[] novi;
            throw;
        }
        for (int i = 0; i < broj_knjiga; i++) delete knjige[i];
        delete[] knjige;

        knjige = novi;
        knjige = novi;
        broj_knjiga = b.broj_knjiga;
        kapacitet = b.kapacitet;

        return *this;
    }

    Biblioteka(Biblioteka &&b) : knjige(b.knjige), kapacitet(b.kapacitet), broj_knjiga(b.broj_knjiga) {
        b.knjige = nullptr;
        b.kapacitet = 0;
        b.broj_knjiga = 0;
    }

    Biblioteka &operator=(Biblioteka &&b) {
        if (&b == this) return *this;
        for (int i = 0; i < broj_knjiga; i++) {
            delete knjige[i];
        }
        delete[] knjige;
        knjige = b.knjige;
        broj_knjiga = b.broj_knjiga;
        kapacitet = b.kapacitet;

        b.knjige = nullptr;
        b.broj_knjiga = 0;
        b.kapacitet = 0;

        return *this;
    }

    Biblioteka& DodajKnjigu (int evBroj, string puniNaziv) {
        if (kapacitet <= broj_knjiga) throw std::range_error("Kapacitet biblioteke je pun");
        knjige[broj_knjiga] = new Knjiga (evBroj, puniNaziv);
        broj_knjiga++;
        return *this;
    }
    Biblioteka& DodajUdzbenik (int evBroj, string puniNaziv, string predmet) {
        if (kapacitet <= broj_knjiga) throw std::range_error("Kapacitet biblioteke je pun");
        knjige[broj_knjiga] = new Udzbenik(evBroj, puniNaziv, predmet);
        broj_knjiga++;
        return *this;
    }
    Knjiga& DajKnjigu (int evBroj) const {
        for (int i = 0; i < broj_knjiga; i++) {
            if (knjige[i]->dajEvBroj() == evBroj) {
                return *knjige[i];
            }
        }
        throw std::logic_error("Knjiga ne postoji");
    }
    void ZaduziKnjigu(int evBroj, int clanskiBroj) {
       Knjiga &k = DajKnjigu(evBroj);
        k.ZaduziKnjigu(clanskiBroj);
    }
    void RazduziKnjigu(int evBroj) {
        Knjiga &k = DajKnjigu(evBroj);
        k.RazduziKnjigu();
    }
    int DajClanskiBrojKodKojegJeKnjiga(int evBroj = 0) {
        Knjiga &k = DajKnjigu(evBroj);
        return k.dajClanskiBroj();
    }
    void IspisiSlobodne(std::ostream &tok) const {
        for (int i = 0; i < broj_knjiga; i++) {
            if (!knjige[i]->JeLiZaduzena()) {
                knjige[i]->Ispisi(tok);
            }
        }
    }
    void IspisiZaduzene(std::ostream &tok) const {
        for (int i = 0; i < broj_knjiga; i++) {
            if (knjige[i]->JeLiZaduzena()) {
                knjige[i]->Ispisi(tok);
            }
        }
    }
    void IspisiKnjigeZaduzeneDuzeOd(int n, std::ostream &tok) const {
        for (int i = 0; i < broj_knjiga; i++) {
            if (knjige[i]->dajDanaNaPosudbi() > n) {
                knjige[i]->Ispisi(tok);
            }
        }
    }
    void Sortiraj() {
        std::sort(knjige, knjige + broj_knjiga,[](Knjiga *a, Knjiga*b) {
            if (a->dajDanaNaPosudbi() == b->dajDanaNaPosudbi()) {
                return (a->dajPuniNaziv() < b->dajPuniNaziv());
            } else {
                return (a->dajDanaNaPosudbi() > b->dajDanaNaPosudbi());
            }
        });
    }
};

int main() {

    return 0;
}