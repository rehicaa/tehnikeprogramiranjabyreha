#include <iostream>
#include <stdexcept>

using std::cout, std::cin, std::endl;

class Polinom {
    int stepen;
    double *koeficijenti;

public:
    explicit Polinom(int stepen = 0) {
        if (stepen < 0)
            throw std::domain_error("Neispravan stepen polinoma");

        this->stepen = stepen;
        koeficijenti = new double[stepen + 1]{};
    }

    ~Polinom() {
        delete[] koeficijenti;
    }

    Polinom(const Polinom &p)
        : stepen(p.stepen),
          koeficijenti(new double[p.stepen + 1]{}) {

        for (int i = 0; i <= stepen; i++)
            koeficijenti[i] = p.koeficijenti[i];
    }

    Polinom &operator=(const Polinom &p) {
        if (this == &p)
            return *this;

        double *novi = new double[p.stepen + 1];

        for (int i = 0; i <= p.stepen; i++)
            novi[i] = p.koeficijenti[i];

        delete[] koeficijenti;

        koeficijenti = novi;
        stepen = p.stepen;

        return *this;
    }

    Polinom &operator=(double broj) {
        double *novi = new double[1];
        novi[0] = broj;

        delete[] koeficijenti;

        koeficijenti = novi;
        stepen = 0;

        return *this;
    }

    double &operator[](int indeks) {
        if (indeks < 0 || indeks > stepen)
            throw std::range_error("Neispravan indeks koeficijenta");

        return koeficijenti[indeks];
    }

    double operator[](int indeks) const {
        if (indeks < 0 || indeks > stepen)
            throw std::range_error("Neispravan indeks koeficijenta");

        return koeficijenti[indeks];
    }

    double operator()(double x) const {
        double rez = 0;
        double stepenX = 1;

        for (int i = 0; i <= stepen; i++) {
            rez += koeficijenti[i] * stepenX;
            stepenX *= x;
        }

        return rez;
    }

    Polinom &operator+=(const Polinom &p) {
        if (p.stepen <= stepen) {
            for (int i = 0; i <= p.stepen; i++)
                koeficijenti[i] += p.koeficijenti[i];
        } else {
            double *novi = new double[p.stepen + 1]{};

            for (int i = 0; i <= stepen; i++)
                novi[i] = koeficijenti[i] + p.koeficijenti[i];

            for (int i = stepen + 1; i <= p.stepen; i++)
                novi[i] = p.koeficijenti[i];

            delete[] koeficijenti;

            koeficijenti = novi;
            stepen = p.stepen;
        }

        return *this;
    }

    Polinom &operator+=(double broj) {
        koeficijenti[0] += broj;
        return *this;
    }

    Polinom &operator-=(const Polinom &p) {
        if (p.stepen <= stepen) {
            for (int i = 0; i <= p.stepen; i++)
                koeficijenti[i] -= p.koeficijenti[i];
        } else {
            double *novi = new double[p.stepen + 1]{};

            for (int i = 0; i <= stepen; i++)
                novi[i] = koeficijenti[i] - p.koeficijenti[i];

            for (int i = stepen + 1; i <= p.stepen; i++)
                novi[i] = -p.koeficijenti[i];

            delete[] koeficijenti;

            koeficijenti = novi;
            stepen = p.stepen;
        }

        return *this;
    }

    Polinom &operator*=(const Polinom &p) {
        int noviStepen = stepen + p.stepen;

        double *novi = new double[noviStepen + 1]{};

        for (int i = 0; i <= stepen; i++) {
            for (int j = 0; j <= p.stepen; j++) {
                novi[i + j] +=
                    koeficijenti[i] * p.koeficijenti[j];
            }
        }

        delete[] koeficijenti;

        koeficijenti = novi;
        stepen = noviStepen;

        return *this;
    }

    Polinom operator-() const {
        Polinom rezultat(*this);

        for (int i = 0; i <= rezultat.stepen; i++)
            rezultat.koeficijenti[i] =
                -rezultat.koeficijenti[i];

        return rezultat;
    }

    Polinom &operator++() {
        for (int i = 0; i <= stepen; i++)
            koeficijenti[i]++;

        return *this;
    }

    Polinom operator++(int) {
        Polinom stari(*this);

        ++(*this);

        return stari;
    }

    explicit operator bool() const {
        for (int i = 0; i <= stepen; i++) {
            if (koeficijenti[i] != 0)
                return true;
        }

        return false;
    }

    bool operator!() const {
        return !static_cast<bool>(*this);
    }

    friend bool operator==(const Polinom &p1,
                           const Polinom &p2);

    friend bool operator<(const Polinom &p1,
                          const Polinom &p2);

