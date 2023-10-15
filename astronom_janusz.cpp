//https://szkopul.edu.pl/problemset/problem/urCDaGcjRaBBSvm-xTuLZXKN/site/?key=statement

#include <bits/stdc++.h>

using namespace std;

typedef unsigned short us;

int main(){
    us n;
    cin>>n;
    us moonPhases[n];
    for(us i=0; i<n; i++){
        cin>>moonPhases[i];
    }

    if(n==1){
        cout<<"UNKNOWN\n";
    }
    else if(moonPhases[n-1]>moonPhases[n-2]){
        if(moonPhases[n-1]==15){
            cout<<"DOWN\n";
        }
        else{
            cout<<"UP\n";
        }
    }
    else if(moonPhases[n-1]<moonPhases[n-2]){
        if(moonPhases[n-1]==0){
            cout<<"UP\n";
        }
        else{
            cout<<"DOWN\n";
        }
    }

    return 0;
}
