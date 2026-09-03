#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <stdexcept>
using std::cout, std::cin, std::vector, std::string, std::endl;

class Temperature {
    double* temperatura;
    int max_broj;
    int broj_evidentiranih;
public:
    explicit Temperature(int max_broj) : max_broj(max_broj), broj_evidentiranih(0){
        if (max_broj < 0) throw std::range_error("Broj temperatura mora biti veci od 0.");
        temperatura = new double[max_broj];
    }
    ~Temperature() {
        delete[] temperatura;
    }
    Temperature (const Temperature& t) {
        max_broj = t.max_broj;
        broj_evidentiranih = t.broj_evidentiranih;
        temperatura = new double[max_broj];
        for (int i = 0; i < broj_evidentiranih; i++) {
            temperatura[i] = t.temperatura[i];
        }
    }

    Temperature &operator=(const Temperature& t) {
        if (this == &t) return *this;
        double* nova_temperatura = new double [t.max_broj];
        for (int i = 0; i < t.broj_evidentiranih; i++) {
            nova_temperatura[i] = t.temperatura[i];
        }

        delete[] temperatura;

        temperatura = nova_temperatura;
        max_broj = t.max_broj;
        broj_evidentiranih = t.broj_evidentiranih;
        return *this;
    }

    void RegistrujTemperaturu (double t) {
        if (broj_evidentiranih == max_broj) {
            throw std::domain_error("Maksimalan broj temperatura dostignut!");
        }
        temperatura[broj_evidentiranih] = t;
        broj_evidentiranih++;
        }

    void ObrisiTemperature() {
        broj_evidentiranih = 0;
    }

    double DajMinimalnu() const {
        if (broj_evidentiranih == 0) throw std::domain_error("Broj temperatura je 0.");
        double min = temperatura[0];
        for (int i = 1; i < broj_evidentiranih; i++) {
            if (temperatura[i] <= min) min = temperatura[i];
        }
        return min;
    }

    double DajMaksimalnu() const {
        if (broj_evidentiranih == 0) throw std::domain_error("Broj temperatura je 0.");
        double max = temperatura[0];
        for (int i = 1; i < broj_evidentiranih; i++) {
            if (temperatura[i] >= max) max = temperatura[i];
        }
        return max;
    }

    double DajProsjecnu() const {
        if (broj_evidentiranih == 0) throw std::domain_error("Broj temperatura je 0.");
        double suma = 0;
        for (int i = 0; i < broj_evidentiranih; i++) {
            suma += temperatura[i];
        }
        return suma/broj_evidentiranih;
    }

    void IspisiZabiljezeneTemperature() const {
        if (broj_evidentiranih == 0) throw std::domain_error("Broj temperatura je 0.");
        vector<double>temp;
        for (int i = 0; i < broj_evidentiranih; i++) {
            temp.push_back(temperatura[i]);
        }
        std::sort(temp.begin(), temp.end(), [](double x, double y) {
           return x > y;
        });

        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << "C" << endl;
        }
    }
};

int main() {
    try {
        Temperature t1(7);
        t1.RegistrujTemperaturu(17.6);
        t1.RegistrujTemperaturu(23.6);
        t1.RegistrujTemperaturu(5.6);
        t1.RegistrujTemperaturu(-6.6);
        t1.RegistrujTemperaturu(19.6);
        t1.RegistrujTemperaturu(22.6);

        t1.IspisiZabiljezeneTemperature();

        cout << "Minimalna temperatura je: " << t1.DajMinimalnu() << endl;
        cout << "Maksimalna temperatura je: " << t1.DajMaksimalnu() << endl;
        cout << "Prosjecna temperatura je: " << t1.DajProsjecnu() << endl;

        Temperature t2(t1);

        t2.IspisiZabiljezeneTemperature();
        t1.ObrisiTemperature();
        t2.IspisiZabiljezeneTemperature();
        t1 = t2;
        t2.ObrisiTemperature();
        t1.IspisiZabiljezeneTemperature();
        
    } catch (std::exception &e) {
        cout << "GRESKA: " << e.what();
    }
    return 0;
}