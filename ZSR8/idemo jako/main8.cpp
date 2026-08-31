#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>

using std::cout, std::cin, std::vector, std::string, std::endl;

struct Podatak {
    int *p;
};

int main() {
    Podatak a;
    a.p = new int;
    *a.p = 25;

    Podatak b;
    b.p = new int;
    *b.p = *a.p;

    *b.p = 100;

    cout << *a.p << endl;
    cout << *b.p << endl;


    delete a.p;
    delete b.p;


    return 0;
}