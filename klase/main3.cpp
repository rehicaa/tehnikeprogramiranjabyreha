#include <iostream>
#include <stdexcept>
#include <string>


using std::cout, std::cin, std::endl, std::string, std::range_error;

class student
{
    int indexID{};
    int brojPredmeta{};

public:

    student (int indexID, int brojPredmeta)
    {
        postaviIndexID(indexID);
        postaviBrojPredmeta(brojPredmeta);
    }

    void postaviBrojPredmeta (int brojPredmeta);

    void postaviIndexID (int indexID);

    int dajBrojPredmeta() const {return brojPredmeta;}

    int dajBrojIndeksa() const {return indexID;}

};

void student::postaviBrojPredmeta (int brojPredmeta)
{
    if (brojPredmeta <= 0 || brojPredmeta > 12)
    {
        throw range_error ("Greska: Netacan unos broja predmeta!");
    }
    this -> brojPredmeta = brojPredmeta;
}

void student::postaviIndexID (int indexID)
{
    if (indexID <= 0)
    {
        throw range_error ("Greska: Nepravilan unos broja indeksa!");
    }
    this -> indexID = indexID;
}


int main()
{
    student Haris (192, 11);
    cout << "Haris ima " << Haris.dajBrojPredmeta() << " predmeta, a indeks mu je: " << Haris.dajBrojIndeksa() << ".";
}