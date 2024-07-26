// https://szkopul.edu.pl/problemset/problem/fof/site/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

bool jest_wieksze(ull podstawa, int wykladnik, ull wartosc) { // czy potegowana liczba jest wieksza od liczby, ktorej pierwiastka szukamy
    ull wynik = 1;
    for (int i = 0; i < wykladnik; i++) {
        if (wynik > wartosc / podstawa) // dzielimy, a nie mnozymy, aby nie wyjsc poza limit typu
            return 1;
        wynik *= podstawa;
    }
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ile_pytan;
    cin >> ile_pytan;

    for (int i = 0; i < ile_pytan; i++) {
        ull liczba;
        int potega;
        cin >> liczba >> potega;

        ull lewa = 1;
        ull prawa = liczba + 1;
        ull srodek;
    
        while (prawa - lewa > 1) {
            srodek = (lewa + prawa) / 2;

            if (jest_wieksze(srodek, potega, liczba))
                prawa = srodek;
            else 
                lewa = srodek;
        }

        cout << lewa << '\n';
    }

    return 0;
}
