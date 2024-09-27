// https://codeforces.com/problemset/problem/1907/B

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        int len = str.length();
        stack<int> upper, lower;
        vector<bool> mask(len, true);
        for (int j = 0; j < len; j++) {
            if (str[j] == 'b') {
                mask[j] = false;
                if (!lower.empty()) {
                    mask[lower.top()] = false;
                    lower.pop();
                }
            } else if (str[j] == 'B') {
                mask[j] = false;
                if (!upper.empty()) {
                    mask[upper.top()] = false;
                    upper.pop();
                }
            } else if (str[j] >= 'A' && str[j] <= 'Z')
                upper.push(j);
            else if (str[j] >= 'a' && str[j] <= 'z')
                lower.push(j);
        }
        
        for (int j = 0; j < len; j++) {
            if (mask[j])
                cout << str[j];
        }

        cout << '\n';
    }

    return 0;
}
