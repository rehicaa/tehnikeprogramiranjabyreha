#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

using std::cout, std::cin, std::endl, std::string;
#define PI (std::atan(1) * 4)

class Kvadrat
{
    double a;

public:
    explicit Kvadrat(double a) : a(a)
    {
        if (a <= 0) throw std::domain_error("Stranica mora biti veca od 0!");
    }

    void PostaviStranicu (double a);
    double DajDuzinuStranice() const {return a;}
    double DajPovrsinu() const {return a*a;}
    double DajObim() const {return 4*a;}
    void SkalirajKvadrat(double paramSkaliranja);
    void IspisiPodatke() const;

};

void Kvadrat::PostaviStranicu(double a)
{
    if (a <= 0) throw std::domain_error("Stranica mora biti veca od 0!");

    this->a = a;
}

void Kvadrat::SkalirajKvadrat(double paramSkaliranja)
{
    if (paramSkaliranja <=0) throw std::domain_error("Parametar skaliranja ne smije biti manji od 0!");

    this->a *= paramSkaliranja;
}

void Kvadrat::IspisiPodatke() const
{
    cout << "Duzina stranice kvadrata je: " << DajDuzinuStranice() << endl;
    cout << "Povrsina kvadrata je: " << DajPovrsinu() << endl;
    cout << "Obim kvadrata je: " << DajObim() << endl;
}

class Piramida
{
    Kvadrat baza;
    double visina;

public:

    Piramida(const Kvadrat& baza, double visina) : baza(baza), visina(visina)
    {
        if (visina <= 0) throw std::domain_error("Visina mora biti veca od 0!");
    }
    Piramida(double duzina, double visina) : baza(duzina), visina(visina)
    {
        if (visina <= 0) throw std::domain_error("Visina mora biti veca od 0!");
    }

    void PostaviPiramidu (const Kvadrat& baza, double visina);
    void PostaviPiramidu (double baza, double visina);
    Kvadrat DajBazu() const {return baza;};
    double DajDuzinuStraniceBaze() const {return baza.DajDuzinuStranice();}
    double DajDuzinuVisine() const {return visina;}
    double DajPovrsinu() const {return (baza.DajPovrsinu() + visina*(std::sqrt(baza.DajPovrsinu() + 4*visina*visina)));}
    double DajZapreminu() const {return (1./3. * baza.DajPovrsinu() * visina);}
    void PomnoziSaSkalarom (double paramSkaliranja);
    void Ispisi() const;

};

void Piramida::PostaviPiramidu(const Kvadrat& baza, double visina)
{
    if (visina <= 0) throw std::domain_error("Visina mora biti veca od 0!");
    this-> baza = baza;
    this-> visina = visina;
}

void Piramida::PostaviPiramidu(double baza, double visina)
{
    if (visina <= 0) throw std::domain_error("Visina mora biti veca od 0!");
    this-> baza.PostaviStranicu(baza);
    this-> visina = visina;
}

void Piramida::PomnoziSaSkalarom(double paramSkaliranja)
{
    if (paramSkaliranja <= 0) throw std::domain_error("Parametar skaliranja ne smije biti 0 ili manji!");
    this -> baza.SkalirajKvadrat(paramSkaliranja);
    this -> visina *= paramSkaliranja;

}

void Piramida::Ispisi() const
{
    cout << "Sve o bazi piramide: " << endl; baza.IspisiPodatke();
    cout << "Povrsina piramide je: " << DajPovrsinu() << endl;
    cout << "Zapremina piramide je: " << DajZapreminu() << endl;
}


int main()
{
}