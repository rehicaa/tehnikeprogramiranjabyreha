#include <iostream>
#include <stdexcept>
using std::cout, std::cin, std::endl;
enum Pravci {Sjever, Istok, Jug, Zapad};


class Robot {
    int x, y;
    Pravci p;
public:

    Robot() : x(0), y(0), p(Sjever) {}

    void Postavi(int x, int y, Pravci p);
    void PomjeriSe(int korak);
    void OkreniSeNalijevo();
    void OkreniSeNadesno();
    int DajPozicijuX() const {return x;}
    int DajPozicijuY() const {return y;}
    Pravci DajOrijentaciju() const {return p;}
    void Ispisi() const;
};

void Robot::Postavi(int x, int y, Pravci p) {
    this->x = x;
    this->y = y;
    this->p = p;
}

void Robot::PomjeriSe(int korak) {
    switch (this-> p) {
        case Sjever:
            this->y += korak;
            break;
        case Istok:
            this->x += korak;
            break;
        case Zapad:
            this->x -= korak;
            break;
        case Jug:
            this->y -= korak;
            break;
    }
}

void Robot::OkreniSeNadesno() {
    switch (this-> p) {
        case Sjever:
            this->p = Istok;
            break;
        case Istok:
            this->p = Jug;
            break;
        case Jug:
            this->p = Zapad;
            break;
        case Zapad:
            this ->p = Sjever;
            break;
    }
}

void Robot::OkreniSeNalijevo() {
    switch (this-> p) {
        case Sjever:
            this->p = Zapad;
            break;
        case Istok:
            this->p = Sjever;
            break;
        case Jug:
            this->p = Istok;
            break;
        case Zapad:
            this ->p = Jug;
            break;
    }
}

void Robot::Ispisi() const {
    const char* nazivi[] = {"sjever", "istok", "jug", "zapad"};
    cout << "Robot se nalazi na poziciji: (" << DajPozicijuX() << ", " << DajPozicijuY() << ") i gleda na " <<
            nazivi[DajOrijentaciju()] << "." << endl;
}

int main() {
    Robot r;
    r.Postavi(5, 7, Sjever);
    r.Ispisi();
    r.PomjeriSe(4);
    r.Ispisi();
    r.OkreniSeNadesno();
    r.PomjeriSe(2);
    r.Ispisi();
    r.OkreniSeNalijevo(); r.OkreniSeNalijevo();
    r.PomjeriSe(7);
    r.Ispisi();

    return 0;

}