#include <iostream>
#include <string>
#include <utility>
#include <map>


int main () {
    std::map<std::string, double> cijene;
    cijene.insert({"Mlijeko", 2.50});
    cijene.insert({"Hljeb", 1.80});
    cijene["Kafa"] = 12.75;

    std::cout << cijene["Mlijeko"] << " " << cijene["Hljeb"] << " " << cijene["Kafa"] << std::endl;


    for (auto it = cijene.begin(); it != cijene.end(); it++) {
        std::cout << "Proizvod: " << it->first << std::endl;
        std::cout << "Cijena: " << it->second << std::endl;
    }


    return 0;
}