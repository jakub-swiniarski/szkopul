//https://codeforces.com/problemset/problem/279/B

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int numBooks, timeMinutes;
    cin>>numBooks>>timeMinutes;
    unsigned short books[numBooks];
    for(int i=0; i<numBooks; i++){
        cin>>books[i];
    }

    int tail=0;
    int head=0;
    int currentTime=0;
    int answer=0;
        
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
