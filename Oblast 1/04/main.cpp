//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;
template <typename tip>
vector<tip> unijaSkupova(vector<tip> v1, vector<tip> v2) {
    vector<tip>rez;
        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                if (v1[i] == v2[j]) {
                    bool postoji = false;
                    for (int k = 0; k < rez.size(); k++) {
                        if (rez[k] == v1[i]) {
                            postoji = true;
                            break;
                        }
                    }
                    if (!postoji) {
                        rez.push_back(v1[i]);
                    }
                }
            }
        }
    return rez;
}

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {3, 4, 5, 6, 7};
    vector<int> v3 = unijaSkupova(v1, v2);

    for (auto x : v3) {
        cout << x << " ";
    }

    return 0;
}