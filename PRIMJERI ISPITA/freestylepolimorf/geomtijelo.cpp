#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <memory>
#define PI (std::atan(1) * 4)

using std::cout, std::cin, std::vector, std::string, std::endl;

class GeometrijskoTijelo {

public:
    virtual double DajPovrsinu() const = 0;
    virtual double DajZapreminu() const = 0;
    virtual ~GeometrijskoTijelo() = default;
};

class Kvadar : public GeometrijskoTijelo {
    double a, b, c;
public:
    Kvadar(double a, double b, double c) : a(a), b(b), c(c){}
    double DajPovrsinu() const override {
        return 2*(a*b + a*c + b*c);
    }
    double DajZapreminu() const override {
        return a * b * c;
    }
};

class Kugla : public GeometrijskoTijelo {
    double r;
public:
    Kugla(double r): r(r){}
    double DajPovrsinu() const override {
        return (4 * r * r * PI) / 3;
    }
    double DajZapreminu() const override {
        return 4 * r * r * r * PI;
    }
};

class Valjak : public GeometrijskoTijelo {
    double r, h;
public:
    Valjak(double r, double h) : r(r), h(h){}
    double DajPovrsinu() const override {
        return  2 * PI * r * (r + h);
    }
    double DajZapreminu() const override {
        return r * r * PI * h;
    }
};

int main() {
    vector<std::shared_ptr<GeometrijskoTijelo>> v;
    v.push_back(std::make_shared<Kugla>(3.5));
    v.push_back((std::make_shared<Valjak>(3, 5)));
    v.push_back(std::make_shared<Kvadar>(3, 6, 7));

    for (int i = 0; i < v.size(); i++) {
        cout << "Zapremina: " << v[i]->DajZapreminu() << " | Povrsina: " << v[i]->DajPovrsinu() << endl;
    }
    return 0;
}