#include <bits/stdc++.h>
#define N 100000
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int g[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>g[i][j];
        }
    }

    for(int i=0;i<=N;i++){
        g[0][0]=i;
        int sum = g[0][0] + g[0][1] + g[0][2];
        if(sum != g[0][0] + g[1][0] + g[2][0])
            continue;
        g[1][1] = sum - g[1][0] - g[1][2];
        if(sum != g[2][0] + g[1][1] + g[0][2])
            continue;
        if(sum != g[0][1] + g[1][1] + g[2][1])
            continue;
        g[2][2] = sum - g[0][0] - g[1][1];
        if(sum != g[2][0] + g[2][1] + g[2][2])
            continue;
        if(sum != g[0][2] + g[1][2] + g[2][2])
            continue;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cout<<g[j][k]<<' ';
            }
            cout<<endl;
        }
        return 0;
    }
    return 0;
}