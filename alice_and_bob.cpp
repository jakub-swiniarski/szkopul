// https://codeforces.com/problemset/problem/346/A

#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ui n_elements;
    cin >> n_elements;
    ui elements[n_elements];
    ui largest = 0;
    for (ui i = 0; i < n_elements; i++) {
        cin >> elements[i];
        largest = max(largest, elements[i]);
    }
   
    ui gcd_elements = gcd(elements[0], elements[1]);
    for (ui i = 2; i < n_elements; i++)
        gcd_elements = gcd(gcd_elements, elements[i]);

    ui n_moves = (largest / gcd_elements) - n_elements;

    if (n_moves % 2 == 0)
        cout << "Bob\n";
    else
        cout << "Alice\n";

    return 0;
}
