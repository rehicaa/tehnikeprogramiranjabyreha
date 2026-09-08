#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>


using std::cout, std::cin, std::vector, std::string, std::endl;

int main() {
    std::ofstream izlaz("DNEVNIK.TXT");
    if (!izlaz) throw std::logic_error("Datoteka se ne moze procitat");
    for (int i = 0; i < 3; i++) {
        string text;
        std::getline(cin, text);
        izlaz << text << endl;
    }
    izlaz.close();

    izlaz.open("DNEVNIK.TXT", std::ios::app);
    if (!izlaz) throw std::logic_error("Datoteka se ne moze procitat");
    for (int i = 0; i < 2; i++) {
        string text;
        std::getline(cin, text);
        izlaz << text << endl;
    }
    izlaz.close();

    std::ifstream ulaz("DNEVNIK.TXT");
    if (!ulaz) throw std::logic_error("Datoteka se ne moze procitat");
    string text;
    while (std::getline(ulaz, text)) {
        cout << text << endl;
    }
    if (!ulaz.eof()) throw std::logic_error("Greska pri citanju datoteke");


    return 0;

}