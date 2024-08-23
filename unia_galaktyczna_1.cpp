// https://szkopul.edu.pl/problemset/problem/ug1/site/

#include <iostream>

using namespace std;

inline constexpr int max_n = 1e6 + 9;
int rep[max_n]; // reprezentantem unii jest element i, dla ktorego rep[i] == i, jesli rep[i] != i, to znaczy ze element i zna droge do reprezentanta swojej unii

int find(int a) { // znajdz reprezentanta unii, do ktorej nalezy element a
    if (rep[a] == a)
        return a;

    rep[a] = find(rep[a]); // skroc droge do reprezentanta
    return rep[a];
}

void join(int a, int b) { // stworz unie
    rep[find(a)] = rep[find(b)];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < max_n; i++)
        rep[i] = i;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int g1, g2;
        cin >> g1 >> g2;

        if (find(g1) == find(g2))
            cout << "JUZ SIE LUBIMY!\n";
        else {
            join(g1, g2);
            cout << "NOWA UNIA - STRZEZCIE SIE WROGOWIE!\n";
        }
    }

    return 0;
}
