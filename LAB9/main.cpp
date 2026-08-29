#include <iostream>
#include <string>
#include <vector>

class Student {
    int ocjene[10];
    std::string ime, prezime;
public:
    Student &unesiIme() {
        std::cout << "Unesite ime: ";
        std::cin >> ime;
        return *this;
    }
    Student &unesiPrezime() {
        std::cout << "Unesite prezime: ";
        std::cin >> prezime;
        return *this;
    }
    Student &unesiOcjene() {
        std::cout << "Unesite 10 ocjena:" << std::endl;
        for (int i = 0; i < 10; i++) {
            std::cin >> ocjene[i];
        }
        return *this;
    }
    double dajProsjek() const {
        double suma = 0;
        for (int i = 0; i < 10; i++) suma += ocjene[i];
        return suma / 10.0;
    }
    void ispisiImeIPrezime() const {
        std::cout << ime << " " << prezime;
    }
    void ispisiOcjene() const {
        for (int i = 0; i < 10; i++) std::cout << ocjene[i] << " ";
        std::cout << std::endl;
    }
    friend void KoJeBolji(const Student &s1, const Student &s2);
};

void KoJeBolji(const Student &s1, const Student &s2) {
    double p1 = s1.dajProsjek();
    double p2 = s2.dajProsjek();
    if (p1 > p2) {
        std::cout << "Bolji je student: " << s1.ime << " " << s1.prezime << std::endl;
    } else if (p2 > p1) {
        std::cout << "Bolji je student: " << s2.ime << " " << s2.prezime << std::endl;
    } else {
        std::cout << "Studenti imaju isti prosjek." << std::endl;
    }
}

class Fakultet {
    std::vector<Student> niz;
public:
    void dodajStudenta(const Student &s) {
        niz.push_back(s);
    }
    void prikaziSve() const {
        for (const auto &s : niz) {
            s.ispisiImeIPrezime();
            std::cout << " Prosjek: " << s.dajProsjek();
            s.ispisiOcjene();
        }
    }
};

int main() {
    Fakultet f;
    Student s1, s2;

    s1.unesiIme().unesiPrezime().unesiOcjene();
    s2.unesiIme().unesiPrezime().unesiOcjene();

    f.dodajStudenta(s1);
    f.dodajStudenta(s2);

    std::cout << "\nPodaci o studentima:" << std::endl;
    f.prikaziSve();

    KoJeBolji(s1, s2);

    return 0;
}