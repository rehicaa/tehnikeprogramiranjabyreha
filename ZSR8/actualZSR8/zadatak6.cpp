#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
using std::cout, std::cin, std::vector, std::string, std::endl;

string SifrirajMonoalfabetski (string s, std::map<char, char> &m) {
    for (int i = 0; i < s.length(); i++) {
        auto it = m.find(s[i]);
        if (it != m.end()) {
            s[i] = it->second;
        }
    }
    return s;
}

int main() {
    cout << "Unesite tekst za sifriranje: ";
    string tekst; std::getline(cin, tekst);

    std::map<char, char> kljuc = {
        {'a', 'x'},
        {'b', 'c'},
        {'c', 'a'}
    };

    string sifriraniTekst = SifrirajMonoalfabetski(tekst, kljuc);
    cout << "Sifrirani tekst: " << sifriraniTekst;

    return 0;
}