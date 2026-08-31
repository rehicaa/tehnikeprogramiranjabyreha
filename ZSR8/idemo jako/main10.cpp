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
    Cvor *p1 = new Cvor;
    Cvor *p2 = new Cvor;
    Cvor *p3 = new Cvor;


    p1->element = 10;
    p1->veza = p2;
    p2->element = 20;
    p2->veza = p3;
    p3->element = 30;
    p3->veza = nullptr;

    cout << p1->element << endl;
    cout << p1->veza->element << endl;
    cout << p1->veza->veza->element << endl;

    delete p1; delete p2; delete p3;

    return 0;
}