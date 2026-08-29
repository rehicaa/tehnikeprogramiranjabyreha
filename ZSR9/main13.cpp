#include <iostream>
#include <stdexcept>
using std::cout, std::cin, std::endl;

class Televizor {
    int brojKanala, volume;
    bool jeLiUkljucen;
public:
    Televizor() {
        this -> brojKanala = 1;
        this -> volume = 1;
        this -> jeLiUkljucen = true;
    }

    void Upali();
    void Ugasi();
    void PostaviKanal(int brojKanala);
    int DajKanal () const {return brojKanala;}
    void KanalUnaprijed();
    void KanalUnazad();
    void PostaviGlasnocu(int volume);
    void Pojacaj();
    void Stisaj();
    int DajGlasnocu() const {return volume;}
    bool DaLiJeUkljucen() const {return jeLiUkljucen;}
    void Prikazi() const;

};

void Televizor::Upali() {this -> jeLiUkljucen = true;}

void Televizor::Ugasi() {this -> jeLiUkljucen = false;}

void Televizor::PostaviKanal(int brojKanala) {
    if (this -> jeLiUkljucen == true && brojKanala >= 1 && brojKanala <= 150) {
        this -> brojKanala = brojKanala;
    }
}

void Televizor::KanalUnaprijed() {
    if (this -> jeLiUkljucen == true) {
        if (this -> brojKanala == 150) {
            this -> brojKanala = 1;
        } else this -> brojKanala += 1;
    }
}

void Televizor::KanalUnazad() {
    if (this -> jeLiUkljucen == true) {
        if (this -> brojKanala == 1) {
            this->brojKanala = 150;
        } else this -> brojKanala -= 1;
    }
}

void Televizor::PostaviGlasnocu(int volume) {
    if (this->jeLiUkljucen == true && volume >= 1 && volume <= 9){
        this->volume = volume;
    }
}

void Televizor::Pojacaj() {
    if (this->volume == 9) {
    } else {
        this -> volume += 1;
    }
}

void Televizor::Stisaj() {
    if (this->volume == 1) {
    } else {
        this->volume -= 1;
    }
}

void Televizor::Prikazi() const {
    if (DaLiJeUkljucen()) {
        cout << "Broj trenutnog kanala: " << DajKanal() << endl;
        cout << "Nivo glasnoce: " << DajGlasnocu() << endl;
    }
}

int main() {
    try {
        Televizor t1;
        t1.PostaviKanal(1);
        t1.PostaviGlasnocu(5);
        t1.KanalUnazad();
        t1.Prikazi();
    } catch (std::exception &e) {
        cout << "GRESKA: " << e.what();
    }

    return 0;
}