//https://szkopul.edu.pl/problemset/problem/QgFenN44XX_a8nX7RPmBNph4/site/?key=statement

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int enemyCount;
    cin>>enemyCount; 
    vector <long long> enemies;
    long long player=2;
    for(int i=0; i<enemyCount; i++){
        long long input;
        cin>>input;
        enemies.push_back(input);
    }
    sort(enemies.begin(), enemies.end());

    int time=0;
    long long biggest=0, biggestIndex=0;
    while(player<enemies.back()){
        //look for the biggest ball we can eat
        for(int i=0; i<enemies.size(); i++){
            if(enemies[i]<player){
                biggest=enemies[i];
            }
            else{
                break;
            }
        }
        //eat the found ball
        player+=biggest;
        time++;
        enemies.erase(enemies.begin()+biggestIndex);
    }

    cout<<time;

    return 0;
}
