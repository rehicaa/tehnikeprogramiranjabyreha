#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

using std::cout, std::cin, std::vector, std::string, std::endl;
#define PI (std::atan(1) * 4)

class Krug {
    double r;
public:
    explicit Krug(double r) : r(r) {
        if (r <= 0) throw std::domain_error("Neispravan poluprecnik");
    }
    void Postavi (double r);
    double dajPoluprecnik() const {return r;}
    double dajObim() const {return (2 * r * PI);}
    double dajPovrsinu() const {return (r * r * PI);}
    Krug& Skaliraj(double faktorSkaliranja);
    void Ispisi() const;
};

void Krug::Postavi(double r) {
    if (r <= 0) throw std::domain_error("Neispravan poluprecnik");
    this->r = r;
}

Krug& Krug::Skaliraj(double faktorSkaliranja) {
    if (faktorSkaliranja <= 0) throw std::domain_error("Neispravan faktor skaliranja!");
    this->r *= faktorSkaliranja;

    return *this;
}

void Krug::Ispisi() const {
    cout << "Poluprecnik kruga: " << dajPoluprecnik() << endl;
    cout << "Obim kruga: " << dajObim() << endl;
    cout << "Povrsina kruga: " << dajPovrsinu() << endl;
}

class Valjak {
    Krug baza;
    double visina;
public:
    Valjak(Krug baza, double visina) : baza(baza), visina (visina) {
        if (visina <= 0) throw std::domain_error("Neispravna visina.");
    }
    Valjak(double r, double visina) : baza(r), visina(visina) {
        if (visina <= 0) throw std::domain_error("Neispravna visina.");
    }

    Valjak& Postavi (Krug baza, double visina) {
        if (visina <= 0) throw std::domain_error("Neispravna visina.");
        if (baza.dajPoluprecnik() <= 0) throw std::domain_error("Neispravan poluprecnik.");
        this->baza = baza;
        this->visina = visina;

        return *this;
    }

    Valjak& Postavi (double r, double visina) {
        if (visina <= 0) throw std::domain_error("Neispravna visina.");
        if (r <= 0) throw std::domain_error("Neispravan poluprecnik.");
        this->baza.Postavi(r);
        this->visina = visina;

        return *this;
    }

    Krug &dajBazu() {return baza;}
    const Krug &dajBazu() const { return baza; }
    double dajPoluprecnikBaze() const {return baza.dajPoluprecnik();}
    double dajVisinu() const {return visina;}
    double dajPovrsinu() const {return (2*baza.dajPoluprecnik()*PI*(baza.dajPoluprecnik() + visina));}
    double dajZapreminu() const {return baza.dajPoluprecnik()*baza.dajPoluprecnik()*PI*visina;}

    void Skaliraj(double faktorSkaliranja) {
        if (faktorSkaliranja <= 0) throw std::domain_error("Neispravan faktor skaliranja.");
        this->baza.Skaliraj(faktorSkaliranja);
        this->visina*=faktorSkaliranja;
    }

    void Ispisi() const {
        cout << "Baza ovog valjka je: \n"; baza.Ispisi();
        cout << "Poluprecnik baze je: " << this->baza.dajPoluprecnik() << endl;
        cout << "Visina valjka je: " << dajVisinu() << endl;
        cout << "Povrsina valjka je: " << dajPovrsinu() << endl;
        cout << "Zapremina valjka je: " << dajZapreminu() << endl;
    }



};

int main() {
    try {
        Krug k1(5);
        Valjak v1 (k1, 9);
        v1.Ispisi();
    } catch (std::exception &e) {
        cout << "GRESKA: " << e.what() << endl;
    }

    return 0;
}