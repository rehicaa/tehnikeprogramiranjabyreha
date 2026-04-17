#include <iostream>
#include <cmath>
#include <stdexcept>
#include <algorithm>

using std::cout, std::cin, std::endl, std::domain_error, std::min;

void SumaCetiriKvadrata(int n, int &a, int &b, int &c, int &d) {
    if (n < 0) throw domain_error("Broj koji se rastavlja mora biti nenegativan");

    int korijen = std::sqrt(n);
    for (int i = korijen; i >= 0; i--) {
        int r1 = n - i * i;
        if (r1 > 3 * i * i) continue;

        for (int j = min(i, (int)std::sqrt(r1)); j >= 0; j--) {
            int r2 = r1 - j * j;
            if (r2 > 2 * j * j) continue;

            for (int k = min(j, (int)std::sqrt(r2)); k >= 0; k--) {
                int r3 = r2 - k * k;
                int l = std::sqrt(r3);
                if (l * l == r3 && l <= k) {
                    a = i; b = j; c = k; d = l;
                    return;
                }
            }
        }
    }
}

int main() {
    int n;
    while (cout << "Unesite prirodan broj: ", cin >> n) {
        try {
            int a, b, c, d;
            SumaCetiriKvadrata(n, a, b, c, d);
            cout << n << "=" << a << "^2+" << b << "^2+" << c << "^2+" << d << "^2" << endl;
        } catch (domain_error &e) {
            cout << "Uneseni broj nije prirodan broj!" << endl;
        }
        cout << endl;
    }
    return 0;
}