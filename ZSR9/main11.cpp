#include <iostream>
#include <stdexcept>
using std::cout, std::cin, std::endl, std::string;


class Student {
    std::string ime, prezime;
    int indexID, godinaStudija;
    int ocjene[10];

    public:

    Student() {
        this->ime = "";
        this->prezime= "";
        this->indexID = 0;
        this->godinaStudija = 1;
        for (int i = 0; i < 10; i++) {
            this->ocjene[i] = 5;
        }
    }
    void PostaviStudenta (string ime, string prezime, int indexID);
    string DajIme() const {return ime;}
    string DajPrezime() const {return prezime;}
    int DajIndexID() const {return indexID;}
    int DajGodinuStudija() const {return godinaStudija;}
    bool ImaLiProlaz();
    void PostaviOcjenu(int redniBrojKursa, int ocjena);
    int DajOcjenu(int redniBrojKursa);
    void PredjiNaSljedecuGodinu();
    double DajProsjek();
    bool DaLiJeBoljiOd (Student &s);
    static bool DaLiJePrviBolji (Student &s1, Student &s2);
    void IspisiPodatke();
};

void Student::PostaviStudenta(string ime, string prezime, int indexID) {
    if (indexID < 0) {
        throw std::logic_error ("Index ne smije biti negativan!");
    }
    this->ime = ime;
    this->prezime = prezime;
    this->indexID = indexID;
}

bool Student::ImaLiProlaz() {
    int brojac = 0;
    for (int i = 0; i < 10; i++) {
        if (this -> ocjene[i] <= 5) {
            brojac++;
        }
        if (brojac >= 2) return false;
    }
    return true;
}

void Student::PostaviOcjenu(int redniBrojKursa, int ocjena) {
    if ((redniBrojKursa < 1 || redniBrojKursa > 10) || (ocjena < 5 || ocjena > 10)) {
        throw std::domain_error("Redni broj kursa mora biti u opsegu od 1 do 10, a ocjena od 5 do 10!");
    }

    this -> ocjene[redniBrojKursa - 1] = ocjena;
}

int Student::DajOcjenu(int redniBrojKursa) {
    if (redniBrojKursa < 1 || redniBrojKursa > 10) {
        throw std::domain_error("Redni broj kursa mora biti u opsegu od 1 do 10!");
    }
    return this->ocjene[redniBrojKursa];
}

void Student::PredjiNaSljedecuGodinu() {
    this -> godinaStudija += 1;
    for (int i = 0; i < 10; i++) {
        this->ocjene[i] = 5;
    }
}

double Student::DajProsjek() {
        int brojac = 0;
        double suma = 0;
    for (int i = 0; i < 10; i++) {
        if (this->ocjene[i] > 5) {
            brojac++;
            suma += ocjene[i];
        }
    }
    if (brojac == 0) return 5.0;
    return suma / brojac;
}

bool Student::DaLiJeBoljiOd(Student &s) {
    return (this->DajProsjek() > s.DajProsjek());
}

bool Student::DaLiJePrviBolji(Student &s1, Student &s2) {
    return (s1.DajProsjek() > s2.DajProsjek());
}

void Student::IspisiPodatke() {
    cout << "Ime i prezime studenta: " << this -> ime << " " << this -> prezime << endl;
    cout << "Indeks studenta: " << this -> indexID << endl;
    cout << "Godina studija: " << this -> godinaStudija << endl;
    ImaLiProlaz() ? cout << "Student ima prolaz." << endl : cout << "Student nema prolaz." << endl;
    cout << "Prosjek studenta: " << DajProsjek() << endl;

}

int main() {
    Student s1, s2;
    s1.PostaviStudenta("Haris", "Mesic", 192);
    s2.PostaviStudenta("Tarik", "Avdovic", 225);

    for (int i = 1; i < 10; i++) {
        s1.PostaviOcjenu(i, 7);
    }

    for (int i = 1; i < 10; i++) {
        s2.PostaviOcjenu(i, 9);
    }

    s1.IspisiPodatke();
    cout << endl;
    s2.IspisiPodatke();

    s1.PredjiNaSljedecuGodinu();
    s1.IspisiPodatke();

    return 0;
}