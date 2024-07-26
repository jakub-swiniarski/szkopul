// https://szkopul.edu.pl/problemset/problem/bsp/site/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n_values;
    cin >> n_values;
    ll values[n_values];
    for (int i = 0; i < n_values; i++)
        cin >> values[i];
    ll x;
    cin >> x;

    int low = 0;
    int high = n_values - 1;

    while (high >= low) {
        int mid = (low + high) / 2;

        if (values[mid] == x) { // found the value
            while (mid > 0) { // look for the first appearance
                if (values[mid - 1] == values[mid])
                    mid--;
                else
                    break;
            }
            cout << mid + 1 << '\n';
            return 0;
        } else if (values[mid] > x) // ignore right side
            high = mid - 1;
        else // ignore left side
            low = mid + 1;
    }

    // if we reach here, then element is not present

    return 0;
}
