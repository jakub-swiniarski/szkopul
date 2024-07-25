// https://szkopul.edu.pl/problemset/problem/dwc/site/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long ile_czasteczek, min_oddzialywanie;
    cin >> ile_czasteczek >> min_oddzialywanie;
    ile_czasteczek++; // dodajemy czasteczke o ladunku 0, nie zmieni wyniku, ale bedzie latwiej z sumami prefiksowymi
    
    long long czasteczki[ile_czasteczek];
    czasteczki[0] = 0;
    for (long long i = 1; i < ile_czasteczek; i++)
        cin >> czasteczki[i];

    sort(czasteczki, czasteczki + ile_czasteczek);

    long long suma_ladunkow[ile_czasteczek]; // suma prefiksowa ladunkow
    suma_ladunkow[0] = czasteczki[0];

    long long wynik = 0;
    long long ile_max[static_cast<long long>(1e6 + 1)] = { 0 }; // ile jest czasteczek o maksymalnej wartosci i
    for (long long i = 1; i < ile_czasteczek; i++) {
        suma_ladunkow[i] = suma_ladunkow[i - 1] + czasteczki[i];

        for (long long j = czasteczki[i - 1] + 1; j <= czasteczki[i]; j++)
            ile_max[j] = ile_max[czasteczki[i - 1]];

        long long ile_bliskich = ile_max[czasteczki[i]] - ile_max[max(0ll, czasteczki[i] - min_oddzialywanie - 1)];
        wynik += ile_bliskich * min_oddzialywanie;
        wynik += czasteczki[i] * (i - 1 - ile_bliskich) - suma_ladunkow[i - 1 - ile_bliskich];

        ile_max[czasteczki[i]]++;
    }

    cout << wynik << '\n';

    return 0;
}
