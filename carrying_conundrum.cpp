//Problema Disponível em: 
#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
#endif
#define FOR(S,E) for(int I = S; I < E; I++)
#define FORJ(S,E) for(int J = S; J < E; J++)
#define FORK(S,E) for(int K = S; K < E; K++)
#define FORT(S,E) for(int T = S; T < E; T++)
#define FORR(S,E) for(int R = S-1; R>= E; R--)
#define FORIT(OBJ) for(auto IT: (OBJ))
#define MAX 123456789
#define MIN -123456789
#define PI pair<int,int>
#define PB push_back
#define LL long long
#define F first
#define S second
#define LIM 15
using namespace std;

string s;

LL dp[LIM][2][2];

LL rec(int idx, int cin, int cout){
    if( idx == s.size()){
        if(cin == 0 and cout == 0)
            return 1;
        else
            return 0;
    }
    
    if(dp[idx][cin][cout] == -1){
        dp[idx][cin][cout] = 0;
        FOR(0,10){
            FORJ(0,10){
                int digit = s[idx] - '0';
                if(I + J ==  digit + (cout?10:0))
                    dp[idx][cin][cout] += rec(idx + 1 , 0, cin);
                if(I + J == digit - 1 + (cout?10:0))
                    dp[idx][cin][cout] += rec(idx + 1 , 1, cin);
            }
        }
    }
    return dp[idx][cin][cout];
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>> s;
        FOR(0,LIM)
            FORJ(0,2)
                FORK(0,2)
                    dp[I][J][K] = -1;
                
        s = '0' + s;
        cout << rec(0,0,0) - 2 <<endl;;
    }
    return 0;
}