//https://szkopul.edu.pl/problemset/problem/NQamRQ2UZEwn6gPqo-l6nat9/site/?key=statement

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    short n; //for some reason when i'm using unsigned short, it doesn't give me the right answer
    cin>>n;
    unsigned short guests[n];
    bool checked[n]; 
    for(unsigned short i=0; i<n; i++){
        cin>>guests[i];
        guests[i]--; //pomniejszamy wartosc, zeby numeracja gosci zaczynala sie od zera, tak samo jak numeracja indeksow tablicy
    }

    unsigned short currentIndex; 
    unsigned short tableCount=0;
    for(unsigned short i=0; i<n; i++){
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
