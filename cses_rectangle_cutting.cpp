//Problema Disponível em: 
#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugC(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
    #define bugM(X,N,M) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) { for(int j = 0; j < M; j++) cout<< X[i][j] << ' ' ;  cout<<endl; }}
#else
    #define bug(X) {;}
    #define bugC(X) {;}
    #define bugV(X,N) {;}
    #define bugM(X,N,M) {;}
#endif
#define FOR(S,E) for(int I = S; I < E; I++)
#define FORJ(S,E) for(int J = S; J < E; J++)
#define FORK(S,E) for(int K = S; K < E; K++)
#define FORT(S,E) for(int T = S; T < E; T++)
#define FORR(S,E) for(int R = S-1; R>= E; R--)
#define FORIT(OBJ) for(auto IT: (OBJ))
#define LLMAX 123456789012345
#define LLMIN -123456789012345
#define MAX 123456789
#define MIN -123456789
#define PI pair<int,int>
#define PB push_back
#define LL long long
#define F first
#define S second
#define LIM 100001
#define MOD 1'000'000'007
using namespace std;

int solve(int a, int b){
    
    int lim = max(a,b);
    int mem[lim+1][lim+1];

    FOR(0, lim + 1)
        mem[I][I] = 0;
    
    FOR(1,lim + 1){
        FORJ(I+1, lim + 1){
            mem[I][J] = MAX;
            FORK(1,J)
                mem[I][J] = min(mem[I][J], mem[I][K] + mem[I][J-K] + 1);
            FORK(1,I)
                mem[I][J] = min(mem[I][J], mem[K][J] + mem[I-K][J] + 1);
            mem[J][I] = mem[I][J];
        }
    }
    return mem[a][b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}