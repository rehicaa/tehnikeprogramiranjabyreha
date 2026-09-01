#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>

using std::cout, std::cin, std::vector, std::string, std::endl;

class NeobicnaKlasa {
public:
    explicit NeobicnaKlasa(int broj) {
        cout << "Direktna inicijalizacija." << endl;
    }

    NeobicnaKlasa (double broj) {
        cout << "Kopirajuca inicijalizacija." << endl;
    }
};

int main() {
    NeobicnaKlasa k1(5);
    NeobicnaKlasa k2 = 5;
    return 0;
}