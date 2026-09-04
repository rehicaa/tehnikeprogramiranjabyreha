#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

class Tim {
    char ime_tima[21];
    int broj_odigranih;
    int broj_pobjeda, broj_nerijesenih, broj_poraza;
    int broj_datih, broj_primljenih;
    int broj_poena;
public:
    Tim(const char ime[]) {
        if (std::strlen(ime) <= 20) {
            std::strcpy(ime_tima, ime);
        } else {
            throw std::range_error("Maksimalan broj karaktera je 20.");
        }
        broj_datih = 0;
        broj_nerijesenih = 0;
        broj_odigranih = 0;
        broj_pobjeda = 0;
        broj_poena = 0;
        broj_poraza = 0;
        broj_primljenih = 0;
    }

    void ObradiUtakmicu(int broj_datih, int broj_primljenih);
    const char* DajImeTima() const { return ime_tima; }
    int DajBrojPoena() const { return broj_poena; }
    int DajGolRazliku() const { return broj_datih - broj_primljenih; }
    void Ispisi() const;
};

void Tim::ObradiUtakmicu(int broj_datih, int broj_primljenih) {
    if (broj_datih < 0 || broj_primljenih < 0) throw std::range_error("Neispravan broj golova.");
    this->broj_odigranih++;
    this->broj_primljenih += broj_primljenih;
    this->broj_datih += broj_datih;
    if (broj_datih > broj_primljenih) {
        this->broj_pobjeda++;
        this->broj_poena += 3;
    } else if (broj_primljenih > broj_datih) {
        this->broj_poraza++;
    } else {
        this->broj_nerijesenih++;
        this->broj_poena++;
    }
}

void Tim::Ispisi() const {
    cout << std::left << std::setw(20) << ime_tima;
    cout << std::right << std::setw(4) << broj_odigranih
         << std::setw(4) << broj_pobjeda
         << std::setw(4) << broj_nerijesenih
         << std::setw(4) << broj_poraza
         << std::setw(4) << broj_datih
         << std::setw(4) << broj_primljenih
         << std::setw(4) << broj_poena << endl;
}

class Liga {
    int broj_timova;
    const int max_br_timova;
    Tim** timovi;
public:
    explicit Liga(int velicina_lige) : broj_timova(0), max_br_timova(velicina_lige), timovi(new Tim*[max_br_timova]{}) {}
    explicit Liga(std::initializer_list<Tim> lista_timova);
    ~Liga() {
        for (int i = 0; i < max_br_timova; i++) delete timovi[i];
        delete[] timovi;
    }
    Liga(const Liga &l) : broj_timova(l.broj_timova), max_br_timova(l.max_br_timova), timovi(new Tim*[l.max_br_timova]{}) {
        try {
            for (int i = 0; i < l.broj_timova; i++) timovi[i] = new Tim(*l.timovi[i]);
        } catch (...) {
            for (int i = 0; i < max_br_timova; i++) delete timovi[i];
            delete[] timovi;
            throw;
        }
    }
    Liga(Liga &&l) : broj_timova(l.broj_timova), max_br_timova(l.max_br_timova), timovi(l.timovi) {
        l.broj_timova = 0;
        l.timovi = nullptr;
    }

    Liga &operator =(const Liga &l);
    Liga &operator =(Liga &&l);

    void DodajNoviTim(const char ime_tima[]);
    void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2);
    void IspisiTimove() const;
    void IspisiTabelu() const;
};

Liga &Liga::operator =(const Liga &l) {
    if (this == &l) return *this;
    if (max_br_timova != l.max_br_timova) throw std::logic_error("Nesaglasni kapaciteti liga");
    Tim** noviTim = new Tim*[l.max_br_timova]{};
    try {
        for (int i = 0; i < l.broj_timova; i++) noviTim[i] = new Tim(*l.timovi[i]);
    } catch (...) {
        for (int i = 0; i < l.max_br_timova; i++) delete noviTim[i];
        delete[] noviTim;
        throw;
    }
    for (int i = 0; i < max_br_timova; i++) delete timovi[i];
    delete[] timovi;
    broj_timova = l.broj_timova;
    timovi = noviTim;
    return *this;
}

