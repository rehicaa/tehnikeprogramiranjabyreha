#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>

using std::cout, std::cin, std::vector, std::string, std::endl;

int main() {
    std::multimap<string, int> bodovi;
    bodovi.insert({"Haris", 10});
    bodovi.insert({"Haris", 20});
    bodovi.insert({"Tarik", 15});

    for (auto it = bodovi.begin(); it != bodovi.end(); it++) {
        cout << "Ime: " << it->first << ", Bodovi: " << it->second << endl;
    }

    return 0;
}