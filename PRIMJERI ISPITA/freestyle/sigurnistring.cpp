#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <string>

using std::cout, std::cin, std::vector, std::string, std::endl;

class SigurniString : public std::string {
public:
    using std::string::string;
    SigurniString(const std::string &s): std::string(s){}
    char& operator[](int indeks) {
        if (indeks < 0 || indeks >= this->length()) throw std::range_error("Neispravan indeks");
        return std::string::operator[](indeks);
    }
    const char& operator[](int indeks) const {
        if (indeks < 0 || indeks >= this->length()) throw std::range_error("Neispravan indeks");
        return std::string::operator[](indeks);
    }
};

int main() {
    return 0;
}