Liga &Liga::operator =(Liga &&l) {
    if (this == &l) return *this;
    if (max_br_timova != l.max_br_timova) throw std::logic_error("Nesaglasni kapaciteti liga");
    for (int i = 0; i < max_br_timova; i++) delete timovi[i];
    delete[] timovi;
    broj_timova = l.broj_timova;
    timovi = l.timovi;
    l.broj_timova = 0;
    l.timovi = nullptr;
    return *this;
}

Liga::Liga(std::initializer_list<Tim> lista_timova) : broj_timova(lista_timova.size()), max_br_timova(lista_timova.size()), timovi(new Tim*[lista_timova.size()]{}) {
    int i = 0;
    for (const auto &t : lista_timova) {
        timovi[i++] = new Tim(t);
    }
}

void Liga::DodajNoviTim(const char ime_tima[]) {
    if (broj_timova >= max_br_timova) throw std::range_error("Liga popunjena");
    for (int i = 0; i < broj_timova; i++) {
        if (std::strcmp(timovi[i]->DajImeTima(), ime_tima) == 0) throw std::logic_error("Tim vec postoji");
    }
    timovi[broj_timova++] = new Tim(ime_tima);
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2) {
    Tim *p_tim1 = nullptr, *p_tim2 = nullptr;
    for (int i = 0; i < broj_timova; i++) {
        if (std::strcmp(tim1, timovi[i]->DajImeTima()) == 0) p_tim1 = timovi[i];
        if (std::strcmp(tim2, timovi[i]->DajImeTima()) == 0) p_tim2 = timovi[i];
    }
    if (rezultat_1 < 0 || rezultat_2 < 0) throw std::range_error("Neispravan broj golova");
    if (p_tim1 == nullptr || p_tim2 == nullptr) throw std::logic_error("Tim nije nadjen");
    p_tim1->ObradiUtakmicu(rezultat_1, rezultat_2);
    p_tim2->ObradiUtakmicu(rezultat_2, rezultat_1);
}

void Liga::IspisiTimove() const {
    for (int i = 0; i < broj_timova; i++) {
        cout << timovi[i]->DajImeTima() << endl;
    }
}
void Liga::IspisiTabelu() const {
    std::vector<Tim*> pomocni(timovi, timovi + broj_timova);
    std::sort(pomocni.begin(), pomocni.end(), [](Tim* a, Tim* b) {
        if (a->DajBrojPoena() != b->DajBrojPoena()) return a->DajBrojPoena() > b->DajBrojPoena();
        if (a->DajGolRazliku() != b->DajGolRazliku()) return a->DajGolRazliku() > b->DajGolRazliku();
        return std::strcmp(a->DajImeTima(), b->DajImeTima()) < 0;
    });
    for (auto t : pomocni) t->Ispisi();
}

int main() {
    try {
        Liga l(6);
        l.DodajNoviTim("Sarajevo");
        l.DodajNoviTim("Zeljeznicar");
        l.DodajNoviTim("Zrinjski");
        l.DodajNoviTim("Sloboda");
        l.DodajNoviTim("Celik");
        l.DodajNoviTim("Borac");

        l.RegistrirajUtakmicu("Sarajevo", "Zeljeznicar", 2, 1);
        l.RegistrirajUtakmicu("Zrinjski", "Sloboda", 3, 0);
        l.RegistrirajUtakmicu("Celik", "Borac", 1, 1);
        l.RegistrirajUtakmicu("Sarajevo", "Zrinjski", 1, 1);

        cout << "Timovi u ligi:" << endl;
        l.IspisiTimove();

        cout << endl << "Tabela lige:" << endl;
        l.IspisiTabelu();
    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}