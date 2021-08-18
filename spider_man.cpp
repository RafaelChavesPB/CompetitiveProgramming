// Problema disponível em: https://codeforces.com/problemset/problem/705/B

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    long long acc = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p;
        acc+=p-1;
        cout<<2-(acc%2)<<endl;
    }
}