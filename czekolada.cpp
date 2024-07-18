//https://szkopul.edu.pl/problemset/problem/fRRpEz8PbuHalZh4lgF29mXy/site/?key=statement

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

bool doesItFit(ull cW, ull cH, ull rW, ull rH) {
    if ((cW >= rW && cH >= rH) || (cW >= rH && cH >= rW))
        return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ull chocolateWidth, chocolateHeight, rectWidth, rectHeight;
    cin >> chocolateWidth >> chocolateHeight >> rectWidth >> rectHeight;

    vector<ull> widthDivisors;
    vector<ull> heightDivisors;

    //find divisors
    for (int i = 1; i <= sqrt(rectWidth) + 2; i++) {
        if (rectWidth % i != 0) continue;
        widthDivisors.push_back(i);
        widthDivisors.push_back(rectWidth / i);
    }
    for (int i=1; i<=sqrt(rectHeight)+2; i++) {
        if(rectHeight % i != 0) continue;
        heightDivisors.push_back(i);
        heightDivisors.push_back(rectHeight / i);
    }

    for (int i = 0; i<widthDivisors.size(); i++) {
        for (int j = 0; j < heightDivisors.size(); j++) {
            if (doesItFit(chocolateWidth, chocolateHeight, widthDivisors[i] * heightDivisors[j], (rectWidth * rectHeight) / (widthDivisors[i] * heightDivisors[j]))) {
                cout << "TAK\n";
                return 0;
            }
        }
    }

    cout << "NIE\n";
    return 0;
}
