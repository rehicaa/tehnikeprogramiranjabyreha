#include <iostream>
#include <stdexcept>
#include <string>

using std::cout, std::cin, std::endl;

class Zivotinja {
public:
    virtual void OglasiSe() const = 0;
    virtual Zivotinja* DajKopiju() const = 0;
    virtual ~Zivotinja() = default;
};

class Krava : public Zivotinja {
public:
    void OglasiSe() const override {
        cout << "Muu!" << endl;
    }
    Zivotinja* DajKopiju() const override {
        return new Krava(*this);
    }
};

class Macka : public Zivotinja {
public:
    void OglasiSe() const override {
        cout << "Mjau!" << endl;
    }
    Zivotinja* DajKopiju() const override {
        return new Macka(*this);
    }
};

class Pas : public Zivotinja {
public:
    void OglasiSe() const override {
        cout << "Av!" << endl;
    }
    Zivotinja* DajKopiju() const override {
        return new Pas(*this);
    }
};

class PolimorfnaZivotinja {
    Zivotinja* zivotinja;
public:
    PolimorfnaZivotinja() : zivotinja(nullptr) {}

    PolimorfnaZivotinja(const Zivotinja &z) : zivotinja(z.DajKopiju()) {}

    ~PolimorfnaZivotinja() {
        delete zivotinja;
    }

    PolimorfnaZivotinja(const PolimorfnaZivotinja &pz) {
        if (pz.zivotinja) zivotinja = pz.zivotinja->DajKopiju();
        else zivotinja = nullptr;
    }

    PolimorfnaZivotinja(PolimorfnaZivotinja &&pz) noexcept : zivotinja(pz.zivotinja) {
        pz.zivotinja = nullptr;
    }

    PolimorfnaZivotinja &operator=(const Zivotinja &z) {
        Zivotinja* nova = z.DajKopiju();
        delete zivotinja;
        zivotinja = nova;
        return *this;
    }

    PolimorfnaZivotinja &operator=(const PolimorfnaZivotinja &pz) {
        if (&pz == this) return *this;
        Zivotinja* nova = nullptr;
        if (pz.zivotinja) nova = pz.zivotinja->DajKopiju();
        delete zivotinja;
        zivotinja = nova;
        return *this;
    }

    PolimorfnaZivotinja &operator=(PolimorfnaZivotinja &&pz) noexcept {
        if (&pz == this) return *this;
        delete zivotinja;
        zivotinja = pz.zivotinja;
        pz.zivotinja = nullptr;
        return *this;
    }

    void OglasiSe() const {
        if (zivotinja == nullptr) {
            throw std::logic_error("Nepoznata vrsta zivotinje");
        }
        zivotinja->OglasiSe();
    }
};

int main() {
    PolimorfnaZivotinja pz1;

    try {
        pz1.OglasiSe();
    } catch (const std::logic_error& e) {
        cout << "Izuzetak uhvacen: " << e.what() << endl;
    }

    pz1 = Pas();
    cout << "Nakon dodjele psa: ";
    pz1.OglasiSe();

    pz1 = Macka();
    cout << "Nakon dodjele macke: ";
    pz1.OglasiSe();

    PolimorfnaZivotinja pz2 = Krava();
    PolimorfnaZivotinja pz3 = pz2;

    cout << "Kopirana krava: ";
    pz3.OglasiSe();

    return 0;
}