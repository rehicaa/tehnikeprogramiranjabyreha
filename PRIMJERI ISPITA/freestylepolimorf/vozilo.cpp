#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Vozilo {
    int tezina;
public:
    Vozilo(int tezina) : tezina(tezina){}
    int DajTezinu() const {return tezina;}
    virtual int DajUkupnuTezinu() const = 0;
    virtual Vozilo *DajKopiju() const = 0;
    virtual void IspisiPodatke() const = 0;
    virtual ~Vozilo() = default;
};

class Automobil : public Vozilo {
    vector<int> tezina_putnika;
public:
    Automobil(int tezina, vector<int> tezina_putnika) : Vozilo(tezina), tezina_putnika(tezina_putnika){}
    int DajUkupnuTezinu() const override {
        int ukupna_tezina_putnika = 0;
        for (int i = 0; i < tezina_putnika.size(); i++) {
            ukupna_tezina_putnika += tezina_putnika[i];
        }
        return DajTezinu() + ukupna_tezina_putnika;
    }
    Vozilo *DajKopiju() const override {
        return new Automobil(*this);
    }
    void IspisiPodatke() const override {
        cout << "Vrsta vozila: Automobil" << endl
        << "Vlastita tezina: " << DajTezinu() << endl
        << "Tezine putnika : ";
        for (int i = 0; i < tezina_putnika.size(); i++) {
            cout << tezina_putnika[i] << " kg";
            if (i != tezina_putnika.size() - 1) cout << ",";
        }
        cout << endl << "Ukupna tezina: " << DajUkupnuTezinu() << " kg" << endl;
    }
};

class Kamion : public Vozilo {
    int tezina_tereta;
public:
    Kamion(int tezina, int tezina_tereta) : Vozilo(tezina), tezina_tereta(tezina_tereta){}
    int DajUkupnuTezinu() const override {
        return DajTezinu() + tezina_tereta;
    }
    Vozilo *DajKopiju() const override {
        return new Kamion(*this);
    }
    void IspisiPodatke() const override {
        cout << "Vrsta vozila: Kamion" << endl
        << "Vlastita tezina: " << DajTezinu() << endl
        << "Tezina tereta: " << tezina_tereta << endl
        << "Ukupna tezina: " << DajUkupnuTezinu() << endl;
    }
};

class Autobus : public Vozilo {
    int broj_putnika;
    int prosjecna_tezina;
public:
    Autobus(int tezina, int broj_putnika, int prosjecna_tezina) : Vozilo(tezina), broj_putnika(broj_putnika), prosjecna_tezina(prosjecna_tezina){}
    Vozilo *DajKopiju() const override {
        return new Autobus(*this);
    }
    int DajUkupnuTezinu() const override {
        return DajTezinu() + (broj_putnika * prosjecna_tezina);
    }
    void IspisiPodatke() const override {
        cout << "Vrsta vozila: Autobus" << endl
        << "Vlastita tezina: " << DajTezinu() << endl
        << "Broj putnika: " << broj_putnika << endl
        << "Prosjecna tezina putnika: " << prosjecna_tezina << endl
        << "Ukupna tezina: " << DajUkupnuTezinu() << endl;
    }
};

class Parking {
    vector<std::shared_ptr<Vozilo>> vozila;
public:
    Parking() = default;
    Parking(const Parking &p) {
        for (int i = 0; i < p.vozila.size(); i++) {
            vozila.push_back(std::shared_ptr<Vozilo>(p.vozila[i]->DajKopiju()));
        }
    }
    Parking &operator=(const Parking &p) {
        if (&p == this) return *this;
        Parking novi = p;
        vozila.erase(vozila.begin(), vozila.end());
        vozila = std::move(novi.vozila);

        return *this;
    }
    Parking(Parking &&p) : vozila(std::move(p.vozila)){}
    Parking &operator= (Parking &&p) {
        if (&p == this) return *this;
        vozila = std::move(p.vozila);

        return *this;
    }
    Parking& DodajAutomobil(int tezina, vector<int>tezina_putnika) {
        vozila.push_back(std::make_shared<Automobil>(tezina, tezina_putnika));
        return *this;
    }
    Parking& DodajKamion(int tezina, int tezina_tereta) {
        vozila.push_back((std::make_shared<Kamion>(tezina, tezina_tereta)));
        return *this;
    }
    Parking& DodajAutobus(int tezina, int broj_putnika, int prosjecna_tezina_putnika) {
        vozila.push_back(std::make_shared<Autobus>(tezina, broj_putnika, prosjecna_tezina_putnika));
        return *this;
    }
    Parking& DodajVozilo(const Vozilo &v) {
        vozila.push_back(std::shared_ptr<Vozilo>(v.DajKopiju()));
        return *this;
    }
    void IspisiSve() const {
        for (int i = 0; i < vozila.size(); i++) {
            vozila[i]->IspisiPodatke();
        }
    }
};

int main() {
    Parking p;

    p.DodajAutomobil(1200, {70, 85, 60});
    p.DodajKamion(5000, 2500);
    p.DodajAutobus(8000, 40, 75);

    cout << "=== PARKING P ===" << endl;
    p.IspisiSve();

    Parking p2(p);

    cout << endl << "=== PARKING P2 - COPY CONSTRUCTOR ===" << endl;
    p2.IspisiSve();

    Parking p3;
    p3 = p;

    cout << endl << "=== PARKING P3 - COPY ASSIGNMENT ===" << endl;
    p3.IspisiSve();

    Kamion k(4000, 1500);
    p.DodajVozilo(k);

    cout << endl << "=== P NAKON DODAJVOZILO ===" << endl;
    p.IspisiSve();

    Parking p4(std::move(p2));

    cout << endl << "=== PARKING P4 - MOVE CONSTRUCTOR ===" << endl;
    p4.IspisiSve();

    Parking p5;
    p5 = std::move(p3);

    cout << endl << "=== PARKING P5 - MOVE ASSIGNMENT ===" << endl;
    p5.IspisiSve();

    return 0;
}