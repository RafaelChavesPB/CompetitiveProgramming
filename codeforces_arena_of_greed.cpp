//Problema disponivel em: https://codeforces.com/problemset/problem/1425/A
#include <bits/stdc++.h>
#define LL long long
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
#endif

using namespace std;

LL rec(int p, LL n, LL v){
    if(n == 0){
        return 0;
    }
    if(n%2)
        return rec(!p,n-1,v)+(p?1:0);
    if(n%4 == 0 and n>5)
        return rec(!p,n-1,v)+(p?1:0);
    return rec(!p,n/2,v)+(p?n/2:0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        LL n;
        cin>>n;
        cout<<rec(1,n,0)<<endl;
    }
    return 0;
}