// https://szkopul.edu.pl/problemset/problem/75WTu9ZZJlfrT_dO204-8djk/site/

#include <iostream>

using namespace std;

inline constexpr int limit = 1e6 + 9;
int rep_grupy[limit];
int rep_koloru[limit];

int znajdz_rep(int a) {
    if (rep_grupy[a] == a)
        return a;

    rep_grupy[a] = znajdz_rep(rep_grupy[a]);
    return rep_grupy[a];
}

void polacz(int a, int b) {
    rep_grupy[znajdz_rep(a)] = rep_grupy[znajdz_rep(b)];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ile_samochodow, ile_miast, ile_kolorow;
    cin >> ile_samochodow >> ile_miast >> ile_kolorow;
    
    for (int i = 1; i <= ile_samochodow; i++) {
        int kolor_samochodu;
        cin >> kolor_samochodu;
        
        if (rep_koloru[kolor_samochodu] == 0)
            rep_koloru[kolor_samochodu] = i;

        rep_grupy[i] = rep_koloru[kolor_samochodu];
    }

    for (int i = 1; i <= ile_miast; i++) {
        int a, b;
        cin >> a >> b;

        if (rep_koloru[a] == 0 ||
            a == b)
            continue;

        if (rep_koloru[b] == 0)
            rep_koloru[b] = rep_koloru[a];
        else
            polacz(rep_koloru[a], rep_koloru[b]);

        rep_koloru[a] = 0;
    }

    int kolory_rep[ile_samochodow]; // kolory reprezentantow
    for (int i = 1; i <= ile_kolorow; i++) {
        if (rep_koloru[i] == 0)
            continue;
        kolory_rep[rep_koloru[i]] = i;
    }
    for (int i = 1; i <= ile_samochodow; i++)
        cout << kolory_rep[znajdz_rep(i)] << ' ';
    cout << '\n';
    
    return 0;
}
