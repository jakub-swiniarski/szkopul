// https://szkopul.edu.pl/problemset/problem/4aBOXgr7VveyqhidCDcqDwse/site/

#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int ile_pytan;
    cin >> ile_pytan;
    
    for (int i = 0; i < ile_pytan; i++) {
        int hp, n, m;
        cin >> hp >> n >> m;

        while (n > 0 && hp > (hp / 2) + 10) { // sprawdzamy, czy oplaca sie uzyc tego zaklecia
            n--;
            hp = (hp / 2) + 10;
        }

        hp -= m * 10;

        if (hp <= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
