#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

using std::cout, std::cin, std::vector, std::string, std::endl;

class VektorNd {
    int dimenzija;
    double* koordinate;

public:
    explicit VektorNd(int dimenzija, double vrijednost = 0);
    VektorNd(int dimenzija, double niz[]);
    ~VektorNd();

    VektorNd(const VektorNd &v);
    VektorNd &operator=(const VektorNd &v);

    int DajDimenzijuVektora() const { return dimenzija; }

    double DajVrijednostNaIndeksu(int indeks) const;
    void PostaviVrijednostNaIndeksu(int indeks, double vrijednost);

    double DajDuzinuVektora() const;

    friend double DajDuzinuVektora(const VektorNd &v1);

    int DajRangVektora() const;

    VektorNd& Redimenzionriaj(int vrijednost);

    friend std::ostream& operator<<(std::ostream &tok, const VektorNd &v);
    friend VektorNd operator+(VektorNd v1, const VektorNd &v2);
    friend VektorNd operator-(VektorNd v1, const VektorNd &v2);
    friend double operator*(VektorNd v1, const VektorNd &v2);
    friend VektorNd operator*(double broj, const VektorNd &v);

    VektorNd operator*(double broj) const;

    VektorNd &operator+=(const VektorNd &v);
    VektorNd &operator-=(const VektorNd &v);
    VektorNd &operator*=(double broj);

    VektorNd& operator++();
    VektorNd operator++(int);

    bool operator==(const VektorNd &v2);
    bool operator!=(const VektorNd &v2);
    bool operator!();
};


VektorNd::VektorNd(int dimenzija, double vrijednost)
    : dimenzija(dimenzija), koordinate(new double[dimenzija]{}) {

    for (int i = 0; i < dimenzija; i++) {
        koordinate[i] = vrijednost;
    }
}


VektorNd::VektorNd(int dimenzija, double niz[])
    : dimenzija(dimenzija), koordinate(new double[dimenzija]{}) {

    for (int i = 0; i < dimenzija; i++) {
        koordinate[i] = niz[i];
    }
}


VektorNd::~VektorNd() {
    delete[] koordinate;
}


VektorNd::VektorNd(const VektorNd &v)
    : dimenzija(v.dimenzija), koordinate(new double[v.dimenzija]{}) {

    for (int i = 0; i < v.dimenzija; i++) {
        koordinate[i] = v.koordinate[i];
    }
}


VektorNd &VektorNd::operator=(const VektorNd &v) {
    if (this == &v) return *this;

    double* novi = new double[v.dimenzija];

    for (int i = 0; i < v.dimenzija; i++) {
        novi[i] = v.koordinate[i];
    }

    delete[] koordinate;
    koordinate = novi;
    dimenzija = v.dimenzija;

    return *this;
}


double VektorNd::DajVrijednostNaIndeksu(int indeks) const {
    if (indeks > dimenzija || indeks < 1)
        throw std::domain_error("Indeks je van opsega vektora");

    return koordinate[indeks - 1];
}


void VektorNd::PostaviVrijednostNaIndeksu(int indeks, double vrijednost) {
    if (indeks > dimenzija || indeks < 1)
        throw std::domain_error("Indeks je van opsega vektora");

    koordinate[indeks - 1] = vrijednost;
}


double VektorNd::DajDuzinuVektora() const {
    double suma = 0;

    for (int i = 0; i < dimenzija; i++) {
        suma += koordinate[i] * koordinate[i];
    }

    return std::sqrt(suma);
}


double DajDuzinuVektora(const VektorNd &v1) {
    double suma = 0;

    for (int i = 0; i < v1.dimenzija; i++) {
        suma += v1.koordinate[i] * v1.koordinate[i];
    }

    return std::sqrt(suma);
}


int VektorNd::DajRangVektora() const {
    int brojac = 0;

    for (int i = 0; i < dimenzija; i++) {
        if (koordinate[i] != 0)
            brojac++;
    }

    return brojac;
}


VektorNd& VektorNd::Redimenzionriaj(int vrijednost) {
    if (vrijednost <= 0)
        throw std::logic_error("Ilegalan unos");

    if (dimenzija < vrijednost) {

        double* noviVek = new double[vrijednost];

        for (int i = 0; i < dimenzija; i++) {
            noviVek[i] = koordinate[i];
        }

        for (int i = dimenzija; i < vrijednost; i++) {
            noviVek[i] = 0;
        }

        delete[] koordinate;
        koordinate = noviVek;
        dimenzija = vrijednost;

    } else {

        double* noviVek = new double[vrijednost];

        for (int i = 0; i < vrijednost; i++) {
            noviVek[i] = koordinate[i];
        }

        delete[] koordinate;
        koordinate = noviVek;
        dimenzija = vrijednost;
    }

    return *this;
}


VektorNd VektorNd::operator*(double broj) const {
    VektorNd novi(dimenzija);

    for (int i = 0; i < dimenzija; i++) {
        novi.koordinate[i] = koordinate[i] * broj;
    }

    return novi;
}


VektorNd &VektorNd::operator+=(const VektorNd &v) {
    *this = *this + v;
    return *this;
}


VektorNd &VektorNd::operator-=(const VektorNd &v) {
    *this = *this - v;
    return *this;
}


VektorNd &VektorNd::operator*=(double broj) {
    *this = *this * broj;
    return *this;
}


