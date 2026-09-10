#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <stdexcept>
#include <deque>

using std::cout, std::cin, std::vector, std::string, std::endl;
template<typename tip>
class RedSPrioritetom {
    std::deque<tip> niz;
public:
    void Dodaj(tip element) {
        niz.push_back(element);
    }
    tip DajNajveci() {
        if (niz.size() == 0) throw std::logic_error("Red je prazan");
        if (niz.size() == 1) return niz[0];
        tip najveci = niz[0];
        for (int i = 1; i < niz.size(); i++) {
            if (niz[i] > najveci) najveci = niz[i];
        }
        return najveci;
    }
    void UkloniNajveci() {
        if (niz.size() == 0) throw std::logic_error("Red je prazan");
        tip najveci = niz[0];
        int indeksNajveceg = 0;
        for (int i = 1; i < niz.size(); i++) {
            if (niz[i] > najveci) {
                najveci = niz[i];
                indeksNajveceg = i;
            }
        }
        niz.erase(niz.begin() + indeksNajveceg);
    }
    int Velicina() {
        return niz.size();
    }
    bool Prazan() {
        return niz.empty();
    }
};

int main() {
    return 0;
}