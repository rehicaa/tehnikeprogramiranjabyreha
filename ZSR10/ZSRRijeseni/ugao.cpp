#include <iostream>
#include <cmath>

class Ugao {
    double radijani;
    static constexpr double PI = 3.14159265358979323846;

    void Normaliziraj() {
        radijani = std::fmod(radijani, 2 * PI);
        if (radijani < 0) radijani += 2 * PI;
    }

    static int PretvoriUArsekunde(double rad) {
        return std::round(rad * (180.0 / PI) * 3600.0);
    }

public:
    Ugao(double rad = 0) : radijani(rad) {
        Normaliziraj();
    }

    Ugao(int st, int min, int sek) {
        radijani = (st + min / 60.0 + sek / 3600.0) * (PI / 180.0);
        Normaliziraj();
    }

    Ugao &Postavi(double rad) {
        radijani = rad;
        Normaliziraj();
        return *this;
    }

    Ugao &Postavi(int st, int min, int sek) {
        radijani = (st + min / 60.0 + sek / 3600.0) * (PI / 180.0);
        Normaliziraj();
        return *this;
    }

    double DajRadijane() const {
        return radijani;
    }

    void OcitajKlasicneJedinice(int &st, int &min, int &sek) const {
        int ukupno_sekundi = PretvoriUArsekunde(radijani);
        st = ukupno_sekundi / 3600;
        min = (ukupno_sekundi % 3600) / 60;
        sek = ukupno_sekundi % 60;
    }

    int DajStepene() const {
        int st, min, sek;
        OcitajKlasicneJedinice(st, min, sek);
        return st;
    }

    int DajMinute() const {
        int st, min, sek;
        OcitajKlasicneJedinice(st, min, sek);
        return min;
    }

    int DajSekunde() const {
        int st, min, sek;
        OcitajKlasicneJedinice(st, min, sek);
        return sek;
    }

    void Ispisi() const {
        std::cout << radijani;
    }

    void IspisiKlasicno() const {
        int st, min, sek;
        OcitajKlasicneJedinice(st, min, sek);
        std::cout << st << "deg " << min << "min " << sek << "sek";
    }

    Ugao &SaberiSa(const Ugao &u) {
        radijani += u.radijani;
        Normaliziraj();
        return *this;
    }

    Ugao &PomnoziSa(double x) {
        radijani *= x;
        Normaliziraj();
        return *this;
    }

    friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2) {
        return Ugao(u1.radijani + u2.radijani);
    }

    friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x) {
        return Ugao(u.radijani * x);
    }
};

int main() {
    Ugao u1(10, 20, 30);
    Ugao u2(350, 50, 0);

    u1.SaberiSa(u2);
    u1.IspisiKlasicno();
    std::cout << std::endl;

    Ugao u3 = ProduktUglaSaBrojem(u1, 2);
    u3.IspisiKlasicno();

    return 0;
}