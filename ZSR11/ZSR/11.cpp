#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <stdexcept>


using std::cout, std::cin, std::vector, std::string, std::endl;

class Zahtjevi;

class Zahtjev {
    string ime, prezime;
    int indexID;
    string tekstZahtjeva;
    int dan, mjesec, godina;
public:
    Zahtjev(string ime, string prezime, int indexID, string tekstZahtjeva, int dan, int mjesec, int godina) :
    ime(ime), prezime(prezime), indexID(indexID), tekstZahtjeva(tekstZahtjeva), dan(0), mjesec(0), godina(0) {
        if ((dan < 1 || dan > 31) || (mjesec < 1 || mjesec > 12) || (godina < 1940) || godina > 2026) {
            throw std::range_error("Ilegalan datum.");
        }
        this->dan = dan;
        this->mjesec = mjesec;
        this->godina = godina;
    }
    friend class Zahtjevi;
};


class Zahtjevi {
    Zahtjev** zahtjevi;
    int maks_broj_zahtjeva;
    int zabiljezen_broj_zahtjeva;
public:
    Zahtjevi(int maks_broj_zahtjeva) : maks_broj_zahtjeva(maks_broj_zahtjeva),  zabiljezen_broj_zahtjeva(0), zahtjevi(new Zahtjev*[maks_broj_zahtjeva]{}){}
    ~Zahtjevi() {
        for (int i = 0; i < maks_broj_zahtjeva; i++) {
            delete zahtjevi[i];
        }
        delete[] zahtjevi;
    }
    Zahtjevi(const Zahtjevi &drugi) {
        maks_broj_zahtjeva = drugi.maks_broj_zahtjeva;
        zabiljezen_broj_zahtjeva = drugi.zabiljezen_broj_zahtjeva;
        try {
            zahtjevi = new Zahtjev *[drugi.maks_broj_zahtjeva]{};
            for (int i = 0; i < zabiljezen_broj_zahtjeva; i++) {
                zahtjevi[i] = new Zahtjev (*drugi.zahtjevi[i]);
            }
        } catch (...) {
            for (int i = 0; i < maks_broj_zahtjeva; i++) {
                delete zahtjevi[i];
            }
            delete[] zahtjevi;
            throw;
        }
    }

    Zahtjevi &operator=(const Zahtjevi &drugi) {
        if (this == &drugi) return *this;

        Zahtjev **noviZahtjevi = nullptr;
        try {
            noviZahtjevi = new Zahtjev *[drugi.maks_broj_zahtjeva]{};
            for (int i = 0; i < drugi.zabiljezen_broj_zahtjeva; i++) {
                noviZahtjevi[i] = new Zahtjev (*drugi.zahtjevi[i]);
            }

        for (int i = 0; i < this->maks_broj_zahtjeva; i++) {
            delete this->zahtjevi[i];
        }
        delete[] this->zahtjevi;


        zahtjevi = noviZahtjevi;
        maks_broj_zahtjeva = drugi.maks_broj_zahtjeva;
        zabiljezen_broj_zahtjeva = drugi.zabiljezen_broj_zahtjeva;


        } catch (...) {
            if (noviZahtjevi != nullptr) {
                for (int i = 0; i < drugi.maks_broj_zahtjeva; i++) {
                    delete noviZahtjevi[i];
                }
                delete[] noviZahtjevi;
            }
            throw;
        }
        return *this;
    }

    void NapraviZahtjev (string ime, string prezime, int indexID, string tekstZahtjeva, int dan, int mjesec, int godina);
    void IspisiIObrisiZahtjev();
    bool JeLiPraznaKolekcija();
};

void Zahtjevi::NapraviZahtjev(string ime, string prezime, int indexID, string tekstZahtjeva, int dan, int mjesec, int godina) {
    if (zabiljezen_broj_zahtjeva >= maks_broj_zahtjeva) {
        throw std::range_error("Ova kolekcija zahtjeva je popunjena.");
    }
    zahtjevi[zabiljezen_broj_zahtjeva] = new Zahtjev(ime, prezime, indexID, tekstZahtjeva, dan, mjesec, godina);
    zabiljezen_broj_zahtjeva++;
}

void Zahtjevi::IspisiIObrisiZahtjev() {
    if (zabiljezen_broj_zahtjeva == 0) throw std::logic_error("Kolekcija nema niti jedan zahtjev.");
    Zahtjev *prvi = zahtjevi[0];
    cout << "Ime i prezime studenta: " << prvi->ime << " " << prvi->prezime << "." << endl;
    cout << "Indeks ID: " << prvi->indexID << "." << endl;
    cout << "Tekst zahtjeva: " << endl << prvi->tekstZahtjeva << "." << endl;
    cout << "Datum zahtjeva: " << prvi->dan << "/" << prvi->mjesec << "/" << prvi->godina << "." << endl;

    delete prvi;

    for (int i = 0; i < zabiljezen_broj_zahtjeva - 1; i++) {
        zahtjevi[i] = zahtjevi[i + 1];
    }
    zahtjevi[zabiljezen_broj_zahtjeva - 1] = nullptr;
    zabiljezen_broj_zahtjeva--;
}

bool Zahtjevi::JeLiPraznaKolekcija() {
    return zabiljezen_broj_zahtjeva == 0;
}

int main() {
    try {
        Zahtjevi kolekcija1(5);
        for (int i = 0; i < 3; i++) {
            string ime, prezime, tekstZahtjeva;
            int indexID, dan, mjesec, godina;

            cout << "Unesite ime: "; cin >> ime; cout << endl;
            cout << "Unesite prezime: "; cin >> prezime; cout << endl;
            cout << "Unesite broj indeksa: "; cin >> indexID; cout << endl;
            cin.ignore();
            cout << "Unesite tekst zahtjeva: "; std::getline(cin, tekstZahtjeva); cout << endl;
            cout << "Unesite datum: "; cin >> dan >> mjesec >> godina; cout << endl;
            kolekcija1.NapraviZahtjev(ime, prezime, indexID, tekstZahtjeva, dan, mjesec, godina);

            cout << endl;
        }

        while (!kolekcija1.JeLiPraznaKolekcija()) {kolekcija1.IspisiIObrisiZahtjev();}

    } catch (std::exception &e) {
        cout << "GRESKA: " << e.what() << endl;
    }
    return 0;
}