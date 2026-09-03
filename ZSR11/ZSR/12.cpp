#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Zahtjevi;

class Zahtjev {
    string ime, prezime;
    int indexID;
    string tekstZahtjeva;
    int dan, mjesec, godina;
public:
    Zahtjev(string ime, string prezime, int indexID, string tekstZahtjeva, int dan, int mjesec, int godina) :
    ime(ime), prezime(prezime), indexID(indexID), tekstZahtjeva(tekstZahtjeva), dan(dan), mjesec(mjesec), godina(godina) {
        if ((dan < 0 || dan > 31) || (mjesec < 1 || mjesec > 12) || (godina < 1940 || godina > 2026)) {
            throw std::range_error("Ilegalan datum.");
        }
    }
    friend class Zahtjevi;
};

class Zahtjevi {
    vector<Zahtjev*> zahtjevi;
public:
    Zahtjevi() = default;
    ~Zahtjevi() {
        for (Zahtjev *z : zahtjevi) delete z;
    }
};
//NEDOVRSEN ZADATAK
int main() {
    return 0;
}