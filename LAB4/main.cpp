#include <iostream>
#include <vector>
#include <deque>
#include <string>

using std::cin, std::cout, std::vector, std::deque, std::string, std::endl;

template <typename Kont, typename T>
bool Postoji(const Kont &k, const T &x) {
    for(const auto &e : k)
        if(e == x) return true;
    return false;
}

template <typename Kont>
Kont Unija(const Kont &a, const Kont &b) {
    Kont rezultat;

    for(const auto &e : a)
        if(!Postoji(rezultat, e))
            rezultat.push_back(e);

    for(const auto &e : b)
        if(!Postoji(rezultat, e))
            rezultat.push_back(e);

    return rezultat;
}

template <typename Kont>
Kont Razlika(const Kont &a, const Kont &b) {
    Kont rezultat;

    for(const auto &e : a)
        if(!Postoji(b, e))
            rezultat.push_back(e);

    return rezultat;
}

int main() {
    int n, m;
    cout << "Unesite broj elemenata prvog vektora: ";
    cin >> n;

    vector<int> v1(n);
    cout << "Unesite elemente: ";
    for(int &x : v1) cin >> x;

    cout << "Unesite broj elemenata drugog vektora: ";
    cin >> m;

    vector<int> v2(m);
    cout << "Unesite elemente: ";
    for(int &x : v2) cin >> x;

    auto u = Unija(v1, v2);
    auto r = Razlika(v1, v2);

    cout << endl;
    cout << "Unija: ";
    for(int x : u) cout << x << " ";

    cout << endl;
    cout << "Razlika: ";
    for(int x : r) cout << x << " ";

    cout << endl;
    int d1, d2;
    cout << "Unesite broj elemenata prvog deka: ";
    cin >> d1;

    deque<string> s1(d1);
    cout << "Unesite stringove: ";
    for(auto &x : s1) cin >> x;

    cout << "Unesite broj elemenata drugog deka: ";
    cin >> d2;

    deque<string> s2(d2);
    cout << "Unesite stringove: ";
    for(auto &x : s2) cin >> x;

    auto u2 = Unija(s1, s2);
    auto r2 = Razlika(s1, s2);


    cout << endl;
    cout << "Unija: ";
    for(auto x : u2) cout << x << " ";

    cout << endl;
    cout << "Razlika: ";
    for(auto x : r2) cout << x << " ";

    return 0;
}