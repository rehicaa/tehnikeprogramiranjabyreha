#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <stdexcept>
#include <string.h>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Album;

class Pjesma {
    string naslov, izvodjac;
    int trajanje;
public:
    Pjesma (string naslov, string izvodjac, int trajanje) : naslov(naslov), izvodjac(izvodjac), trajanje(trajanje) {
        if (trajanje < 0 || trajanje > 3600) throw std::domain_error("Nerealno trajanje.");
    }

    friend class Album;
};

class Album {
    Pjesma** pjesme;
    int max_pjesama;
    int trenutno_pjesama;
public:
    Album(int max_pjesama) : max_pjesama(max_pjesama), trenutno_pjesama(0), pjesme(new Pjesma*[max_pjesama]{}){}
    ~Album() {
        for (int i = 0; i < trenutno_pjesama; i++) {
            delete pjesme[i];
        }
        delete[] pjesme;
    }
    Album(const Album &drugi) {
        this->max_pjesama = drugi.max_pjesama;
        this->trenutno_pjesama = drugi.trenutno_pjesama;
        try {
            pjesme = new Pjesma *[drugi.max_pjesama]{};
            for (int i = 0; i < drugi.trenutno_pjesama; i++) {
                this->pjesme[i] = new Pjesma(*drugi.pjesme[i]);
            }
        } catch (...) {
            for (int i = 0; i < max_pjesama; i++) {
                delete pjesme[i];
            }
            delete[] pjesme;
            throw;
        }
    }
    Album &operator=(const Album &drugi) {
        if (this == &drugi) return *this;

        Pjesma** novi = nullptr;
        try {
            novi = new Pjesma*[drugi.trenutno_pjesama]{};
            for (int i = 0; i < drugi.trenutno_pjesama; i++) {
                novi[i] = new Pjesma(*drugi.pjesme[i]);
            }
        } catch (...) {
            if (novi != nullptr) {
                for (int i = 0; i < drugi.max_pjesama; i++) {
                    delete novi[i];
                }
                delete[] novi;
            }
            throw;
        }

        for (int i = 0; i < max_pjesama; i++) {
            delete pjesme[i];
        }
        delete[] pjesme;

        pjesme = novi;
        max_pjesama = drugi.max_pjesama;
        trenutno_pjesama = drugi.trenutno_pjesama;

        return *this;
    }

    Album &operator=(Album &&drugi){
        if (this == &drugi) return *this;

        for (int i = 0; i < max_pjesama; i++) delete pjesme[i];
        delete[] pjesme;

        this->max_pjesama = drugi.max_pjesama;
        this->trenutno_pjesama = drugi.trenutno_pjesama;
        this->pjesme = drugi.pjesme;

        drugi.max_pjesama = 0;
        drugi.trenutno_pjesama = 0;
        drugi.pjesme = nullptr;

        return *this;
    }

    void DodajPesmu(string naslov, string izvodjac, int trajanje);
    void SvirajSve() const;
    int UkupnoTrajanje() const;
};

void Album::DodajPesmu(string naslov, string izvodjac, int trajanje) {
    if (trenutno_pjesama >= max_pjesama) throw std::range_error("Ovaj album je popunjen.");
    pjesme[trenutno_pjesama] = new Pjesma(naslov, izvodjac, trajanje);
    trenutno_pjesama++;
}

void Album::SvirajSve() const {
    for (int i = 0; i < trenutno_pjesama; i++) {
        cout << "Ime pjesme: " << pjesme[i]->naslov << endl;
        cout << "Ime izvodjaca: " << pjesme[i]->izvodjac << endl;
        cout << "Trajanje pjesme: " << pjesme[i]->trajanje << "s" << endl;
    }
}

int Album::UkupnoTrajanje() const {
    int suma = 0;
    for (int i = 0; i < trenutno_pjesama; i++) {
        suma+=pjesme[i]->trajanje;
    }

    return suma;
}

int main() {
    try {
        Album Currents(4);
        for (int i = 0; i < 3; i++) {
            string naslov, izvodjac; int trajanje;
            cout << "Unesite naslov pjesme: "; std::getline(cin, naslov); cout << endl;
            cout << "Unesite ime izvodjaca: "; std::getline(cin, izvodjac); cout << endl;
            cout << "Unesite trajanje pjesme (u sekundama): "; cin >> trajanje; cout << endl;
            cin.ignore (10000, '\n');
            Currents.DodajPesmu(naslov, izvodjac, trajanje);
        }

        Currents.SvirajSve();
        cout << endl;
        cout << "Ukupno trajanje albuma: " << Currents.UkupnoTrajanje() << endl;

        Album a2 = Currents;
        cout << endl;
        a2.DodajPesmu("Mala prodavnica uzasa", "Eva braun", 211);
        a2.SvirajSve();
        cout << endl;
        Currents.SvirajSve();
        cout << endl;
        Currents = a2;
        Currents.SvirajSve();
        cout << endl;
        
    } catch (std::exception &e) {
        cout << "GRESKA: " << e.what() << endl;
    }
    return 0;
}