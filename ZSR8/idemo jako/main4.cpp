#include <iostream>
#include <string>
#include <utility>
#include <map>
using std::cout, std::cin, std::endl, std::string;

template <typename Tip1, typename Tip2>
struct Par {
    Tip1 prvi;
    Tip2 drugi;
};

int main () {
    Par<int, double> p1;
    Par<string, int> p2;

    p1.prvi = 10; p1.drugi = 5.5;
    p2.prvi = "Haris"; p2.drugi = 192;

    cout << p1.prvi << " " << p1.drugi << endl;
    cout << p2.prvi << " " << p2.drugi << endl;


    std::pair<string, int> par1("Haris", 15);
    std::pair<string, double> par2("Mijeko", 2.5);
    auto par3 = std::make_pair(10, 20);

    cout << par1.first << " " << par1.second << endl;
    cout << par2.first << " " << par2.second << endl;
    cout << par3.first << " " << par3.second << endl;

}