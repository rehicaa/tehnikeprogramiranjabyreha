#include <iostream>
using std::cout, std::cin, std::endl;
int main() {
    cout << "Unesite prvo vrijeme: ";
    int sat1, min1, sek1; cin >> sat1 >> min1 >> sek1;
    int vrijeme1 = (sat1*60*60) + (min1*60) + sek1;

    cout << "Unesite prvo vrijeme: ";
    int sat2, min2, sek2; cin >> sat2 >> min2 >> sek2;
    int vrijeme2 = (sat2*60*60) + (min2*60) + sek2;

    int finalnoVrijeme = vrijeme1 - vrijeme2;
    cout << "Razlika u unesenim vremenima je: " << ((finalnoVrijeme/60)) / 60 << "hr " << (finalnoVrijeme%60) / 60 << "min " << finalnoVrijeme % 60 << "sek.";

    return 0;

}