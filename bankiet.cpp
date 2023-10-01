//https://szkopul.edu.pl/problemset/problem/NQamRQ2UZEwn6gPqo-l6nat9/site/?key=statement

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    const unsigned short MAX=30000;

    unsigned short n;
    cin>>n;
    unsigned short guests[MAX];
    bool checked[MAX]; 
    for(unsigned short i=1; i<=n; i++){ //zaczynamy od 1, bo numeracja sasiadow w wejsciu zaczyna sie od 1
        cin>>guests[i];
    }

    unsigned short currentIndex; 
    unsigned short tableCount=0;
    for(unsigned short i=1; i<=n; i++){
        if(!checked[i]){
            currentIndex=i;
            while(!checked[currentIndex]){
                checked[currentIndex]=true;
                currentIndex=guests[currentIndex];
            }
            tableCount++;
        }
    }

    cout<<tableCount<<'\n';

    return 0;
}
