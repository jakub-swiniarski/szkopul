#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;
using ull = unsigned long long;

inline constexpr ull limit = 1e13 + 9;

vector<ull> znajdz_liczby_silne(void) {
    vector<ull> silnie;
    ull silnia = 1;
    for (ull i = 2; silnia <= limit; i++) {
        silnie.push_back(silnia);
        silnia *= i;
    }

    set<ull> liczby_silne;
    liczby_silne.insert(0);
    for (ull i = 1; i < (1 << silnie.size()); i++) {
        ull liczba_silna = 0;
        for (ull j = 0; j <= silnie.size(); j++) {
            if (i & (1 << j))
                liczba_silna += silnie[j];
        }
        liczby_silne.insert(liczba_silna);
    }

    return vector<ull>(liczby_silne.begin(), liczby_silne.end());
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<ull> liczby_silne = znajdz_liczby_silne();

    ull sumy_pref[liczby_silne.size()];
    sumy_pref[0] = liczby_silne[0];
    for (ull i = 1; i < liczby_silne.size(); i++)
        sumy_pref[i] = sumy_pref[i - 1] + liczby_silne[i];

    ull ile_zapytan;
    cin >> ile_zapytan;
    for (ull i = 0; i < ile_zapytan; i++) {
        ull a, b;
        cin >> a >> b;

        ull wynik = sumy_pref[distance(liczby_silne.begin(), --upper_bound(liczby_silne.begin(), liczby_silne.end(), b))] -
                    sumy_pref[distance(liczby_silne.begin(), --lower_bound(liczby_silne.begin(), liczby_silne.end(), a))];

        cout << wynik << '\n';
    }

    return 0;
}
