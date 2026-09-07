#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Proizvod {
    string naziv;
    double cijena;

public:
    Proizvod(string naziv, double cijena) : naziv(naziv), cijena(cijena) {
    }

    string DajNaziv() const { return naziv; }
    double DajCijenu() const { return cijena; }

    virtual void Ispisi() const {
        cout << "Ime proizvoda: " << DajNaziv() << endl;
        cout << "Cijena: " << DajCijenu() << endl;
        cout << "Cijena s popustom: " << DajCijenuSaPopustom() << endl;
    }

    virtual ~Proizvod() = default;
    virtual double DajCijenuSaPopustom() const = 0;
    virtual std::unique_ptr<Proizvod> DajKopiju() const = 0;
};

class PrehrambeniProizvod : public Proizvod {
    int rok_trajanja;

public:
    PrehrambeniProizvod(string naziv, double cijena, int rok_trajanja)
        : Proizvod(naziv, cijena), rok_trajanja(rok_trajanja) {
    }

    int DajRokTrajanja() const { return rok_trajanja; }

    void Ispisi() const override {
        Proizvod::Ispisi();
        cout << "Rok trajanja: " << DajRokTrajanja() << endl;
    }

    bool JeSkupljiOd(double granica) const {
        return (DajCijenu() > granica);
    }

    double DajCijenuSaPopustom() const override {
        if (rok_trajanja <= 3) {
            return DajCijenu() - (DajCijenu() * 0.30);
        }
        return DajCijenu();
    }

    std::unique_ptr<Proizvod> DajKopiju() const override {
        return std::make_unique<PrehrambeniProizvod>(*this);
    }
};

class ElektronskiProizvod : public Proizvod {
    int garancija;

public:
    ElektronskiProizvod(string naziv, double cijena, int garancija) : Proizvod(naziv, cijena), garancija(garancija) {
    }

    int DajGaranciju() const { return garancija; }

    void Ispisi() const override {
        Proizvod::Ispisi();
        cout << "Garancija (u mjesecima): " << DajGaranciju() << endl;
    }

    double DajCijenuSaPopustom() const override {
        return DajCijenu() - (DajCijenu() * 0.10);
    }

    std::unique_ptr<Proizvod> DajKopiju() const override {
        return std::make_unique<ElektronskiProizvod>(*this);
    }
};

class Odjeca : public Proizvod {
    string velicina;
    bool na_akciji;

public:
    Odjeca(string naziv, double cijena, string velicina, bool na_akciji) : Proizvod(naziv, cijena), velicina(velicina),
                                                                           na_akciji(na_akciji) {
    }

    double DajCijenuSaPopustom() const override {
        if (na_akciji) return (DajCijenu() - (DajCijenu() * 0.20));
        return DajCijenu();
    }

    void Ispisi() const override {
        Proizvod::Ispisi();
        cout << "Velicina: " << velicina << endl;
        na_akciji ? cout << "Artikal je na akciji." << endl : cout << "Artikal nije na akciji." << endl;
    }

    std::unique_ptr<Proizvod> DajKopiju() const override {
        return std::make_unique<Odjeca>(*this);
    }
};

class Prodavnica {
    vector<std::unique_ptr<Proizvod>> proizvodi;
public:
    void DodajProizvod(std::unique_ptr<Proizvod> p) {
        if (p == nullptr) throw std::invalid_argument("Nema proizvoda");
        proizvodi.push_back(std::move(p));
    }
    void IspisiSve() const {
        for (int i = 0; i < proizvodi.size(); i++) {
            proizvodi[i]->Ispisi();
        }
    }
    double DajUkupnuCijenu() const {
        double suma = 0;
        for (int i = 0; i < proizvodi.size(); i++) {
            suma += proizvodi[i]->DajCijenuSaPopustom();
        }
        return suma;
    }
    const Proizvod* DajNajjeftiniji() const {
        const Proizvod *najjeftiniji = nullptr;
        for (int i = 0; i < proizvodi.size(); i++) {
            if (najjeftiniji == nullptr || najjeftiniji->DajCijenuSaPopustom() > proizvodi[i]->DajCijenuSaPopustom()) {
                najjeftiniji = proizvodi[i].get();
            }
        }
        return najjeftiniji;
    }
    void ObrisiProizvod(int indeks) {
        if (indeks < 0 || indeks >= proizvodi.size()) throw std::range_error("Indeks van opsega niza.");
        proizvodi.erase(proizvodi.begin() + indeks);
    }
    Prodavnica() = default;
    Prodavnica(const Prodavnica &p) {
        for (int i = 0; i < p.proizvodi.size(); i++) {
            proizvodi.push_back(p.proizvodi[i]->DajKopiju());
        }
    }
    Prodavnica &operator=(const Prodavnica &p) {
        if (this == &p) return *this;
        Prodavnica nova = p;
        proizvodi.swap(nova.proizvodi);
        return *this;
    }
    Prodavnica(Prodavnica &&p) noexcept = default;
    Prodavnica &operator=(Prodavnica &&p) noexcept = default;

    void SortirajPoCijeni() {
        std::sort(proizvodi.begin(), proizvodi.end(),
            [](const auto &a, const auto &b) {
                if (a->DajCijenuSaPopustom() == b->DajCijenuSaPopustom()) {
                    return a->DajNaziv() < b->DajNaziv();
                } else {
                    return a->DajCijenuSaPopustom() < b->DajCijenuSaPopustom();
                }
            });
    }
};

void PrikaziProizvod(const Proizvod *p) {
    if (p != nullptr) {
        p->Ispisi();
    } else {
        cout << "Nema proizvoda.";
    }
}

double DajUkupnuCijenu(const vector<const Proizvod *> &p) {
    double suma = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] != nullptr) {
            suma += p[i]->DajCijenuSaPopustom();
        }
    }
    return suma;
}

const Proizvod *DajNajjeftiniji(const vector<const Proizvod *> &proizvodi) {
    if (proizvodi.size() == 0) return nullptr;
    const Proizvod *p = nullptr;
    for (int i = 0; i < proizvodi.size(); i++) {
        if (proizvodi[i] == nullptr) continue;
        if (p == nullptr || p->DajCijenuSaPopustom() > proizvodi[i]->DajCijenuSaPopustom()) p = proizvodi[i];
    }
    return p;
}

int main() {
    Prodavnica prodavnica;

    prodavnica.DodajProizvod(
        std::make_unique<ElektronskiProizvod>("Monitor", 300, 24)
    );

    auto majica = std::make_unique<Odjeca>("Majica", 20, "L", true);
    prodavnica.DodajProizvod(std::move(majica));

    prodavnica.IspisiSve();

    cout << "Ukupno: " << prodavnica.DajUkupnuCijenu();

    cout << "Ukupno: " << prodavnica.DajUkupnuCijenu() << endl;
    cout << "Najjeftiniji proizvod:" << endl;
    PrikaziProizvod(prodavnica.DajNajjeftiniji());

    prodavnica.ObrisiProizvod(0);
    prodavnica.IspisiSve();
}
