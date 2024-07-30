// https://szkopul.edu.pl/problemset/problem/gol/site/

#include <iostream>

using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll ile_osob, ile_ras;
    cin >> ile_osob >> ile_ras;

    ll ile_konf = (1 << ile_ras) + 1; // ile jest mozliwych konfiguracji ras golebi
    ll tab[ile_konf]; // ile jest osob ktore posiadaja dana konfiguracje
    fill(tab, tab + ile_konf, 0);
    for (ll i = 0; i < ile_osob; i++) {
        string dane;
        cin >> dane;

        ll konf = 0;
        for (ll j = 0; j < ile_ras; j++) {
            if (dane[j] == '1')
                konf += 1 << (ile_ras - j - 1);
        }
        tab[konf]++;
    }

    ll wynik = 0;
    for (ll i = 1; i < ile_konf; i++) {
        wynik += (tab[i] * (tab[i] - 1)) / 2; // polaczenia z osobami posiadajacymi te sama konfiguracje
        for (ll j = i + 1; j < ile_konf; j++) {
            if (i & j)
                wynik += tab[i] * tab[j]; // polaczenia z innymi osobami
        }
    }

    cout << wynik << '\n';

    return 0;
}
