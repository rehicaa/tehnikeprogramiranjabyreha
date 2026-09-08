#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <limits>

using std::cout, std::cin, std::string, std::endl;

int main() {
    std::ofstream studentiIzlaz("Studenti.txt");

    if (!studentiIzlaz)
        throw std::logic_error("Datoteka se ne moze otvoriti");

    for (int i = 0; i < 3; i++) {
        string ime;
        int ocjena;

        std::getline(cin, ime);
        cin >> ocjena;

        studentiIzlaz << ime << "," << ocjena << endl;

        cin.ignore(10000, '\n');
    }

    studentiIzlaz.close();

    std::ifstream studentiUlaz("Studenti.txt");

    if (!studentiUlaz)
        throw std::logic_error("Datoteka se ne moze otvoriti");

    string ime;
    int ocjena;

    while (std::getline(studentiUlaz, ime, ',') && studentiUlaz >> ocjena) {
        cout << "Student: " << ime
             << " | Ocjena: " << ocjena << endl;

        studentiUlaz.ignore(10000, '\n');
    }

    return 0;
}