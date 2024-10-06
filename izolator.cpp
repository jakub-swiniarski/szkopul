// https://szkopul.edu.pl/problemset/problem/C-avIJ9h36gThNQUOeaYwAD9/site/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n_layers;
    cin >> n_layers;

    vector<int> coefficients(n_layers);
    for (auto& i : coefficients)
        cin >> i;

    sort(coefficients.begin(), coefficients.end());
    vector<int> new_coefficients;
    int i_left = 0;
    int i_right = n_layers - 1;
    while (i_right > i_left) {
        new_coefficients.push_back(coefficients[i_left]);
        new_coefficients.push_back(coefficients[i_right]);
        i_right--;
        i_left++;
    }
    if (i_right == i_left)
        new_coefficients.insert(new_coefficients.begin(), coefficients[i_left]);

    int answer = 0;
    for (auto i = new_coefficients.begin(); i != new_coefficients.end() - 1; i++)
        answer += *i + max(0, *(i + 1) - *i);
    answer += new_coefficients.back();

    cout << answer << '\n';

    return 0;
}
