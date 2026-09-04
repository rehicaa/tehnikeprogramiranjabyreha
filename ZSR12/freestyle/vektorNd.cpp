#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

class VektorNd {
    int dimenzija;
    double* koordinate;
public:
    explicit VektorNd(int n) : dimenzija(n), koordinate(new double [dimenzija]{}){}
    ~VektorNd() {
        delete[] koordinate;
    }

    VektorNd (const VektorNd &v) : dimenzija(v.dimenzija), koordinate(new double[v.dimenzija]{}) {
        for (int i = 0; i < v.dimenzija; i++) {
            koordinate[i] = v.koordinate[i];
        }
    }

    VektorNd &operator=(const VektorNd &v) {
        if (this == &v) return *this;
        double* noviNiz = new double[v.dimenzija];
        for (int i = 0; i < v.dimenzija; i++) {
            noviNiz[i] = v.koordinate[i];
            }
        delete[] koordinate;
        koordinate = noviNiz;
        dimenzija = v.dimenzija;

        return *this;
    }

    double &operator[](int indeks) {
        if (indeks >= dimenzija || indeks < 0) throw std::logic_error("Indeks je van opsega vektora");
        return koordinate[indeks];
    }
    double operator[](int indeks) const {
        if (indeks >= dimenzija || indeks < 0) throw std::logic_error("Indeks je van opsega vektora");
        return koordinate[indeks];
    }

    VektorNd& operator+=(const VektorNd &v) {
        if (this->dimenzija != v.dimenzija) throw std::range_error("Vektori nemaju iste dimenzije");
        for (int i = 0; i < dimenzija; i++) {
            this->koordinate[i]+=v.koordinate[i];
        }
        return *this;
    }

    friend VektorNd operator+(VektorNd v1, const VektorNd &v2);
    friend std::ostream& operator<<(std::ostream &tok, const VektorNd &v);
};

std::ostream& operator<<(std::ostream &tok, const VektorNd &v) {
    tok << "{";
    for (int i = 0; i < v.dimenzija; i++) {
        tok << v.koordinate[i];
        if (i < v.dimenzija - 1) {
            tok << ", ";
        }
    }
    tok << "}";

    return tok;
}

VektorNd operator+(VektorNd v1, const VektorNd &v2) {
    if (v1.dimenzija != v2.dimenzija) throw std::range_error("Vektori nemaju iste dimenzije");
    return v1 += v2;
}



int main() {
    try {
        // 1. Test konstruktora i operatora []
        VektorNd v1(3);
        v1[0] = 1.5; v1[1] = 2.5; v1[2] = 3.5;
        cout << "Vektor v1: " << v1 << endl;

        // 2. Test kopirnog konstruktora (Duboka kopija)
        VektorNd v2 = v1;
        v2[0] = 10.0; // Promjena u v2 ne smije utjecati na v1
        cout << "v2 (kopija v1 sa izmijenjenim prvim elementom): " << v2 << endl;
        cout << "v1 nakon promjene u v2 (mora ostati isti): " << v1 << endl;

        // 3. Test operatora +=
        v1 += v1;
        cout << "v1 += v1: " << v1 << endl;

        // 4. Test operatora +
        VektorNd v3 = v1 + v2;
        cout << "v1 + v2 = " << v3 << endl;

        // 5. Test operatora dodjele (=)
        VektorNd v4(1);
        v4 = v3;
        cout << "v4 (nakon v4 = v3): " << v4 << endl;

        // 6. Test izuzetka - Indeks van opsega
        cout << "\nPokusaj pristupa pogresnom indeksu:" << endl;
        try {
            v1[5] = 0;
        } catch (const std::logic_error &e) {
            cout << "Greska: " << e.what() << endl;
        }

        // 7. Test izuzetka - Razlicite dimenzije
        cout << "\nPokusaj sabiranja vektora razlicitih dimenzija:" << endl;
        VektorNd v_mali(2);
        try {
            v1 + v_mali;
        } catch (const std::range_error &e) {
            cout << "Greska: " << e.what() << endl;
        }

    } catch (const std::exception &e) {
        cout << "Neocekivan izuzetak: " << e.what() << endl;
    }

    return 0;
}