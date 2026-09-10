#include <iostream>
#include <stdexcept>
#include <utility>

class CjelobrojniRed {
    struct Cvor {
        int element;
        Cvor *veza;
    };

    Cvor *pocetak;
    Cvor *kraj;

    void Validiraj() const {
        if (pocetak == nullptr)
            throw std::logic_error("Red je prazan");
    }

    void Obrisi() {
        while (pocetak != nullptr) {
            Cvor *temp = pocetak;
            pocetak = pocetak->veza;
            delete temp;
        }

        kraj = nullptr;
    }

public:
    CjelobrojniRed() : pocetak(nullptr), kraj(nullptr) {}

    ~CjelobrojniRed() {
        Obrisi();
    }

    CjelobrojniRed(const CjelobrojniRed &r)
        : pocetak(nullptr), kraj(nullptr) {
        try {
            Cvor *temp = r.pocetak;

            while (temp != nullptr) {
                *this += temp->element;
                temp = temp->veza;
            }
        } catch (...) {
            Obrisi();
            throw;
        }
    }

    CjelobrojniRed &operator=(const CjelobrojniRed &r) {
        if (this == &r)
            return *this;

        CjelobrojniRed novi(r);

        std::swap(pocetak, novi.pocetak);
        std::swap(kraj, novi.kraj);

        return *this;
    }

    CjelobrojniRed(CjelobrojniRed &&r)
        : pocetak(r.pocetak), kraj(r.kraj) {
        r.pocetak = nullptr;
        r.kraj = nullptr;
    }

    CjelobrojniRed &operator=(CjelobrojniRed &&r) {
        if (this == &r)
            return *this;

        Obrisi();

        pocetak = r.pocetak;
        kraj = r.kraj;

        r.pocetak = nullptr;
        r.kraj = nullptr;

        return *this;
    }

    CjelobrojniRed &operator+=(int element) {
        Cvor *novi = new Cvor{element, nullptr};

        if (pocetak == nullptr)
            pocetak = novi;
        else
            kraj->veza = novi;

        kraj = novi;

        return *this;
    }

    int &operator*() {
        Validiraj();
        return pocetak->element;
    }

    const int &operator*() const {
        Validiraj();
        return pocetak->element;
    }

    int &operator~() {
        Validiraj();
        return kraj->element;
    }

    const int &operator~() const {
        Validiraj();
        return kraj->element;
    }

    CjelobrojniRed &operator--() {
        Validiraj();

        Cvor *temp = pocetak;
        pocetak = pocetak->veza;

        delete temp;

        if (pocetak == nullptr)
            kraj = nullptr;

        return *this;
    }

    CjelobrojniRed operator--(int) {
        Validiraj();

        CjelobrojniRed stari(*this);
        --(*this);

        return stari;
    }

    bool operator!() const {
        return pocetak != nullptr;
    }

    int operator+() const {
        int brojac = 0;
        Cvor *temp = pocetak;

        while (temp != nullptr) {
            brojac++;
            temp = temp->veza;
        }

        return brojac;
    }

    CjelobrojniRed &operator*=(int broj) {
        Cvor *temp = pocetak;

        while (temp != nullptr) {
            temp->element *= broj;
            temp = temp->veza;
        }

        return *this;
    }

    friend CjelobrojniRed operator+(const CjelobrojniRed &r1,
                                    const CjelobrojniRed &r2) {
        if (+r1 != +r2)
            throw std::domain_error("Redovi nisu iste velicine");

        CjelobrojniRed rezultat;

        Cvor *p1 = r1.pocetak;
        Cvor *p2 = r2.pocetak;

        while (p1 != nullptr) {
            rezultat += p1->element + p2->element;

            p1 = p1->veza;
            p2 = p2->veza;
        }

        return rezultat;
    }

    friend std::ostream &operator<<(std::ostream &tok,
                                    const CjelobrojniRed &r) {
        Cvor *temp = r.pocetak;

        while (temp != nullptr) {
            tok << temp->element;

            if (temp->veza != nullptr)
                tok << ",";

            temp = temp->veza;
        }

        return tok;
    }
};

int main() {
    CjelobrojniRed s;

    s += 3;
    s += 1;
    s += 5;
    s += 2;
    s += 4;

    while (!s)
        std::cout << *(s--) << " ";

    return 0;
}