//Problema Disponível em: 
#include <bits/stdc++.h>
#define SUBMIT
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
#define PB push_back
#define PI pair<int,int>
#define F first
#define S second
#define LIM 100001
using namespace std;

int  solve(int n, int a, int b){
    while(n>1){
        bug(n);
        if(n%a == 0 and a!=1){
            n/=a;
        }
        else{
            n-=b;
        }
    }
    return n == 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>b>>a;
        cout<<(solve(n,b,a)?"YES":"NO")<<endl;
    }
    return 0;
}