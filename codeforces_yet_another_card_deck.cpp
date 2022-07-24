//Problema disponivel em: https://codeforces.com/problemset/problem/1511/C
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q,color;
    cin>>n>>q;
    vector<int> colors(51,0);
    for(int i=1;i<=n;i++){
        cin>>color;
        if(colors[color]==0){
            colors[color]=i;
        }
    }
    while(q--){
        cin>>color;
        int index = colors[color];
        colors[color]=0;
        for(int i=1;i<=50;i++){
            if(colors[i]<index){
                colors[i]++;
            }
        }
        cout<<index<<' ';
    }
    cout<<endl;
    return 0;
}
