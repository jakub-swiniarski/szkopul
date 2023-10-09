//https://codeforces.com/problemset/problem/279/B

#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ui numBooks, timeMinutes;
    cin>>numBooks>>timeMinutes;
    unsigned short books[numBooks];
    for(ui i=0; i<numBooks; i++){
        cin>>books[i];
    }

    ui tail=0;
    ui head=0;
    ui currentTime=0;
    ui answer=0;
        
    while(tail<numBooks){
        while(head<numBooks && currentTime<=timeMinutes){
            currentTime+=books[head];
            head++;
            if(currentTime<=timeMinutes){
                answer=max(head-tail,answer);
            }
        }
        currentTime-=books[tail];
        tail++;
    }

    cout<<answer<<'\n';
    return 0;
}
