#include <iostream>
#include <string>
#include <vector>
using std::cout, std::cin, std::endl, std::string, std::vector, std::ws;

struct Roba {
    string nazivRobe;
    int brojSkladista;
    int minKolicinaRobe;
    int kolicinaRobe;
    string imeDobavljaca;
    double cijena;
};


int main() {
    vector<Roba> r;
    while (true) {
        cout << "Da li zelite unijeti podatke za robu? 1 - za Da, 0 - za Ne: ";
        int x; cin >> x; if (x == 0) break;
        cout << endl;
        Roba roba;
        cout << "Naziv robe: "; std::getline(cin >> ws,roba.nazivRobe); cout << endl;
        cout << "Broj skladista robe: "; cin >> roba.brojSkladista; cout << endl;
        cout << "Minimalna kolicina robe: "; cin >> roba.minKolicinaRobe; cout << endl;
        cout << "Kolicina robe: "; cin >> roba.kolicinaRobe; cout << endl;
        cout << "Ime dobavljaca: "; std::getline (cin >> ws, roba.imeDobavljaca); cout << endl;
        cout << "Cijena robe: "; cin >> roba.cijena; cout << endl;

        r.push_back(roba);

    }
    for (int i = 0; i < r.size(); i++) {
        if (r[i].kolicinaRobe <= r[i].minKolicinaRobe) {
            cout << r[i].nazivRobe << " se mora naruciti!";
        }
    }

    return 0;
}