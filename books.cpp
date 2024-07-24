// https://codeforces.com/problemset/problem/279/B

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num_books, time_minutes;
    cin >> num_books >> time_minutes;
    int books[num_books];
    for (int i = 0; i < num_books; i++)
        cin >> books[i];

    int tail = 0;
    int head = 0;
    int current_time = 0;
    int answer = 0;
        
    while (tail < num_books) {
        while (head < num_books && current_time <= time_minutes) {
            current_time += books[head];
            head++;
            if (current_time <= time_minutes)
                answer = max(head - tail, answer);
        }
        current_time -= books[tail];
        tail++;
    }

    cout << answer<<'\n';
    return 0;
}
