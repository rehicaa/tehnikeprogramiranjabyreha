#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>
#include <iomanip>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Tim {
    char ime_tima[21];
    int broj_odigranih;
    int broj_pobjeda, broj_nerijesenih, broj_poraza;
    int broj_datih, broj_primljenih;
    int broj_poena;
public:
    Tim(const char ime[]) {
        if (std::strlen(ime) <= 20) {
            std::strcpy(ime_tima, ime);
        } else {
            throw std::range_error("Maksimalan broj karaktera je 20.");
        }
        broj_datih = 0;
        broj_nerijesenih = 0;
        broj_odigranih = 0;
        broj_pobjeda = 0;
        broj_poena = 0;
        broj_poraza = 0;
        broj_primljenih = 0;
    }

    void ObradiUtakmicu (int broj_datih, int broj_primljenih);
    const char* DajImeTima() const {return ime_tima;}
    int DajBrojPoena() const {return broj_poena;}
    int DajBrojRazlike() const {return broj_datih - broj_primljenih;}
    void Ispisi() const;
};

void Tim::ObradiUtakmicu(int broj_datih, int broj_primljenih) {

        if (broj_datih < 0 || broj_primljenih < 0) throw std::range_error("Neispravan broj golova.");

        this->broj_odigranih++;
        this->broj_primljenih+=broj_primljenih;
        this->broj_datih+=broj_datih;

        if (broj_datih > broj_primljenih) {
            this->broj_pobjeda++;
            this->broj_poena+=3;
        } else if (broj_primljenih > broj_datih) {
            this->broj_poraza++;
        } else {
            this->broj_nerijesenih++;
            this->broj_poena++;
        }
}

void Tim::Ispisi() const {
    cout << std::left << std::setw(20) << ime_tima;
    cout << std::right << std::setw(4) << broj_datih << std::setw(4) << broj_primljenih << std::setw(4) << broj_odigranih << std::setw(4) << broj_pobjeda << std::setw(4) << broj_poraza << std::setw(4) << broj_nerijesenih << std::setw(4) <<broj_poena;
}

int main() {
    try {
        Tim t1("FK Zeljeznicar");
        t1.ObradiUtakmicu(3, 0);
        t1.ObradiUtakmicu(1, 1);
        t1.ObradiUtakmicu(0, 2);

        cout << std::left << std::setw(20) << "TIM" << "  O   P   N   I   D   P  BOD" << endl;
        t1.Ispisi();
    } catch (const std::exception &e) {
        cout << "Greska: " << e.what() << endl;
    }
    return 0;
}
