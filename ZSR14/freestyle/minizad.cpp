#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

int main() {
    std::ofstream brojevi("BROJEVI.TXT");
    if (!brojevi) throw std::logic_error("Datoteka se ne moze otvoriti");

    for (int i = 0; i < 5; i++) {
        int broj;
        cin >> broj;
        brojevi << broj << endl;
    }

    brojevi.close();

    std::ifstream brojeviIzlaz("BROJEVI.TXT");
    if (!brojeviIzlaz) throw std::logic_error("Datoteka se ne moze otvoriti");
    int x;
    while (brojeviIzlaz >> x) {
        cout << x << endl;
    }

    return 0;
}