#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
#include <stdexcept>

using std::cout, std::cin, std::vector, std::string, std::endl;

template<typename Tip>
std::ostream& operator<<(std::ostream &tok, std::stack<Tip> stek) {
    while (!stek.empty()) {
        tok << stek.top(); stek.pop(); tok << " ";
    }
    return tok;
}
template<typename Tip>
std::stack<Tip> operator-(std::stack<Tip>s1, std::stack<Tip>s2) {
    if (s1.size() != s2.size()) throw std::logic_error("Nisu istih dimenzija");
    std::stack<Tip> rez;
    while (!s1.empty()) {
        rez.push(s1.top() - s2.top());
        s1.pop(); s2.pop();
    }
    return rez;
}
template<typename Tip>
std::stack<Tip>& operator*=(std::stack<Tip>&s, Tip broj) {
    std::stack<Tip> pomocni;
    while (!s.empty()) {
        Tip el = s.top();
        el *= broj;
        pomocni.push(el);
        s.pop();
    }
    while (!pomocni.empty()) {
        Tip el = pomocni.top();
        s.push(el);
        pomocni.pop();
    }
    return s;
}
template<typename Tip>
bool operator*(const std::stack<Tip> &s) {
    return !s.empty();
}


int main() {
    return 0;
}