// https://szkopul.edu.pl/problemset/problem/res/site/

#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ile_nominalow, kwota;
    cin >> ile_nominalow >> kwota;
    int nominaly[ile_nominalow];
    for (int i = 0; i < ile_nominalow; i++)
        cin >> nominaly[i];
    sort(nominaly, nominaly + ile_nominalow);

    int dp[kwota + 1];
    dp[0] = 0;
    for (int i = 1; i <= kwota; i++)
        dp[i] = 1e6;
    
    for (int i = 0; i < ile_nominalow; i++) {
        for (int j = 0; j <= kwota; j++) {
            if (j >= nominaly[i])
                dp[j] = min(dp[j], dp[j - nominaly[i]] + 1);
        }
    } 

    cout << dp[kwota] << '\n';

    for (int i = ile_nominalow - 1; i >= 0; i--) {
        while (nominaly[i] <= kwota && dp[kwota] == dp[kwota - nominaly[i]] + 1) {
            kwota -= nominaly[i];
            cout << nominaly[i] << ' ';
        }
    }
    cout << '\n';

    return 0;
}
