// https://szkopul.edu.pl/problemset/problem/rca1/site/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int ile_miast, ile_pytan;
    cin >> ile_miast >> ile_pytan;
    long long czas_przejazdu[ile_miast - 1];
    for (int i = 0; i < ile_miast - 1; i++)
        cin >> czas_przejazdu[i];
    pair<int, int> pytania[ile_pytan];
    for (int i = 0; i < ile_pytan; i++) {
        cin >> pytania[i].first >> pytania[i].second;
        pytania[i].first--;
        pytania[i].second--;
    }

    long long sum_pref[ile_miast];
    sum_pref[0] = 0;
    for (int i = 1; i < ile_miast; i++)
        sum_pref[i] = sum_pref[i - 1] + czas_przejazdu[i - 1];

    for (int i = 0; i < ile_pytan; i++) {
        if (pytania[i].first > pytania[i].second)
            swap(pytania[i].first, pytania[i].second);
        cout << sum_pref[pytania[i].second] - sum_pref[pytania[i].first] << '\n';
    }

    return 0;
}