    friend std::ostream &operator<<(std::ostream &tok,
                                    const Polinom &p);

    friend std::istream &operator>>(std::istream &tok,
                                    Polinom &p);
};

Polinom operator+(Polinom p1, const Polinom &p2) {
    p1 += p2;
    return p1;
}

Polinom operator+(Polinom p, double broj) {
    p += broj;
    return p;
}

Polinom operator+(double broj, Polinom p) {
    p += broj;
    return p;
}

Polinom operator-(Polinom p1, const Polinom &p2) {
    p1 -= p2;
    return p1;
}

Polinom operator*(Polinom p1, const Polinom &p2) {
    p1 *= p2;
    return p1;
}

bool operator==(const Polinom &p1, const Polinom &p2) {
    int stepen1 = p1.stepen;
    int stepen2 = p2.stepen;

    while (stepen1 > 0 &&
           p1.koeficijenti[stepen1] == 0)
        stepen1--;

    while (stepen2 > 0 &&
           p2.koeficijenti[stepen2] == 0)
        stepen2--;

    if (stepen1 != stepen2)
        return false;

    for (int i = 0; i <= stepen1; i++) {
        if (p1.koeficijenti[i] !=
            p2.koeficijenti[i])
            return false;
    }

    return true;
}

bool operator!=(const Polinom &p1,
                const Polinom &p2) {
    return !(p1 == p2);
}

bool operator<(const Polinom &p1,
               const Polinom &p2) {

    int stepen1 = p1.stepen;
    int stepen2 = p2.stepen;

    while (stepen1 > 0 &&
           p1.koeficijenti[stepen1] == 0)
        stepen1--;

    while (stepen2 > 0 &&
           p2.koeficijenti[stepen2] == 0)
        stepen2--;

    if (stepen1 != stepen2)
        return stepen1 < stepen2;

    for (int i = stepen1; i >= 0; i--) {
        if (p1.koeficijenti[i] <
            p2.koeficijenti[i])
            return true;

        if (p1.koeficijenti[i] >
            p2.koeficijenti[i])
            return false;
    }

    return false;
}

bool operator>(const Polinom &p1,
               const Polinom &p2) {
    return p2 < p1;
}

bool operator<=(const Polinom &p1,
                const Polinom &p2) {
    return !(p2 < p1);
}

bool operator>=(const Polinom &p1,
                const Polinom &p2) {
    return !(p1 < p2);
}

std::ostream &operator<<(std::ostream &tok,
                         const Polinom &p) {

    tok << "{";

    for (int i = 0; i <= p.stepen; i++) {
        tok << p.koeficijenti[i];

        if (i != p.stepen)
            tok << ", ";
    }

    tok << "}";

    return tok;
}

std::istream &operator>>(std::istream &tok,
                         Polinom &p) {

    int noviStepen;

    tok >> noviStepen;

    if (!tok)
        return tok;

    if (noviStepen < 0) {
        tok.setstate(std::ios::failbit);
        return tok;
    }

    Polinom novi(noviStepen);

    for (int i = 0; i <= noviStepen; i++) {
        tok >> novi.koeficijenti[i];

        if (!tok)
            return tok;
    }

    p = novi;

    return tok;
}

int main() {
    try {
        Polinom p(2);

        p[0] = 1;
        p[1] = 2;
        p[2] = 3;

        Polinom q(1);

        q[0] = 4;
        q[1] = -1;

        cout << "p = " << p << endl;
        cout << "q = " << q << endl;

        cout << "p(2) = " << p(2) << endl;

        cout << "p + q = " << p + q << endl;
        cout << "p + 5 = " << p + 5 << endl;
        cout << "5 + p = " << 5 + p << endl;

        cout << "p * q = " << p * q << endl;

        cout << "-p = " << -p << endl;
        cout << "p - q = " << p - q << endl;

        Polinom prije = p++;

        cout << "prije p++ = " << prije << endl;
        cout << "poslije p++ = " << p << endl;

        cout << "poslije ++p = " << ++p << endl;

        Polinom a(1);
        Polinom b(3);

        a[0] = 1;
        a[1] = 2;

        b[0] = 1;
        b[1] = 2;
        b[2] = 0;
        b[3] = 0;

        cout << std::boolalpha;
        cout << "a == b: " << (a == b) << endl;

        Polinom nula(3);

        cout << "!nula = " << !nula << endl;

        q = 7;

        cout << "q = " << q << endl;

        Polinom r(1);

        r[0] = 1;
        r[1] = 1;

        r *= r;

        cout << "(1+x)^2 = " << r << endl;
    }
    catch (const std::exception &e) {
        cout << "GRESKA: " << e.what() << endl;
    }

    return 0;
}