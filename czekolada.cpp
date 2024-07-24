// https://szkopul.edu.pl/problemset/problem/fRRpEz8PbuHalZh4lgF29mXy/site/ 

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

bool does_it_fit(ull cW, ull cH, ull rW, ull rH) {
    if ((cW >= rW && cH >= rH) || (cW >= rH && cH >= rW))
        return 1;
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ull chocolate_width, chocolate_height, rect_width, rect_height;
    cin >> chocolate_width >> chocolate_height >> rect_width >> rect_height;

    vector<ull> width_divisors;
    vector<ull> height_divisors;

    for (int i = 1; i <= sqrt(rect_width) + 2; i++) {
        if (rect_width % i != 0) continue;
        width_divisors.push_back(i);
        width_divisors.push_back(rect_width / i);
    }
    for (int i = 1; i <= sqrt(rect_height)+2; i++) {
        if(rect_height % i != 0) continue;
        height_divisors.push_back(i);
        height_divisors.push_back(rect_height / i);
    }

    for (int i = 0; i<width_divisors.size(); i++) {
        for (int j = 0; j < height_divisors.size(); j++) {
            if (does_it_fit(chocolate_width, chocolate_height, width_divisors[i] * height_divisors[j], (rect_width * rect_height) / (width_divisors[i] * height_divisors[j]))) {
                cout << "TAK\n";
                return 0;
            }
        }
    }

    cout << "NIE\n";
    return 0;
}
