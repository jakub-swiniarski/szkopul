// https://szkopul.edu.pl/problemset/problem/75WTu9ZZJlfrT_dO204-8djk/site/

#include <iostream>

using namespace std;

inline constexpr int limit = 1e6 + 9;
int rep_grupy[limit]; // kto jest reprezentantem i-tego samochodu w grupie samochodow o tych samych kolorach
int rep_koloru[limit]; // kto jest reprezentantem i-tego koloru

int znajdz_rep(int a) { // znajdz reprezentanta grupy samochodow
    if (rep_grupy[a] == a)
        return a;

    rep_grupy[a] = znajdz_rep(rep_grupy[a]);
    return rep_grupy[a];
}

void polacz(int a, int b) { // polacz grupy samochodow
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
            rep_koloru[kolor_samochodu] = i; // jesli nie ma jeszcze reprezentanta tego koloru, to zostaje nim aktualny samochod

        rep_grupy[i] = rep_koloru[kolor_samochodu]; // przydzielamy samochod do grupy samochodow o tych samych kolorach
    }

    for (int i = 1; i <= ile_miast; i++) {
        int a, b;
        cin >> a >> b;

        if (rep_koloru[a] == 0 ||
            a == b)
            continue; // kontynuujemy, jesli nie ma przedstawiciela pierwszego koloru, lub gdy kolory sa takie same

        if (rep_koloru[b] == 0)
            rep_koloru[b] = rep_koloru[a];
        else
            polacz(rep_koloru[a], rep_koloru[b]); // jesli malujemy samochod na kolor, ktorego przedstawiciele juz istnieja, to musimy polaczyc grupy

        rep_koloru[a] = 0; // nie ma juz przedstawicieli koloru a, bo wszystkie samochody o kolorze a zostaly przemalowane na kolor b
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
