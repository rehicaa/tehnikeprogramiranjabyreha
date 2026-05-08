#include <iostream>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::domain_error;
using std::min;

void SumaCetiriKvadrata(int n, int &a, int &b, int &c, int &d) {
    if (n < 0) throw domain_error("");

    int korijen = std::sqrt(n);
    for (int i = korijen; i >= 0; i--) {
        int r1 = n - i * i;
        if (r1 > 3 * i * i) continue;

        for (int j = min(i, (int)std::sqrt(r1)); j >= 0; j--) {
            int r2 = r1 - j * j;
            if (r2 > 2 * j * j) continue;

            for (int k = min(j, (int)std::sqrt(r2)); k >= 0; k--) {
                int r3 = r2 - k * k;
                int l = std::round(std::sqrt(r3));
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
    for (;;) {
        cout << "Unesite prirodan broj: ";
        if (!(cin >> n)) {
            if (cin.eof()) break;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (n <= 0) {
            cout << "Uneseni broj nije prirodan broj!" << endl;
        } else {
            try {
                int a, b, c, d;
                SumaCetiriKvadrata(n, a, b, c, d);
                cout << n << "=" << a << "^2+" << b << "^2+" << c << "^2+" << d << "^2" << endl << endl;
            } catch (...) {
                cout << "Uneseni broj nije prirodan broj!" << endl;
            }
        }
    }
    return 0;
}