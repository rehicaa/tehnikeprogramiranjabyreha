#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin, std::cout, std::endl, std::string, std::vector, std::logic_error;

bool JeLiSlovoIliCifra(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char ToLower(char c) {
    if (c >= 'A' && c <= 'Z') return c + ('a' - 'A');
    return c;
}

string Cenzura(string recenica, vector<string> zabranjene) {
    for (int i = 0; i < zabranjene.size(); i++) {
        string s = zabranjene.at(i);
        for (int j = 0; j < s.length(); j++) {
            if (!JeLiSlovoIliCifra(s.at(j))) {
                throw logic_error("Neispravna rijec");
            }
        }
    }

    for (int i = 0; i < zabranjene.size(); i++) {
        string sporna = zabranjene.at(i);
        int n = sporna.length();
        if (n == 0) continue;

        for (int j = 0; j <= (int)recenica.length() - n; j++) {
            bool podudaranje = true;
            for (int k = 0; k < n; k++) {
                if (ToLower(recenica.at(j + k)) != ToLower(sporna.at(k))) {
                    podudaranje = false;
                    break;
                }
            }

            if (podudaranje) {
                bool ispred_ok = (j == 0 || !JeLiSlovoIliCifra(recenica.at(j - 1)));
                bool iza_ok = (j + n == recenica.length() || !JeLiSlovoIliCifra(recenica.at(j + n)));

                if (ispred_ok && iza_ok) {
                    for (int k = 0; k < n; k++) {
                        recenica.at(j + k) = '*';
                    }
                    j += n - 1;
                }
            }
        }
    }
    return recenica;
}

int main() {
    cout << "Unesite recenicu: ";
    string recenica;
    std::getline(cin, recenica);

    cout << "Unesite zabranjene rijeci (. za kraj): ";
    vector<string> zabranjene;
    string rijec;
    while (cin >> rijec && rijec != ".") {
        zabranjene.push_back(rijec);
    }

    try {
        string rezultat = Cenzura(recenica, zabranjene);
        cout << endl << "Cenzurisana recenica: " << rezultat << endl;
    }
    catch (const logic_error &) {
        cout << endl << "GRESKA: Nelegalne zabranjene rijeci!" << endl;
    }

    return 0;
}