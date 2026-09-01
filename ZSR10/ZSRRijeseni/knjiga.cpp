#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Knjiga {
    string naziv;
    char pisac[50];
    long long int isbn;
    mutable int broj_zaduzivanja;
    static int ukupno_knjiga_u_sistemu;
public:

    Knjiga(string naziv, const char p[], long long int isbn) : naziv(naziv), isbn(isbn), broj_zaduzivanja(0) {
        std::strncpy(this->pisac, p, 49);
        if (isbn < 0) throw std::logic_error("ISBN ne smije biti negativan.");
        ukupno_knjiga_u_sistemu++;
    }

    Knjiga(const Knjiga &k) {
        this->naziv = k.naziv;
        this->isbn = k.isbn;
        std::strcpy(this->pisac, k.pisac);
        this->broj_zaduzivanja = 0;
        this->ukupno_knjiga_u_sistemu++;
    }

    Knjiga& Zaduzi () {
        broj_zaduzivanja++;

        return *this;
    }

    void Ispisi() const {
        cout << "Naziv knjige: " << naziv << endl;
        cout << "Ime pisca: " << pisac << endl;
        cout << "ISBN: " << isbn << endl;
        broj_zaduzivanja++;
    }

    static int DajUkupnoKnjiga() {return ukupno_knjiga_u_sistemu;}
    int DajBrojZaduzivanja() const {return broj_zaduzivanja;}
};

int Knjiga::ukupno_knjiga_u_sistemu = 0;

int main() {
    try {
        Knjiga k1("Na Drini cuprija", "Ivo Andric", 123456789);

        k1.Zaduzi().Zaduzi().Zaduzi();

        cout << "K1 broj zaduzivanja: " << k1.DajBrojZaduzivanja() << endl;

        Knjiga k2 = k1;
        cout << "K2 (kopija) broj zaduzivanja (mora biti 0): " << k2.DajBrojZaduzivanja() << endl;

        cout << "Ukupno knjiga u biblioteci: " << Knjiga::DajUkupnoKnjiga() << endl;

        k1.Ispisi();
        k2.Ispisi();

    } catch (const std::exception &e) {
        cout << "Greska: " << e.what() << endl;
    }
    return 0;
}
