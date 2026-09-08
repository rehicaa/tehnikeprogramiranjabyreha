#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>


using std::cout, std::cin, std::vector, std::string, std::endl;

int main() {
    std::ofstream brojeviIzlaz("BROJEVI.TXT");
    if (!brojeviIzlaz) throw std::logic_error("Datoteka se ne moze procitati");
    for (int i = 0; i < 6; i++) {
        int broj;
        cin >> broj;
        brojeviIzlaz << broj << endl;
    }
    brojeviIzlaz.close();

    std::ifstream brojeviUlaz("BROJEVI.TXT");
    if (!brojeviUlaz) throw std::logic_error("Datoteka se ne moze procitati");
    std::ofstream parniIzlaz("PARNI.TXT");
    if (!parniIzlaz) throw std::logic_error("Datoteka se ne moze procitati");
    int broj;
    while (brojeviUlaz >> broj) {
        if (broj % 2 == 0) {
            parniIzlaz << broj << endl;
        }
    }
    parniIzlaz.close();
    if (!brojeviUlaz.eof()) throw std::logic_error("Greska pri citanju datoteke.");
    std::ifstream parniUlaz("PARNI.TXT");
    if (!parniUlaz) throw std::logic_error("Datoteka se ne moze procitati");
    int parniBroj;
    while (parniUlaz >> parniBroj) {
        cout << parniBroj << endl;
    }
    if (!parniUlaz.eof()) throw std::logic_error("Greska pri citanju datoteke.");

    return 0;
}