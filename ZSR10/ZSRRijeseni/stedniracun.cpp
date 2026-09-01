#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

class StedniRacun {
    double stanje;
public:
    StedniRacun(double pocetno_stanje = 0) : stanje(pocetno_stanje) {
        if(stanje < 0) throw std::logic_error("Nedozvoljeno pocetno stanje");
    }

    StedniRacun& Ulozi (double kolicina);
    StedniRacun& Podigni (double kolicina);
    StedniRacun& ObracunajKamatu (double kamata);
    double DajStanje() const {return stanje;}

};

StedniRacun& StedniRacun::Podigni (double kolicina) {
    if (kolicina <= stanje) this->stanje -= kolicina;
    else throw std::logic_error("Transakcija odbijena.");

    return *this;
}

StedniRacun& StedniRacun::Ulozi(double kolicina) {
    this->stanje += kolicina;

    return *this;
}

StedniRacun &StedniRacun::ObracunajKamatu(double kamata) {
    if (kamata > 0) {
        this->stanje *= (kamata / 100);
    } else {
        throw std::logic_error("Nedozvoljena kamatna stopa.");
    }
    return *this;
}

int main() {
    StedniRacun r1(500.25);
    try {
        cout << "Trenutno stanje racuna: " << r1.DajStanje() << endl;
        r1.Podigni(236.4);
        cout << "Trenutno stanje racuna: " << r1.DajStanje() << endl;
        r1.Ulozi(725.50);
        cout << "Trenutno stanje racuna: " << r1.DajStanje() << endl;
    } catch (const std::exception &e) {
        cout << "GRESKA: " << e.what();
    }
    return 0;
}