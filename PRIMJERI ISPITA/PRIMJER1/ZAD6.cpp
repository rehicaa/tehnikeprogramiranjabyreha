#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <ratio>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Artikal {
    string naziv;
    double cijena;
public:
    Artikal(string naziv, double cijena) : naziv(naziv), cijena(cijena){}
    virtual ~Artikal() = default;
    string DajNaziv() const {return naziv;}
    double DajCijenu() const {return cijena;}
    virtual Artikal* DajKopiju() const = 0;
    virtual void Ispisi() const = 0;
};

class Ulje : public Artikal {
    double litri;
public:
    Ulje(double cijena, double litri) : Artikal("Ulje", cijena), litri(litri){}
    double DajLitre() const {return litri;}
    Artikal* DajKopiju() const override {
        return new Ulje(*this);
    }
    void Ispisi() const override {
        cout << "Ulje " << litri <<"l, " << this->DajCijenu() << "KM" << endl;
    }
};

class Brasno : public Artikal {
    double kilogrami;
public:
    Brasno(double cijena, double kilogrami) : Artikal("Brasno", cijena), kilogrami(kilogrami){}
    double DajKilograme() const {return kilogrami;}
    Artikal* DajKopiju() const override {
        return new Brasno(*this);
    }
    void Ispisi() const override {
        cout << "Brasno " << kilogrami << "KG, " << this->DajCijenu() << "KM" << endl;
    }
};

class Prodavnica {
    vector<Artikal*> artikli;
public:
    Prodavnica& DodajUlje(double cijena, double litri) {
        artikli.push_back(new Ulje(cijena, litri));
        return *this;
    }
    Prodavnica& DodajUlje (Ulje &u) {
        artikli.push_back(u.DajKopiju());
        return *this;
    }
    Prodavnica& DodajBrasno(double cijena, double kilogrami) {
        artikli.push_back(new Brasno(cijena, kilogrami));
        return *this;
    }
    Prodavnica& DodajBrasno(Brasno &b) {
        artikli.push_back(b.DajKopiju());
        return *this;
    }


    Prodavnica() = default;
    ~Prodavnica() {
        for (Artikal *a: artikli) {
            delete a;
        }
    }
    Prodavnica(const Prodavnica &p){
        for (Artikal* a : p.artikli) {
            artikli.push_back(a->DajKopiju());
        }
    }
    Prodavnica &operator =(const Prodavnica &p) {
        if (&p == this) return *this;
        vector<Artikal*> novi;
        try {
            for (Artikal *a : p.artikli) {
                novi.push_back(a->DajKopiju());
            }
        } catch (...) {
            for (Artikal *a : novi) {
                delete a;
            }
            throw;
        }
        for (Artikal *a : artikli) {
            delete a;
        }
        artikli = novi;
        return *this;
    }

    Prodavnica(Prodavnica &&p) : artikli(std::move(p.artikli)){}

    Prodavnica& operator=(Prodavnica &&p) {
        if (&p == this) return *this;
        for (Artikal *a : artikli) {
            delete a;
        }
        artikli = (std::move(p.artikli));
        return *this;
    }

    Artikal* operator[](int indeks) {
        if (indeks >= artikli.size() || indeks < 0) throw std::range_error("Indeks ide van granica vektora");
        return artikli[indeks];
    }

    void Ispisi() const {
        for (Artikal* a : artikli) {
            a->Ispisi();
        }
    }
    
};




int main() {
    return 0;
}