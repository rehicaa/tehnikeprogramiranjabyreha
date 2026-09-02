#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <memory>

using std::cout, std::cin, std::vector, std::string, std::endl;

template <typename TipElemenata>
class DinamickiNiz {
    int velicina;
    std::shared_ptr<TipElemenata[]> pokazivac;
public:
    explicit DinamickiNiz(int velicina) : velicina(velicina), pokazivac(new TipElemenata[velicina]{}){}
    TipElemenata &operator[](int indeks) {return pokazivac[indeks];}
    TipElemenata const &operator[] (int indeks) const {return pokazivac[indeks];}
    DinamickiNiz(const DinamickiNiz& drugi) : velicina(drugi.velicina) {
        pokazivac = std::shared_ptr<TipElemenata[]>(new TipElemenata[velicina]);
        for (int i = 0; i < velicina; i++) {
            pokazivac[i] = drugi.pokazivac[i];
        }
    }

        DinamickiNiz &operator=(const DinamickiNiz &drugi) {
            if (this == &drugi) return *this;
            velicina = drugi.velicina;
            pokazivac = std::shared_ptr<TipElemenata[]>(new TipElemenata[velicina]);
            for (int i = 0; i < velicina; i++) {
                pokazivac[i] = drugi.pokazivac[i];
            }
            return *this;
        }
};


int main() {
    return 0;
}