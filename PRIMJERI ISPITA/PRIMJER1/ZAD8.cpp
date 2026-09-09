#include <iostream>
#include <fstream>
#include <complex>
#include <string>
#include <stdexcept>

using std::cout, std::endl;

int main() {
    try {
        // 1. Tekstualna -> binarna
        std::ifstream ulaz("KOMPLEKSNI.TXT");

        if (!ulaz)
            throw std::logic_error("Problem pri otvaranju datoteke KOMPLEKSNI.TXT");

        std::ofstream izlaz("KOMPLEKSNI.DAT", std::ios::binary);

        if (!izlaz)
            throw std::logic_error("Problem pri kreiranju datoteke KOMPLEKSNI.DAT");

        double realni, imaginarni;
        char zarez;

        while (ulaz >> realni >> zarez >> imaginarni) {
            std::complex<double> z(realni, imaginarni);

            izlaz.write(
                reinterpret_cast<const char*>(&z),
                sizeof z
            );

            if (!izlaz)
                throw std::logic_error("Problem pri pisanju u binarnu datoteku");
        }

        if (!ulaz.eof())
            throw std::logic_error("Problem pri citanju tekstualne datoteke");

        ulaz.close();
        izlaz.close();

        // 2. Modifikacija binarne datoteke
        std::fstream dat(
            "KOMPLEKSNI.DAT",
            std::ios::binary | std::ios::in | std::ios::out
        );

        if (!dat)
            throw std::logic_error("Problem pri otvaranju binarne datoteke");

        std::complex<double> z;

        while (dat.read(reinterpret_cast<char*>(&z), sizeof z)) {
            std::complex<double> zamijenjen(z.imag(), z.real());

            dat.seekp(-static_cast<std::streamoff>(sizeof z), std::ios::cur);

            dat.write(
                reinterpret_cast<const char*>(&zamijenjen),
                sizeof zamijenjen
            );

            if (!dat)
                throw std::logic_error("Problem pri izmjeni binarne datoteke");
        }

        if (!dat.eof())
            throw std::logic_error("Problem pri citanju binarne datoteke");

        dat.close();

        // 3. Ispis modificirane datoteke
        std::ifstream citanje("KOMPLEKSNI.DAT", std::ios::binary);

        if (!citanje)
            throw std::logic_error("Problem pri ponovnom otvaranju binarne datoteke");

        while (citanje.read(reinterpret_cast<char*>(&z), sizeof z)) {
            cout << z << endl;
        }

        if (!citanje.eof())
            throw std::logic_error("Problem pri citanju binarne datoteke");
    }
    catch (const std::exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}