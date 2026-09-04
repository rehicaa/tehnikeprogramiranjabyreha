#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Razlomak {
    int brojnik = 0;
    int nazivnik = 1;
    void Skrati() {
        for (int i = 2; i <= std::abs(nazivnik); i++) {
            while ((brojnik % i == 0) && (nazivnik % i == 0)) {
                brojnik /= i;
                nazivnik /= i;
            }
        }
        if (nazivnik < 0) {
            brojnik = -brojnik;
            nazivnik = -nazivnik;
        }
    }
public:
    Razlomak() = default;
    Razlomak (int brojnik, int nazivnik = 1) : brojnik(brojnik), nazivnik(nazivnik) {
        if (nazivnik == 0) throw std::logic_error("Dijeljenje s 0 je zabranjeno.");
    }
    Razlomak &operator+=(const Razlomak &r) {
        this->brojnik = (this->brojnik * r.nazivnik) + (r.brojnik * this->nazivnik);
        this->nazivnik*=r.nazivnik;
        return *this;
    }

    Razlomak &operator++() {
        this->brojnik+=this->nazivnik;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& tok, const Razlomak &r);
    friend bool operator==(const Razlomak &r1, const Razlomak &r2);
    friend std::istream& operator >>(std::istream& tok, Razlomak &r);

    explicit operator double() const {
        return (double)brojnik/nazivnik;
    }

    double operator ()(double x) const {
        return x * (double)brojnik/nazivnik;
    }


};

std::ostream& operator<<(std::ostream &tok, const Razlomak &r) {
    tok << r.brojnik << "/" << r.nazivnik;
    return tok;
}

Razlomak operator +(Razlomak r1, const Razlomak &r2) {
    r1 += r2;
    return r1;
}

bool operator==(const Razlomak &r1, const Razlomak &r2) {
    return r1.brojnik * r2.nazivnik == r2.brojnik * r1.nazivnik;
}

std::istream &operator>>(std::istream &tok, Razlomak &r) {
    char znak;
    tok >> r.brojnik >> znak >> r.nazivnik;
    if (znak != '/') tok.setstate(std::ios::failbit);
    if (r.nazivnik == 0) throw std::logic_error("Dijeljenje s nulom je zabranjeno");
    return tok;
}

int main() {
    try {
        Razlomak r1(1, 2); // 1/2
        Razlomak r2(1, 4); // 1/4

        cout << "r1: " << r1 << ", r2: " << r2 << endl;

        Razlomak suma = r1 + r2;
        cout << "r1 + r2 = " << suma << " (trebalo bi biti 6/8)" << endl;

        if (r1 == Razlomak(2, 4)) {
            cout << "Operator == radi (1/2 je isto sto i 2/4)" << endl;
        }

        ++r1;
        cout << "Nakon ++r1: " << r1 << " (trebalo bi biti 3/2)" << endl;

        r2 += r1;
        cout << "Nakon r2 += r1: " << r2 << " (1/4 + 3/2 = 14/8)" << endl;

        Razlomak r3;
        cout << "Unesite razlomak (format x/y): "; cin >> r3; cout << endl;
        cout << "Razlomak koji ste unijeli: " << r3 << endl;

        cout << "Razlomak u decimalama: " << (double)r3 << endl;

        cout << "Unesite broj kojim zelite pomnoziti uneseni razlomak: "; int x; cin >>x; cout << endl;
        cout << "Pomnozeni razlomak u decimalama: " << r3(x) << endl;

    } catch (const std::logic_error& e) {
        cout << "Greska: " << e.what() << endl;
    }

    return 0;
}