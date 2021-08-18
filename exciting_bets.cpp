//Problema Disponível em: https://codeforces.com/problemset/problem/1543/A
#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
#endif
#define FOR(S,E) for(int i = S; i < E; i++)
#define FORJ(S,E) for(int j = S; j < E; j++)
#define FORR(S,E) for(int i = S-1; i>= E; i--)
#define LL long long
#define F first
#define S second
#define LIM 100001
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a==b){
            cout<<0<<' '<<0<<endl;
        }else{
            LL gcd = abs(a-b);
            LL diff = min(a%gcd, gcd-(a%gcd));
            cout<<gcd<<' '<<diff<<endl; 
        }
    }
    return 0;
}