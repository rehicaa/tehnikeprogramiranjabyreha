#include <atomic>
#include <iostream>
#include <stdexcept>
#include <cmath>

#define PI (4 * std::atan(1))
class Krug {
    double poluprecnik;

public:
    Krug() {
        this -> poluprecnik = 0;
    }

    Krug& PostaviPoluprecnik (double poluprecnik);

    double DajDuzinuPoluprecnika() const {return poluprecnik;}

    double DajPovrsinaKruga() const {return (poluprecnik*poluprecnik) * PI;}

    double DajObimKruga () const {return (2 * poluprecnik) * PI;}

    Krug& SkalirajKrug (double faktorSkaliranja);

    void IspisiSve();
};

Krug& Krug::PostaviPoluprecnik (double poluprecnik) {
    if (poluprecnik < 0) {
        throw std::logic_error("Poluprecnik ne moze biti negativan!");
    }
    this -> poluprecnik = poluprecnik;

    return *this;
}

Krug& Krug::SkalirajKrug(double faktorSkaliranja) {
    if (faktorSkaliranja < 0) {
        throw std::logic_error("Faktor skaliranja mora biti 1 ili vise!");
    }
    this -> poluprecnik = this -> poluprecnik * faktorSkaliranja;
    return *this;
}

void Krug::IspisiSve() {
    std::cout << "Poluprecnik kruga je: " << Krug::DajDuzinuPoluprecnika() <<
        std::endl << "Povrsina kruga je: " << Krug::DajPovrsinaKruga() <<
            std::endl << "Obim krug je: " << Krug::DajObimKruga();
}

int main() {
    try {
        Krug k1;
        k1.PostaviPoluprecnik(3);
        k1.SkalirajKrug(2);
        k1.IspisiSve();
    } catch (std::exception &e) {
        std::cout << "GRESKA: " << e.what();
    }

    return 0;
}