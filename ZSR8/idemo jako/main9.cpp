#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
using std::cout, std::cin, std::vector, std::string, std::endl;


struct Cvor {
    int element;
    Cvor *veza;
};


int main() {
    Cvor *p = new Cvor;
    p->element = 10;
    p->veza = nullptr;

    cout << p->element;

    delete p;

    return 0;
}