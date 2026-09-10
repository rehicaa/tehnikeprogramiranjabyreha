#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Zivotinja {
public:
    virtual void OglasiSe () const = 0;
    virtual Zivotinja *DajKopiju () const = 0;
    virtual ~Zivotinja() = default;
};
class Pas : public Zivotinja {
public:
    void OglasiSe() const override {
        cout << "Av!" << endl;
    }
    Zivotinja *DajKopiju () const override {
        return new Pas(*this);
    }
};
class Krava : public Zivotinja {
public:
    void OglasiSe() const override {
        cout << "Muu!" << endl;
    }
    Zivotinja *DajKopiju() const override {
        return new Krava (*this);
    }
};
class Macka : public Zivotinja {
public:
    void OglasiSe() const override {
        cout << "Mjau!" << endl;
    }
    Zivotinja *DajKopiju() const override {
        return new Macka (*this);
    }
};

class PolimorfnaZivotinja {
    Zivotinja *zivotinja;
public:
    PolimorfnaZivotinja() : zivotinja(nullptr){}
    ~PolimorfnaZivotinja(){
        delete zivotinja;
    }
    void OglasiSe() {
        if (zivotinja == nullptr) throw std::logic_error("Nepoznata vrsta životinje");
        zivotinja->OglasiSe();
    }2
    PolimorfnaZivotinja& operator=(const Zivotinja &z) {
        Zivotinja *nova = z.DajKopiju();

        delete zivotinja;
        zivotinja = nova;

        return *this;
    }
    PolimorfnaZivotinja& operator=(PolimorfnaZivotinja &z) {
        if (this == &z) return *this;
        if (z.zivotinja == nullptr) throw std::logic_error("Zivotinja ne postoji");
        Zivotinja *nova = z.zivotinja->DajKopiju();
        delete zivotinja;
        zivotinja = nova;

        return *this;
    }
};

int main() {
    return 0;
}