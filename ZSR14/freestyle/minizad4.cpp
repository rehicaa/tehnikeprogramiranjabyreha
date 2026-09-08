#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <climits>

using std::cout, std::cin, std::vector, std::string, std::endl;

int main() {
    std::ofstream najveciIzlaz("najveci.txt");
    if (!najveciIzlaz) throw std::logic_error("Datoteka se ne moze otvoriti");
    for (int i = 0; i < 5; i++) {
        int broj;
        cin >> broj;
        najveciIzlaz << broj << endl;
    }
    najveciIzlaz.close();

    std::ifstream najveciUlaz("najveci.txt");
    if (!najveciUlaz) throw std::logic_error("Datoteka se ne moze otvoriti");
    int broj;
    int najveci = INT_MIN;

    while (najveciUlaz >> broj) {
        if (broj > najveci) najveci = broj;
    }

    cout << "Najveci broj je: " << najveci;

    return 0;
}