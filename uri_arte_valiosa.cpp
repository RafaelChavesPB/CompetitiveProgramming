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

vector<vector<int>> adj;
vector<int> ff;

void dfs(int f, int v){
    ff[v] = f;
    FORIT(adj[v])
        if(ff[IT] == 0)
            dfs(f, IT);
}

int dist(PI a, PI b){
    return sqrt(pow(a.F-b.F, 2)+pow(a.F-b.S, 2));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, k;
    cin >> N >> M >> k;
    adj.resize(k+4);
    vector<PI> pos(k+1);
    vector<int> r(k+1);
    ff.resize(k+4,0);
    int U = k, D = k + 1, L = k + 2, R = k + 3;

    FOR(0,k)
        cin >> pos[I].F >> pos[I].S >> r[I];

    FOR(0,k){

        if(pos[I].F - r[I] <= 0){
            adj[I].PB(L);
            adj[L].PB(I);
        }
        
        if(pos[I].F + r[I] >= M){
            adj[I].PB(R);
            adj[R].PB(I);
        }
        
        if(pos[I].S - r[I] <= 0){
            adj[I].PB(U);
            adj[U].PB(I);
        }

        if(pos[I].S + r[I] >= N){
            adj[I].PB(D);
            adj[D].PB(I);
        }

        FORJ(0,k){
            if(dist(pos[I],pos[J]) <= r[I]+r[J]){
                adj[I].PB(J);
                adj[J].PB(I);
            }
        }
    }

    int f = 0;
    
    FOR(0,k+4)
        if(ff[I] == 0)
            dfs( ++f, I);
        
    if(ff[U] == ff[L] or ff[R] == ff[D] or ff[U] == ff[D] or ff[L] == ff[R])
        cout << "N" <<endl;
    else
        cout << "S" <<endl;

    return 0;
}