VektorNd& VektorNd::operator++() {
    for (int i = 0; i < dimenzija; i++) {
        ++koordinate[i];
    }

    return *this;
}


VektorNd VektorNd::operator++(int) {
    VektorNd stari = *this;

    for (int i = 0; i < dimenzija; i++) {
        koordinate[i]++;
    }

    return stari;
}


bool VektorNd::operator==(const VektorNd &v2) {
    bool jesuJednaki = true;

    if (dimenzija != v2.dimenzija)
        jesuJednaki = false;

    for (int i = 0; i < dimenzija; i++) {
        if (koordinate[i] != v2.koordinate[i])
            jesuJednaki = false;
    }

    return jesuJednaki;
}


bool VektorNd::operator!=(const VektorNd &v2) {
    bool jesuJednaki = false;

    if (dimenzija != v2.dimenzija)
        jesuJednaki = true;

    for (int i = 0; i < dimenzija; i++) {
        if (koordinate[i] != v2.koordinate[i])
            jesuJednaki = true;
    }

    return jesuJednaki;
}


bool VektorNd::operator!() {
    bool sveNule = true;

    for (int i = 0; i < dimenzija; i++) {
        if (koordinate[i] != 0)
            sveNule = false;
    }

    return sveNule;
}


std::ostream &operator<<(std::ostream &tok, const VektorNd &v) {
    tok << "{";

    for (int i = 0; i < v.dimenzija; i++) {
        tok << v.koordinate[i];

        if (i != v.dimenzija - 1) {
            tok << ", ";
        }
    }

    tok << "}";

    return tok;
}


VektorNd operator+(VektorNd v1, const VektorNd &v2) {
    if (v1.dimenzija != v2.dimenzija)
        throw std::logic_error("Vektori nemaju isti broj koordinata");

    for (int i = 0; i < v1.dimenzija; i++) {
        v1.koordinate[i] += v2.koordinate[i];
    }

    return v1;
}


VektorNd operator-(VektorNd v1, const VektorNd &v2) {
    if (v1.dimenzija != v2.dimenzija)
        throw std::logic_error("Vektori nemaju isti broj koordinata");

    for (int i = 0; i < v1.dimenzija; i++) {
        v1.koordinate[i] -= v2.koordinate[i];
    }

    return v1;
}


double operator*(VektorNd v1, const VektorNd &v2) {
    if (v1.dimenzija != v2.dimenzija)
        throw std::logic_error("Vektori nemaju isti broj koordinata");

    double suma = 0;

    for (int i = 0; i < v1.dimenzija; i++) {
        suma += v1.koordinate[i] * v2.koordinate[i];
    }

    return suma;
}


VektorNd operator*(double broj, const VektorNd &v) {
    return v * broj;
}


int main() {
    double niz1[] = {1, 2, 3};
    double niz2[] = {4, 5, 6};

    VektorNd v1(3, niz1);
    VektorNd v2(3, niz2);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    cout << "Dimenzija v1: " << v1.DajDimenzijuVektora() << endl;
    cout << "Druga koordinata v1: " << v1.DajVrijednostNaIndeksu(2) << endl;

    v1.PostaviVrijednostNaIndeksu(2, 10);
    cout << "v1 nakon postavljanja druge koordinate na 10: " << v1 << endl;

    cout << "Duzina v1: " << v1.DajDuzinuVektora() << endl;
    cout << "Duzina v2 preko prijateljske funkcije: "
         << DajDuzinuVektora(v2) << endl;

    cout << "Rang v1: " << v1.DajRangVektora() << endl;

    VektorNd v3 = v1 + v2;
    cout << "v1 + v2 = " << v3 << endl;

    VektorNd v4 = v1 - v2;
    cout << "v1 - v2 = " << v4 << endl;

    cout << "Skalarni proizvod v1 * v2 = " << v1 * v2 << endl;

    VektorNd v5 = v1 * 2;
    cout << "v1 * 2 = " << v5 << endl;

    VektorNd v6 = 3 * v2;
    cout << "3 * v2 = " << v6 << endl;

    VektorNd v7 = v1;

    v7 += v2;
    cout << "v7 nakon += v2: " << v7 << endl;

    v7 -= v2;
    cout << "v7 nakon -= v2: " << v7 << endl;

    v7 *= 2;
    cout << "v7 nakon *= 2: " << v7 << endl;

    VektorNd v8 = v1;

    cout << "v8 prije ++: " << v8 << endl;
    cout << "++v8 = " << ++v8 << endl;
    cout << "v8 nakon prefiksnog ++: " << v8 << endl;

    VektorNd v9 = v1;

    cout << "v9++ = " << v9++ << endl;
    cout << "v9 nakon postfiksnog ++: " << v9 << endl;

    VektorNd v10 = v1;

    cout << "v1 == v10: " << (v1 == v10) << endl;
    cout << "v1 != v2: " << (v1 != v2) << endl;

    VektorNd nula(3);

    cout << "nula = " << nula << endl;
    cout << "!nula = " << !nula << endl;
    cout << "!v1 = " << !v1 << endl;

    v1.Redimenzionriaj(5);
    cout << "v1 nakon redimenzioniranja na 5: " << v1 << endl;

    v1.Redimenzionriaj(2);
    cout << "v1 nakon redimenzioniranja na 2: " << v1 << endl;

    return 0;
}