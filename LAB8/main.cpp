#include <iostream>

struct Soba {
    int redni_broj;
    bool daLiJeDostupna;
};

struct Hotel {
    int broj_soba;
    Soba **niz_soba;
};

void rezervisiSobu(Hotel &h, int broj) {
    for (int i = 0; i < h.broj_soba; i++) {
        if (h.niz_soba[i]->redni_broj == broj) {
            h.niz_soba[i]->daLiJeDostupna = false;
            return;
        }
    }
}

void oslobodiSobu(Hotel &h, int broj) {
    for (int i = 0; i < h.broj_soba; i++) {
        if (h.niz_soba[i]->redni_broj == broj) {
            h.niz_soba[i]->daLiJeDostupna = true;
            return;
        }
    }
}

void ispisiBrojSlobodnihSoba(const Hotel &h) {
    int brojac = 0;
    for (int i = 0; i < h.broj_soba; i++) {
        if (h.niz_soba[i]->daLiJeDostupna) {
            brojac++;
        }
    }
    std::cout << "Imamo u hotelu trenutno " << brojac << " slobodne sobe." << std::endl;
}

int main() {
    Hotel HiltonHotelBarca;
    int n;

    std::cout << "Unesite broj soba: ";
    std::cin >> n;

    HiltonHotelBarca.broj_soba = n;
    HiltonHotelBarca.niz_soba = new Soba*[n];
    for (int i = 0; i < n; i++) {
        HiltonHotelBarca.niz_soba[i] = new Soba;
        HiltonHotelBarca.niz_soba[i]->redni_broj = i + 1;
        HiltonHotelBarca.niz_soba[i]->daLiJeDostupna = true;
    }

    ispisiBrojSlobodnihSoba(HiltonHotelBarca);

    rezervisiSobu(HiltonHotelBarca, 1);
    rezervisiSobu(HiltonHotelBarca, 2);
    ispisiBrojSlobodnihSoba(HiltonHotelBarca);

    oslobodiSobu(HiltonHotelBarca, 1);
    ispisiBrojSlobodnihSoba(HiltonHotelBarca);
    rezervisiSobu(HiltonHotelBarca, 4);
    ispisiBrojSlobodnihSoba(HiltonHotelBarca);

    for (int i = 0; i < n; i++) {
        delete HiltonHotelBarca.niz_soba[i];
    }
    delete[] HiltonHotelBarca.niz_soba;

    return 0;
}