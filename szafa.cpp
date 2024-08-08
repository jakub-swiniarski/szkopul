// https://szkopul.edu.pl/problemset/problem/FNDAkbPzKHCXuXmPkuECkWvv/site/

#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main(void) {
    ull ile_szaf;
    cin >> ile_szaf;
    ull szafy[ile_szaf + 1];
    szafy[0] = 0;
    for (ull i = 1; i <= ile_szaf; i++)
        cin >> szafy[i];

    ull dp[ile_szaf + 1];
    dp[0] = szafy[0];
    dp[1] = szafy[1];

    for (ull i = 2; i <= ile_szaf; i++) {
        dp[i] = max(
            dp[i - 2] + szafy[i], // bierzemy aktualna szafe
            dp[i - 1] // nie bierzemy aktualnej szafy
        );
    }

    cout << dp[ile_szaf] << '\n';

    return 0;
}
