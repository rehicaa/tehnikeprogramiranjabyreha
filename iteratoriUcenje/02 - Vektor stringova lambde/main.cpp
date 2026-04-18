//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;

int main() {
    vector<string> v= {"Ivan", "Muhammed", "Zlatko", "Anesa", "Dario"};
    std::sort(v.begin(), v.end(), [](const string &s1, const string &s2) {
        return s1.length() > s2.length();
    });

    cout << "Vektor stringova ppo velicini: " << endl;
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }

    auto broj = std::count_if(v.begin(), v.end(), [](const string &s){
        return s[0] == 'A';
    });

    cout << "\nBroj imena koja pocinju na slovo 'A': " << broj;

    return 0;
}