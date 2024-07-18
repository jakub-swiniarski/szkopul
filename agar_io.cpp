//https://szkopul.edu.pl/problemset/problem/QgFenN44XX_a8nX7RPmBNph4/site/?key=statement

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int enemyCount;
    cin >> enemyCount; 
    vector<long long> enemies;
    long long player = 2;
    for (int i = 0; i < enemyCount; i++) {
        long long input;
        cin >> input;
        enemies.push_back(input);
    }
    sort(enemies.begin(), enemies.end());

    int time = 0;
    int right = 0, middle = 0; //for binary search, in this case left is not needed
    while (player < enemies.back()) {
        //check if it's possible to win 
        if (player <= enemies[0]) {
            cout << "NIE\n";
            return 0;
        }

        //look for the biggest ball we can eat
        right = enemies.size() - 1;
        middle = right/2;
        for (;;) {
            if (enemies[middle] >= player) {
                right = middle;
                middle = right / 2;
            } else {
                //eat the ball
                player += enemies[middle];
                time++;
                enemies.erase(enemies.begin() + middle);
                break;
            }
        }

        if(player >= enemies.back() || enemies.size() < 1) {
            cout << time<<'\n';
            return 0;
        }
    } 

    return 0;
}
