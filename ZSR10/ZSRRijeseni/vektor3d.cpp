#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <cmath>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Vektor3d {
    double x, y, z;
    mutable int brojac_ispisa;
public:
    Vektor3d() : x(0), y(0), z(0), brojac_ispisa(0){}
    Vektor3d(double x, double y, double z) : x(x), y(y), z(z) {
        this->brojac_ispisa = 0;
    }
    Vektor3d(const Vektor3d &v) {
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        this->brojac_ispisa = 0;
    }

    Vektor3d& Postavi (double x, double y, double z);
    Vektor3d& PostaviX (double x);
    Vektor3d& PostaviY (double y);
    Vektor3d& PostaviZ (double z);
    void Ocitaj() const;
    double DajX() const{return this->x;}
    double DajY() const{return this->y;}
    double DajZ() const{return this->z;}
    double DajDuzinu() const {return std::sqrt((x*x) + (y*y) + (z*z));}
    int DajBrojIspisa() const {return brojac_ispisa;}
    Vektor3d& PomnoziSaSkalarom (double faktorSkaliranja);
    Vektor3d& SaberiSa(const Vektor3d &v);
    void Ocitaj(double &x, double &y, double &z) const;
    void Ispisi() const;
    friend Vektor3d ZbirVektora (const Vektor3d &v1, const Vektor3d &v2);

};

Vektor3d &Vektor3d::Postavi(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;

    return *this;
}

Vektor3d &Vektor3d::PostaviX(double x) {
    this-> x = x;
    return *this;
}

Vektor3d &Vektor3d::PostaviY(double y) {
    this-> y = y;
    return *this;
}
Vektor3d &Vektor3d::PostaviZ(double z) {
    this-> z = z;
    return *this;
}

void Vektor3d::Ocitaj() const {
    cout << "X: " << this->x << "Y: " << this->y << "Z: " << this->z << endl;
}

Vektor3d& Vektor3d::PomnoziSaSkalarom(double faktorSkaliranja) {
    this->x*=faktorSkaliranja;
    this->y*=faktorSkaliranja;
    this->z*=faktorSkaliranja;

    return *this;
}

Vektor3d &Vektor3d::SaberiSa(const Vektor3d &v) {
    this->x+= v.x;
    this->y+= v.y;
    this->z+= v.z;

    return *this;
}

void Vektor3d::Ocitaj(double &x, double &y, double &z) const {
    x = this->x;
    y = this->y;
    z = this->z;
}

Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2) {
    Vektor3d rezultat;
    rezultat.PostaviX(v1.x + v2.x);
    rezultat.PostaviY(v1.y + v2.y);
    rezultat.PostaviZ(v1.z + v2.z);

    return rezultat;
}

void Vektor3d::Ispisi() const {
    cout << "{" << x << "," << y << "," << z << "}";
    brojac_ispisa++;
}

int main() {
    return 0;
}