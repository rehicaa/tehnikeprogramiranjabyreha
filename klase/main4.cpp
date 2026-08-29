#include <iostream>
#include <stdexcept>
#include <string>

using std::cout, std::cin, std::endl, std::string;

class Osoba
{
    string ime;

public:

    Osoba (string ime)
    {
        postaviIme(ime);
    }

    void postaviIme (string ime);

    string dajIme() const {return ime;}

};

void Osoba::postaviIme(string ime)
{
    for (int i = 0; i < ime.size(); i++)
    {
        if (!(std::isalpha(ime[i])))
        {
            throw std::logic_error("Nepravilno uneseno ime!");
        }
    }

    this -> ime = ime;
}

class BankovniRacun
{
    Osoba vlasnik;
    const long long brojRacuna;
    double stanje;

public:

    explicit BankovniRacun (string imeKorisnika, long long br, double pocetnoStanje) :
    vlasnik(imeKorisnika),
    brojRacuna(br)
    {
        if (pocetnoStanje < 0)
        {
            throw std::domain_error("Pocetno stanje ne smije biti negativno!");
        }

        this -> stanje = pocetnoStanje;
    }

    void Uplati (double iznos);

    void Podigni (double iznos);

    void Ispisi() const
    {
        cout << "Ime vlasnika: " << vlasnik.dajIme() << " || Stanje: " << stanje << "KM." << endl;
    }
};

void BankovniRacun::Uplati(double iznos)
{
    if (iznos <= 0)
    {
        throw std::domain_error("Uplata mora biti veca od nula!");
    }
    this -> stanje += iznos;
}

void BankovniRacun::Podigni(double iznos)
{
    if (iznos > stanje)
    {
        throw std::domain_error ("Ne mozete dici vise no sto posjedujete!");
    }

    this -> stanje -= iznos;
}

int main()
{
    BankovniRacun b1("Haris", 1134521242, 100);
    b1.Ispisi();
    b1.Podigni(30);
    b1.Ispisi();
    b1.Uplati(100);
    b1.Ispisi();

    return 0;
}