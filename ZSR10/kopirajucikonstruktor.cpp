#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>

using std::cout, std::cin, std::vector, std::string, std::endl;

class Korisnik {
    string ime;
    int id_broj;
public:
    Korisnik(string ime = "", int id_broj = 0) : ime(ime), id_broj(id_broj){}
    Korisnik (const Korisnik &u) {
        this->ime = u.ime;
        this->id_broj = 0;
    }
};

int main() {
    return 0;
}