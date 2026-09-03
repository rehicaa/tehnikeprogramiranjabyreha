#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Biblioteka;
class Knjiga {
    string naslov, autor, isbn;
    int broj_stanica, godina_izdavanja;
public:
    Knjiga(string naslov, string autor, string isbn, int broj_stranica, int godina_izdavanja) :
    naslov(naslov), autor(autor), isbn(isbn), broj_stanica(broj_stranica), godina_izdavanja(godina_izdavanja) {
        if ((broj_stranica <= 0) ||(broj_stranica > 10000)) throw std::range_error("Broj stranica je ilegalan.");
        if ((godina_izdavanja < 1450) || (godina_izdavanja > 2026)) throw std::range_error("Godina izdavanja je ilegalna.");
        if (isbn.empty()) throw std::logic_error("ISBN je prazan.");
    }

    friend class Biblioteka;
};

class Biblioteka {
    Knjiga** knjige;
    int kapacitet, broj_knjiga;
public:
    Biblioteka(int kapacitet) : kapacitet(kapacitet), broj_knjiga(0), knjige(new Knjiga*[kapacitet]{}) {
        if (kapacitet < 0) throw std::logic_error("Kapacitet je negativan.");
    }
    ~Biblioteka() {
        for (int i = 0; i < kapacitet; i++) {
            delete knjige[i];
        }
        delete[] knjige;
    }
    Biblioteka(const Biblioteka &druga) {
        broj_knjiga = druga.broj_knjiga;
        kapacitet = druga.kapacitet;
        try {
            knjige = new Knjiga *[druga.kapacitet]{};
            for (int i = 0; i < druga.broj_knjiga; i++) {
                knjige[i] = new Knjiga (*druga.knjige[i]);
            }
        } catch (...) {
            for (int i = 0; i < broj_knjiga; i++) {
                delete knjige[i];
            }
            delete[] knjige;
            throw;
        }
    }

    Biblioteka &operator=(const Biblioteka &druga) {
        if (this == &druga) return *this;
        Knjiga** nova = nullptr;
        try {
            nova = new Knjiga*[druga.kapacitet]{};
            for (int i = 0; i < druga.broj_knjiga; i++) {
                nova[i] = new Knjiga (*druga.knjige[i]);
            }

            for (int i = 0; i < kapacitet; i++) {
                delete knjige[i];
            }
            delete[] knjige;

            knjige = nova;
            broj_knjiga = druga.broj_knjiga;
            kapacitet = druga.kapacitet;

        } catch (...) {
            if (nova != nullptr) {
                for (int i = 0; i < broj_knjiga; i++) {
                    delete nova[i];
                }
                delete[] nova;
            }
            throw;
        }
        return *this;
    }

    Biblioteka(Biblioteka &&druga) : knjige(druga.knjige), broj_knjiga(druga.broj_knjiga), kapacitet(druga.kapacitet) {
        druga.knjige = nullptr;
        druga.broj_knjiga = 0;
        druga.kapacitet = 0;
    }

    Biblioteka &operator=(Biblioteka &&druga) {
        if (this == &druga) return *this;

        for (int i = 0; i < kapacitet; i++) delete knjige[i]; delete[] knjige;

        knjige = druga.knjige;
        broj_knjiga = druga.broj_knjiga;
        kapacitet = druga.kapacitet;

        druga.knjige = nullptr;
        druga.broj_knjiga = 0;
        druga.kapacitet = 0;

        return *this;
    }

    void DodajKnjigu (string naslov, string autor, string isbn, int broj_stranica, int godina_izdavanja) {
        if (broj_knjiga >= kapacitet) throw std::range_error ("Biblioteka je popunjena.");
        knjige[broj_knjiga] = new Knjiga (naslov, autor, isbn, broj_stranica, godina_izdavanja);
        broj_knjiga++;
    }

    void ObrisiKnjigu (string isbn) {
        for (int i = 0; i < broj_knjiga; i++) {
            if (knjige[i]->isbn == isbn){
                delete knjige[i];
                for (int j = i; j < broj_knjiga - 1; j++) {
                    knjige[j] = knjige[j + 1];
                }
                knjige[broj_knjiga - 1] = nullptr;
                broj_knjiga--;

                return;
            }
        }
        throw std::logic_error("Knjiga ne postoji.");
    }

    void PronadjiKnjigu (string isbn) {
        for (int i = 0; i < broj_knjiga; i++) {
            if (knjige[i]->isbn == isbn) {
                cout << "Ime Knjige: " << knjige[i]->naslov << endl;
                cout << "Ime autora: " << knjige[i]->autor << endl;
                cout << "Godina izdanja: " << knjige[i]->godina_izdavanja << endl;

                return;
            }
        }
        throw std::logic_error("Knjiga nije pronadjena.");
    }

    int UkupanBrojStranica() const {
        if (broj_knjiga == 0) throw std::logic_error("Biblioteka ne sadrzi niti jednu knjigu.");
        int suma = 0;
        for (int i = 0; i < broj_knjiga; i++) {
            suma+=knjige[i]->broj_stanica;
        }
        return suma;
    }

    void IspisiNajstarijuKnjigu () const {
        if (broj_knjiga == 0) throw std::logic_error("Biblioteka je prazna.");
        Knjiga najstarija = *knjige[0];
        for (int i = 1; i < broj_knjiga; i++) {
            if (knjige[i]->godina_izdavanja <= najstarija.godina_izdavanja) najstarija = *knjige[i];
        }

        cout << "Najstarija knjiga je: " << najstarija.naslov << endl;
    }

    void IspisiSve() const {
        for (int i = 0; i < broj_knjiga; i++) {
            cout << "Ime Knjige: " << knjige[i]->naslov << endl;
            cout << "Ime autora: " << knjige[i]->autor << endl;
            cout << "Godina izdanja: " << knjige[i]->godina_izdavanja << endl;
        }
    }

};

int main() {
    try {
        Biblioteka b1(5);
        b1.DodajKnjigu("Na Drini cuprija", "Ivo Andric", "978-123", 450, 1945);
        b1.DodajKnjigu("Prokleta avlija", "Ivo Andric", "978-456", 150, 1954);
        b1.DodajKnjigu("Tvrdjava", "Mesa Selimovic", "978-789", 500, 1970);

        cout << "--- Biblioteka 1 ---" << endl;
        b1.IspisiSve();

        Biblioteka b2 = b1;
        b2.DodajKnjigu("Dervis i smrt", "Mesa Selimovic", "978-000", 600, 1966);

        cout << "\n--- Biblioteka 2 (kopija b1 + nova knjiga) ---" << endl;
        b2.IspisiSve();

        Biblioteka b3(10);
        b3 = std::move(b2);

        cout << "\n--- Biblioteka 3 (move iz b2) ---" << endl;
        b3.IspisiSve();

        cout << "\nUkupan broj stranica u b3: " << b3.UkupanBrojStranica() << endl;
        b3.IspisiNajstarijuKnjigu();

        cout << "\nPretraga knjige 978-456:" << endl;
        b3.PronadjiKnjigu("978-456");

        cout << "\nBrisanje knjige 978-123..." << endl;
        b3.ObrisiKnjigu("978-123");

        cout << "\nStanje b3 nakon brisanja:" << endl;
        b3.IspisiSve();

        cout << "\nTestiranje izuzetka (pogresan ISBN):" << endl;
        b3.ObrisiKnjigu("000-000");

    } catch (const std::exception &e) {
        cout << endl << "GRESKA: " << e.what() << endl;
    }

    return 0;
}