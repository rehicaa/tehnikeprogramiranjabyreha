#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <memory>

using std::cin, std::cout, std::endl, std::string, std::map, std::logic_error, std::domain_error, std::pair, std::make_pair, std::unique_ptr, std::make_unique;

class Korisnik {
    int clanski_broj;
    string ime_i_prezime, adresa, telefon;
public:
    Korisnik(int cb, string ime, string adr, string tel) : clanski_broj(cb), ime_i_prezime(ime), adresa(adr), telefon(tel) {}
    int DajClanskiBroj() const { return clanski_broj; }
    string DajImeIPrezime() const { return ime_i_prezime; }
    string DajAdresu() const { return adresa; }
    string DajTelefon() const { return telefon; }
    void Ispisi() const {
        cout << "Clanski broj: " << clanski_broj << endl << "Ime i prezime: " << ime_i_prezime << endl
             << "Adresa: " << adresa << endl << "Telefon: " << telefon << endl;
    }
};

class Film {
    int evid_broj, godina;
    bool dvd;
    string naziv, zanr;
    Korisnik *zaduzen_kod;
public:
    Film(int eb, bool je_dvd, string n, string z, int g) : evid_broj(eb), godina(g), dvd(je_dvd), naziv(n), zanr(z), zaduzen_kod(nullptr) {}
    int DajEvidencijskiBroj() const { return evid_broj; }
    string DajNaziv() const { return naziv; }
    string DajZanr() const { return zanr; }
    int DajGodinuProdukcije() const { return godina; }
    bool DaLiJeDVD() const { return dvd; }
    void ZaduziFilm(Korisnik &k) { zaduzen_kod = &k; }
    void RazduziFilm() { zaduzen_kod = nullptr; }
    bool DaLiJeZaduzen() const { return zaduzen_kod != nullptr; }
    Korisnik &DajKodKogaJe() const {
        if (!DaLiJeZaduzen()) throw domain_error("Film nije zaduzen");
        return *zaduzen_kod;
    }
    Korisnik *DajPokKogaJe() const { return zaduzen_kod; }
    void Ispisi() const {
        cout << "Evidencijski broj: " << evid_broj << endl << "Medij: " << (dvd ? "DVD" : "Video traka") << endl
             << "Naziv filma: " << naziv << endl << "Zanr: " << zanr << endl << "Godina produkcije: " << godina << endl;
    }
};

class Videoteka {
    map<int, unique_ptr<Korisnik>> korisnici;
    map<int, unique_ptr<Film>> filmova;
public:
    Videoteka() = default;
    ~Videoteka() = default;

    Videoteka(const Videoteka &v) {
        for (auto const& [id, k] : v.korisnici)
            korisnici[id] = make_unique<Korisnik>(*k);
        for (auto const& [id, f] : v.filmova) {
            filmova[id] = make_unique<Film>(*f);
            if (f->DaLiJeZaduzen()) {
                int k_id = f->DajPokKogaJe()->DajClanskiBroj();
                filmova[id]->ZaduziFilm(*korisnici[k_id]);
            }
        }
    }

    Videoteka(Videoteka &&v) = default;

    Videoteka &operator=(const Videoteka &v) {
        if (this == &v) return *this;
        korisnici.clear();
        filmova.clear();
        for (auto const& [id, k] : v.korisnici)
            korisnici[id] = make_unique<Korisnik>(*k);
        for (auto const& [id, f] : v.filmova) {
            filmova[id] = make_unique<Film>(*f);
            if (f->DaLiJeZaduzen()) {
                int k_id = f->DajPokKogaJe()->DajClanskiBroj();
                filmova[id]->ZaduziFilm(*korisnici[k_id]);
            }
        }
        return *this;
    }

    Videoteka &operator=(Videoteka &&v) = default;

    void RegistrirajNovogKorisnika(int cb, string ime, string adr, string tel) {
        if (korisnici.count(cb)) throw logic_error("Vec postoji korisnik s tim clanskim brojem");
        korisnici[cb] = make_unique<Korisnik>(cb, ime, adr, tel);
    }

    void RegistrirajNoviFilm(int eb, bool dvd, string n, string z, int g) {
        if (filmova.count(eb)) throw logic_error("Film s tim evidencijskim brojem vec postoji");
        filmova[eb] = make_unique<Film>(eb, dvd, n, z, g);
    }

    Korisnik &NadjiKorisnika(int cb) const {
        if (!korisnici.count(cb)) throw logic_error("Korisnik nije nadjen");
        return *korisnici.at(cb);
    }

    Film &NadjiFilm(int eb) const {
        if (!filmova.count(eb)) throw logic_error("Film nije nadjen");
        return *filmova.at(eb);
    }

    void IzlistajKorisnike() const {
        for (auto const& [id, k] : korisnici) { k->Ispisi(); cout << endl; }
    }

    void IzlistajFilmove() const {
        for (auto const& [id, f] : filmova) {
            f->Ispisi();
            if (f->DaLiJeZaduzen()) {
                cout << "Zaduzen kod korisnika: " << f->DajKodKogaJe().DajImeIPrezime()
                     << " (" << f->DajKodKogaJe().DajClanskiBroj() << ")" << endl;
            }
            cout << endl;
        }
    }

    void ZaduziFilm(int eb, int cb) {
        Film &f = NadjiFilm(eb);
        Korisnik &k = NadjiKorisnika(cb);
        if (f.DaLiJeZaduzen()) throw logic_error("Film vec zaduzen");
        f.ZaduziFilm(k);
    }

    void RazduziFilm(int eb) {
        Film &f = NadjiFilm(eb);
        if (!f.DaLiJeZaduzen()) throw logic_error("Film nije zaduzen");
        f.RazduziFilm();
    }

    void PrikaziZaduzenja(int cb) const {
        Korisnik &k = NadjiKorisnika(cb);
        bool nasao = false;
        for (auto const& [id, f] : filmova) {
            if (f->DajPokKogaJe() == &k) { f->Ispisi(); cout << endl; nasao = true; }
        }
        if (!nasao) cout << "Korisnik nema zaduzenja!" << endl;
    }
};

int main() {
    Videoteka v;
    v.RegistrirajNovogKorisnika(1, "Niko Nikic", "Ulica 1", "061111222");
    v.RegistrirajNoviFilm(101, true, "Inception", "Sci-Fi", 2010);
    v.ZaduziFilm(101, 1);
    v.IzlistajFilmove();
    return 0;
}