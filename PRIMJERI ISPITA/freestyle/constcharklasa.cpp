#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cstring>

using std::cout, std::cin, std::vector, std::string, std::endl;

struct Student {
    const char *ime;
    const char *indeks;
    double prosjek;
};

class EvidencijaStudenata {
    Student* studenti;
    int broj_studenata;
    int kapacitet;
public:
    explicit EvidencijaStudenata(int kapacitet) : kapacitet(kapacitet), broj_studenata(0), studenti(nullptr) {
        if (kapacitet <= 0) throw std::logic_error("Kapacitet je manji od 0");
        studenti = new Student[kapacitet]{};
    }
    ~EvidencijaStudenata() {
        for (int i = 0; i < broj_studenata; i++) {
            delete[] studenti[i].ime;
            delete[] studenti[i].indeks;
        }
        delete[] studenti;
    }
    EvidencijaStudenata(const EvidencijaStudenata &e) : kapacitet(e.kapacitet), broj_studenata(e.broj_studenata),
        studenti(new Student[e.kapacitet]) {
        for (int i = 0; i < e.broj_studenata; i++) {
            char *novo_ime = new char[std::strlen(e.studenti[i].ime) + 1];
            std::strcpy(novo_ime, e.studenti[i].ime);
            char *novi_indeks = new char[std::strlen(e.studenti[i].indeks) + 1];
            std::strcpy(novi_indeks, e.studenti[i].indeks);

            studenti[i].ime = novo_ime;
            studenti[i].indeks = novi_indeks;
            studenti[i].prosjek = e.studenti[i].prosjek;
        }
    }

    EvidencijaStudenata &operator=(const EvidencijaStudenata &e) {
        if (this == &e)
            return *this;

        for (int i = 0; i < broj_studenata; i++) {
            delete[] studenti[i].ime;
            delete[] studenti[i].indeks;
        }

        delete[] studenti;

        kapacitet = e.kapacitet;
        broj_studenata = e.broj_studenata;

        studenti = new Student[kapacitet]{};

        for (int i = 0; i < broj_studenata; i++) {
            char *novo_ime =
                new char[std::strlen(e.studenti[i].ime) + 1];

            std::strcpy(novo_ime, e.studenti[i].ime);

            char *novi_indeks =
                new char[std::strlen(e.studenti[i].indeks) + 1];

            std::strcpy(novi_indeks, e.studenti[i].indeks);

            studenti[i].ime = novo_ime;
            studenti[i].indeks = novi_indeks;
            studenti[i].prosjek = e.studenti[i].prosjek;
        }

        return *this;
    }

    EvidencijaStudenata(EvidencijaStudenata &&e) {
        kapacitet = e.kapacitet;
        broj_studenata = e.broj_studenata;
        studenti = e.studenti;

        e.studenti = nullptr;
        e.broj_studenata = 0;
        e.kapacitet = 0;
    }

    EvidencijaStudenata& operator=(EvidencijaStudenata &&e) {
        if (this == &e) return *this;
        for (int i = 0; i < broj_studenata; i++) {
            delete[] studenti[i].ime;
            delete[] studenti[i].indeks;
        }
        delete[] studenti;

        studenti = e.studenti;
        kapacitet = e.kapacitet;
        broj_studenata = e.broj_studenata;

        e.studenti = nullptr;
        e.broj_studenata = 0;
        e.kapacitet = 0;

        return *this;
    }
    void RegistrirajStudenta(const char* ime, const char* indeks, double prosjek) {
        if (broj_studenata >= kapacitet) throw std::range_error("Evidencija je popunjena");
        for (int i = 0; i < broj_studenata; i++) {
            if (std::strcmp(studenti[i].indeks, indeks) == 0) throw std::logic_error("Student vec postoji");
        }
        if (prosjek < 5 || prosjek > 10) throw std::logic_error("Ilegalan prosjek");
        char* novo_ime = new char[std::strlen(ime) + 1];
        std::strcpy(novo_ime, ime);

        char* novi_indeks = new char[std::strlen(indeks) + 1];
        std::strcpy(novi_indeks, indeks);

        studenti[broj_studenata].indeks = novi_indeks;
        studenti[broj_studenata].ime = novo_ime;
        studenti[broj_studenata].prosjek = prosjek;

        broj_studenata++;
    }

    void ObrisiStudenta(const char* indeks) {
        for (int i = 0; i < broj_studenata; i++) {
            if (std::strcmp(studenti[i].indeks, indeks) == 0) {
                delete[] studenti[i].indeks;
                delete[] studenti[i].ime;
                for (int j = i; j < broj_studenata - 1; j++) {
                    studenti[j] = studenti[j + 1];
                }
                broj_studenata--;
                return;
            }
        }
        throw std::logic_error("Student sa tim indeksom ne postoji");
    }
    double &operator[](const char *indeks) {
        for (int i = 0; i < broj_studenata; i++) {
            if (std::strcmp(studenti[i].indeks, indeks) == 0) {
                return studenti[i].prosjek;
            }
        }
        throw std::logic_error("Student nije pronadjen");
    }

    const double &operator[](const char *indeks) const{
        for (int i = 0; i < broj_studenata; i++) {
            if (std::strcmp(studenti[i].indeks, indeks) == 0) {
                return studenti[i].prosjek;
            }
        }
        throw std::logic_error("Student nije pronadjen");
    }
    friend std::ostream& operator<<(std::ostream &tok, const EvidencijaStudenata &e);
};

std::ostream& operator<<(std::ostream &tok, const EvidencijaStudenata &e) {
    for (int i = 0; i < e.broj_studenata; i++) {
        tok << e.studenti[i].ime << " (" << e.studenti[i].indeks << ") - " << e.studenti[i].prosjek << endl;
    }
    return tok;
}
int main() {
    return 0;
}