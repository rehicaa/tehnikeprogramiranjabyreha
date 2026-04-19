//SVE BIBLIOTEKE SU TEMPLATES (AKO IMA BESKORISNIH BIBLIOTEKA I IMPORTA ZA TRENUTNI ZADATAK, OBRISATI PO ZELJI)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>

using std::cout, std::cin, std::endl, std::vector, std::string, std::domain_error;
template <typename T, typename nekiKriteriji>
T mojMax (vector<T>v, nekiKriteriji kriteriji) {
    if (v.empty()) throw domain_error ("Vektor je prazan!");
    T najboljiElement = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (kriteriji(v[i], najboljiElement)) {
            najboljiElement = v[i];
        }
    }
    return najboljiElement;
}
int main() {
    vector<double>v1 = {2.4, 2.9, 12.34, 12.31};
    double v1Rez = mojMax(v1, [](double x, double y) {return x > y;});
    cout << "Najveci element je: " << v1Rez;
    return 0;
}