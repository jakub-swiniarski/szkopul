// https://szkopul.edu.pl/problemset/problem/NQamRQ2UZEwn6gPqo-l6nat9/site/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    int guests[n];
    bool checked[n]; 
    for (int i = 0; i < n; i++) {
        cin >> guests[i];
        guests[i]--; // pomniejszamy wartosc, zeby numeracja gosci zaczynala sie od zera, tak samo jak numeracja indeksow tablicy
    }

    int current_index; 
    int table_count = 0;
    for (int i = 0; i < n; i++) {
        if (!checked[i]) {
            current_index = i;
            while (!checked[current_index]) {
                checked[current_index] = true;
                current_index = guests[current_index];
            }
            table_count++;
        }
    }

    cout << table_count<<'\n';

    return 0;
}
