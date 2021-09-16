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
#define LIM 100001
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        int n;
        map<PI,int> freq;
        PI acc(0,0);
        cin>>n>>s;
        
        FOR(0,n){
            if(s[I] == 'K'){
                acc.F++;
            }else{
                acc.S++;
            }
            int gcd = __gcd(acc.F,acc.S); 
            PI curr = {acc.F/gcd, acc.S/gcd};
            cout << ++freq[curr] <<' ';
        }
        cout << endl;
    }
    return 0;
}