// https://szkopul.edu.pl/problemset/problem/kwb/site/

#include "bits/stdc++.h"

using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int current_value = -1;
    int count = 0;

    for (int i = 0; i < n * m; i ++) {
        int value;
        cin >> value;

        if (value == 0)
            continue;

        if (count == 0)
            current_value = value;

        if (current_value == value)
            count++;
        else
            count--;
    }

    cout << current_value << '\n';

    return 0;
}
