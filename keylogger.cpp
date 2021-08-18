#include <bits/stdc++.h>
#define lim 1000000007
using namespace std;

long long K[750+1][750+1];
long long P[10000+1];
long long n, k, l;
long long mem[750+1][10000+1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> l;
    for(int i = 0; i < k; i++)
        for(int j = 0; j < k; j++)
            cin >> K[i][j];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>P[i];        
    }
    for(int t=0;t<=k;t++){
        mem[t][n-1] = t;
    }
    for(int p=0;p<n;p++){
        mem[0][p] = 0;
    }
    for(int p=n-2;p>=0;p--){
        for(int t=0;t<k;t++){
            int ini = lower_bound(K[t],K[t]+k,P[p]-l)-K[t];
            int fin = upper_bound(K[t],K[t]+k,P[p]+l)-K[t];
            mem[t+1][p] = ((mem[fin][p+1] - mem[ini][p+1])%lim + mem[t][p])%lim; 
        }
    }
    
    cout<<mem[k][0]<<endl;

    return 0;
}