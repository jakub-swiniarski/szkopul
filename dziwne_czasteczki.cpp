// https://szkopul.edu.pl/problemset/problem/dwc/site/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ile_czasteczek, min_oddzialywanie;
    cin >> ile_czasteczek >> min_oddzialywanie;
    ile_czasteczek++; // dodajemy czasteczke o ladunku 0, nie zmieni wyniku, ale bedzie latwiej z sumami prefiksowymi
    
    ll czasteczki[ile_czasteczek];
    czasteczki[0] = 0;
    for (ll i = 1; i < ile_czasteczek; i++)
        cin >> czasteczki[i];

    sort(czasteczki, czasteczki + ile_czasteczek);

    ll suma_ladunkow[ile_czasteczek]; // suma prefiksowa ladunkow
    suma_ladunkow[0] = czasteczki[0];

    ll wynik = 0;
    ll ile_max[static_cast<ll>(1e6 + 1)] = { 0 }; // ile jest czasteczek o maksymalnym ladunku i (nie liczac aktualnie rozpatrywanej czasteczki)
    for (ll i = 1; i < ile_czasteczek; i++) {
        suma_ladunkow[i] = suma_ladunkow[i - 1] + czasteczki[i];

        for (ll j = czasteczki[i - 1] + 1; j <= czasteczki[i]; j++)
            ile_max[j] = ile_max[czasteczki[i - 1]];

        ll ile_bliskich = ile_max[czasteczki[i]] - ile_max[max(0ll, czasteczki[i] - min_oddzialywanie - 1)]; // ile jest czasteczek oddzialywujacych minimalna wartoscia, uzywamy max(), aby nie wyjsc poza tablice
        ll ile_dalekich = i - 1 - ile_bliskich; // ile jest czasteczek oddzialywujacych wartoscia wieksza od minimalnej
        wynik += ile_bliskich * min_oddzialywanie; // dla czasteczek oddzialywujacych minimalna wartoscia
        wynik += czasteczki[i] * ile_dalekich - suma_ladunkow[ile_dalekich]; // dla reszty czasteczek

        ile_max[czasteczki[i]]++;
    }

    cout << wynik << '\n';

    return 0;
}
