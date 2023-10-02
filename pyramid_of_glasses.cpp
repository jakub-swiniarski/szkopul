//https://codeforces.com/contest/676/problem/B

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unsigned short height, time;
    const unsigned short capacity=1024; //every glass has a capacity of 1024 to avoid floating point numbers
    cin>>height>>time;
    unsigned short pyramid[50][50];
    unsigned short fullGlasses=0;
    pyramid[0][0]=time*capacity;

    for(int i=0; i<height; i++){
        for(int j=0; j<=i; j++){
            if(pyramid[i][j]>=capacity){
                fullGlasses++;

                unsigned short excess=pyramid[i][j]-capacity;
                
                pyramid[i+1][j]+=excess/2;
                pyramid[i+1][j+1]+=excess/2;
            }
        }
    }
    cout<<fullGlasses<<'\n';

    return 0;
}
