#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <new>
#include <memory>

using std::cout, std::cin, std::endl, std::vector, std::shared_ptr;

struct Datum{
    int dan;
    int mjesec;
    int godina;
};

struct Student {
    std::string ime;
    int indeks;
    double prosjek;
    Datum datum_rodjenja;
    std::vector<int> ocjene;
};

void IspisiStudente(const std::vector<Student> &studenti){
    for(int i = 0; i < studenti.size(); i++) {
        std::cout << studenti[i].ime << std::endl;
        std::cout << studenti[i].indeks << std::endl;
        std::cout << studenti[i].prosjek << std::endl;
        std::cout << studenti[i].datum_rodjenja.dan << "/"
          << studenti[i].datum_rodjenja.mjesec << "/"
          << studenti[i].datum_rodjenja.godina << std::endl;
        std::cout << std::endl;
        for(int j = 0; j < studenti[i].ocjene.size(); j++) {
            std::cout << studenti[i].ocjene[j] << " ";
            std::cout << std::endl;
        }
    }
}

void izracunajProsjekStudenata (std::vector<Student> &studenti) {
    for (int i = 0; i < studenti.size(); i++) {
        double suma = 0;
        for (int j = 0; j < studenti[i].ocjene.size(); j++) {
            suma += studenti[i].ocjene[j];
        }
        double prosjek = suma / studenti[i].ocjene.size();
        studenti[i].prosjek = prosjek;
    }
}

void sortirajStudente (std::vector<Student> &studenti) {
    std::sort(studenti.begin(), studenti.end(), [](const Student &s1, const Student &s2) {
        return s1.prosjek > s2.prosjek;
    });
}

int main() {
    std::vector<Student*> studenti;

   /* Student s1{"Tarik", 225, 0, {15, 4, 2004},{8, 9, 7, 10}};
    studenti.push_back(s1);
    Student s2{"Haris", 192, 0, {7, 6, 2003},{9, 9, 8, 10}};
    studenti.push_back(s2);

    izracunajProsjekStudenata(studenti);
    sortirajStudente(studenti);
    IspisiStudente(studenti);

    Student *p = new Student;
    p->ime = "Mujka";
    p->indeks = 333;
    p->prosjek = 8.5;

    std::cout << p->ime;

    delete p;
    p = nullptr;


*/

    Student *p1 = new Student;
    p1->ime = "Haris";
    p1->prosjek = 9.3;
    p1->indeks = 112;

    studenti.push_back(p1);

    Student *p2 = new Student;
    p2->ime = "Tarik";
    p2->prosjek = 9.5;
    p2->indeks = 117;

    studenti.push_back(p2);


    for (int i = 0; i < studenti.size(); i++) {
        cout << "Ime: " << studenti[i]->ime << ", Indeks: " << studenti[i]->indeks << ", Prosjek: " << studenti[i]->prosjek << endl;
    }


    for (int i = 0; i <studenti.size(); i++) {
        delete studenti[i];
    }


    vector<shared_ptr<Student>> studenti1;
    auto p3 = std::make_shared<Student>();

    p3->ime = "Haris";
    p3->prosjek = 9.0;
    p3->indeks = 114;
    studenti1.push_back(p3);


    auto p4 = std::make_shared<Student>();

    p4->ime = "Haris";
    p4->prosjek = 9.2;
    p4->indeks = 116;
    studenti1.push_back(p4);

    for (int i = 0; i < studenti1.size(); i++) {
        cout << "Ime: " << studenti1[i]->ime << ", Indeks: " << studenti1[i]->indeks << ", Prosjek: " << studenti1[i]->prosjek << endl;
    }



    return 0;
}