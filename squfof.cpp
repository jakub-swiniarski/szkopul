// https://szkopul.edu.pl/problemset/problem/fof/site/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

bool jest_wieksze(ull podstawa, int wykladnik, ull wartosc) { // czy potegowana liczba jest wieksza od liczby, ktorej pierwiastka szukamy
    ull wynik = 1;
    for (int i = 0; i < wykladnik; i++) {
        if (wynik > wartosc / podstawa) // jesli po pomnozeniu bedzie wieksze niz dana liczba, to konczymy wykonywanie funkcji, nie sprawdzamy wynik * podstawa, bo moglibysmy wyjsc poza limit zmiennej
            return 1;
        wynik *= podstawa;
    }

    return 0;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int ile_pytan;
    cin >> ile_pytan;

    pair<ull, int> pytania[ile_pytan];
    for (int i = 0; i < ile_pytan; i++)
        cin >> pytania[i].first >> pytania[i].second; 

    for (int i = 0; i < ile_pytan; i++) {
        ull lewa = 1;
        ull prawa = pytania[i].first + 1;
        ull srodek;
    
        while (prawa - lewa > 1) {
            srodek = (lewa + prawa) / 2;

            if (jest_wieksze(srodek, pytania[i].second, pytania[i].first))
                prawa = srodek;
            else 
                lewa = srodek;
        }

        cout << lewa << '\n';
    }

    return 0;
}
