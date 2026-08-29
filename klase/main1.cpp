#include <iostream>

class ucenik
{
private:
    int godine;
public:
    void postaviGodine (int g)
    {
        if (g > 0 && g <= 100)
        {
            godine = g;
        } else std::cout << "Unijeli ste pogresan podatak!";
    }
    

    int vratiGodine()
    {
        return godine;
    }
};

int main()
{
    ucenik amar;
    amar.postaviGodine(26);
    std::cout << "Amar ima " << amar.vratiGodine() << " godina.";
}