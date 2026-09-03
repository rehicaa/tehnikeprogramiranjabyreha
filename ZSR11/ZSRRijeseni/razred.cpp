#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Razred {
    int kapacitet;
    int broj_ucenika;
    string **ucenici;
public:
    Razred(int kapacitet) : kapacitet(kapacitet), broj_ucenika(0), ucenici(new string*[kapacitet]{}){}
    void DodajUcenika (string ime) {
        ucenici[broj_ucenika] = new string(ime);
        broj_ucenika++;
    }
    ~Razred() {
        for (int i = 0; i < broj_ucenika; i++) {
            delete ucenici[i];
        }
        delete[] ucenici;
    }

    Razred (const Razred& drugiRaz) {
        kapacitet = drugiRaz.kapacitet;
        broj_ucenika = drugiRaz.broj_ucenika;

        ucenici = new string*[kapacitet]{};
        try {
            for (int i = 0; i < broj_ucenika; i++) {
                ucenici[i] = new string(*drugiRaz.ucenici[i]);
            }
        } catch (...) {
            for (int i = 0; i < broj_ucenika; i++) {
                delete ucenici[i];
            }
            delete[] ucenici;
            throw;
        }
    }

    Razred &operator=(const Razred& drugiRaz) {
        if (this == &drugiRaz) return *this;

        for (int i = 0; i < broj_ucenika; i++) {
            delete ucenici[i];
        }
        delete[] ucenici;

        kapacitet = drugiRaz.kapacitet;
        broj_ucenika = drugiRaz.broj_ucenika;

        try {
            ucenici = new string*[kapacitet]{};
            for (int i = 0; i < broj_ucenika; i++) {
                ucenici[i] = new string(*drugiRaz.ucenici[i]);
            }
        } catch (...) {
            for (int i = 0; i < broj_ucenika; i++) {
                delete ucenici[i];
            }
            delete[] ucenici;
            broj_ucenika = 0;
            ucenici = nullptr;

            throw;
        }
        return *this;
    }
};

int main() {
    return 0;
}