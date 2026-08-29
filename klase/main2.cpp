#include <iostream>
#include <string>
using std::string, std::cout, std::cin, std::endl;

class proizvod
{
    string naziv;
    double cijena;

public:

    proizvod (string s, double c)
    {
        naziv = s;
        if (c < 0) cijena = 0;
        else cijena = c;
    }


    void ispisiPodatke ()
    {
        cout << "Naziv: " << naziv << ", Cijena: " << cijena <<" KM";
    }
};

int main ()
{
    proizvod cokolada("Milka Noisette", 4.20);
    cokolada.ispisiPodatke();
}