#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cmath>
#define PI (std::atan(1) * 4)
using std::cout, std::cin, std::vector, std::string, std::endl;

class Ugao {
    double radijani;
    void SkratiUglove() {
        radijani = std::fmod(radijani, 2 * PI);
        if (radijani < 0) {
            radijani += 2 * PI;
        }
    }
    void PodklesajParametre(int &stepen, int &minute, int &sekunde) {
        while(sekunde >= 60) {
            minute++;
            sekunde-=60;
        }
        while (minute >= 60) {
            stepen++;
            minute-=60;
        }
    }
public:
    Ugao(double radijani = 0) : radijani(radijani){SkratiUglove();}
    Ugao(int stepen, int minute, int sekunde) {
        if (stepen < 0 || minute < 0 || sekunde < 0) throw std::logic_error("Parametar ne smije biti negativan");
        PodklesajParametre(stepen, minute, sekunde);
        double ukupno_stepeni = stepen + (minute / 60.) + (sekunde / 3600.);
        radijani = ukupno_stepeni * (PI/180);
        SkratiUglove();
    }
    void Postavi (double radijani) {
        SkratiUglove();
        this->radijani = radijani;
    }
    void Postavi (int stepen, int minute, int sekunde) {
        if (stepen < 0 || minute < 0 || sekunde < 0) throw std::logic_error("Parametar ne smije biti negativan");
        PodklesajParametre(stepen, minute, sekunde);
        double ukupno_stepeni = stepen + (minute / 60.) + (sekunde / 3600.);
        radijani = ukupno_stepeni * (PI/180);
        SkratiUglove();
    }
    double DajRadijane () const {return radijani;}

    int DajStepeni() const {
        int ukupno_stepeni = radijani * (180/PI);
        int stepeni = int(ukupno_stepeni);
        return stepeni;
    }
    int DajMinute() const {
        int ukupno_stepeni = radijani * (180/PI);
        int stepeni = int(ukupno_stepeni);
        double ukupno_minuta = (ukupno_stepeni - stepeni) * 60;
        int minute = int(ukupno_minuta);
        return minute;
    }
    int DajSekunde() const {
        int ukupno_stepeni = radijani * (180/PI);
        int stepeni = int(ukupno_stepeni);
        double ukupno_minuta = (ukupno_stepeni - stepeni) * 60;
        int minute = int(ukupno_minuta);
        double ukupno_sekundi = (ukupno_minuta - minute) * 60;
        int sekunde = int(ukupno_sekundi);
        return sekunde;
    }

    Ugao operator-() const {
        return Ugao(2 * PI - radijani);
    }

    friend Ugao operator+(const Ugao &a, const Ugao &b);
    friend Ugao operator-(const Ugao &a, const Ugao &b);
    Ugao operator*(double broj) const {
        return Ugao(radijani * broj);
    }
    friend Ugao operator*(double broj, const Ugao &u);

    Ugao& operator+=(const Ugao &u) {
        radijani += u.radijani;
        SkratiUglove();
        return *this;
    }
    Ugao& operator-=(const Ugao &u) {
        radijani -= u.radijani;
        SkratiUglove();
        return *this;
    }
    Ugao& operator*=(double broj) {
        radijani *= broj;
        SkratiUglove();
        return *this;
    }

    Ugao& operator++() {
        radijani += PI / 180;
        SkratiUglove();
        return *this;
    }

    Ugao operator++(int) {
        Ugao kopija(*this);
        ++(*this);
        return kopija;
    }

    bool operator<(const Ugao &u) const {
        return radijani < u.radijani;
    }

    friend std::ostream& operator<<(std::ostream &tok, const Ugao &u);

    friend std::istream& operator>>(std::istream &tok, Ugao &u);




};

Ugao operator+(const Ugao &a, const Ugao &b) {
    Ugao rez;
    rez.Postavi(a.DajRadijane() + b.DajRadijane());
    return rez;
}
Ugao operator-(const Ugao &a, const Ugao &b) {
    Ugao rez;
    rez.Postavi(a.DajRadijane() - b.DajRadijane());
    return rez;
}

Ugao operator*(double broj, const Ugao &u) {
    return Ugao(broj * u.radijani);
}
std::ostream& operator<<(std::ostream &tok, const Ugao &u) {
    double ukupno_stepeni = u.radijani * 180 / PI;

    int stepeni = int(ukupno_stepeni);

    double ukupno_minuta = (ukupno_stepeni - stepeni) * 60;
    int minute = int(ukupno_minuta);

    int sekunde = std::round((ukupno_minuta - minute) * 60);

    if (sekunde == 60) {
        sekunde = 0;
        minute++;
    }

    if (minute == 60) {
        minute = 0;
        stepeni++;
    }

    if (stepeni == 360)
        stepeni = 0;

    tok << stepeni << "d " << minute << "m " << sekunde << "s";

    return tok;
}
std::istream& operator>>(std::istream &tok, Ugao &u) {
    int stepeni, minute, sekunde;
    char d, m, s;

    tok >> stepeni >> d >> minute >> m >> sekunde >> s;

    if (!tok || d != 'd' || m != 'm' || s != 's') {
        tok.setstate(std::ios::failbit);
        return tok;
    }

    u = Ugao(stepeni, minute, sekunde);

    return tok;
}

int main() {
    return 0;
}