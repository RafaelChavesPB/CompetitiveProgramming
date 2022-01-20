//Problema Disponível em:
#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG
#define bug(X) {cout << "*** DEBUG *** " << __LINE__ << " " << #X << " " << X << endl;}
#define bugC(X) {cout << "*** DEBUG *** " << __LINE__ << " " << X << endl;}
#define bugV(X, N) {cout << "*** DEBUG *** " << __LINE__ << " " << #X << ':'; for (int i = 0; i < N; i++) cout << X[i] << ' '; cout << endl;}
#define bugP(X, N) {cout << "*** DEBUG *** " << __LINE__ << " " << #X << ':'; for (int i = 0; i < N; i++) cout << '(' << X[i].first << ',' << X[i].second << ')'; cout << endl;}
#define bugM(X, N, M){cout << "*** DEBUG *** " << __LINE__ << " " << #X << ":\n";for (int i = 0; i < N; i++){ for (int j = 0; j < M; j++) cout << X[i][j] << ' '; cout << endl;}}
#else
#define bug(X) {;}
#define bugC(X) {;}
#define bugV(X, N){;}
#define bugP(X, N){;}
#define bugM(X, N, M){;}
#endif
#define FOR(S, E) for (int I = S; I < E; I++)
#define FORJ(S, E) for (int J = S; J < E; J++)
#define FORK(S, E) for (int K = S; K < E; K++)
#define FORT(S, E) for (int T = S; T < E; T++)
#define FORR(S, E) for (int R = S - 1; R >= E; R--)
#define FORIT(OBJ) for (auto &IT : (OBJ))
#define FORIT_(OBJ) for (auto IT = OBJ.begin(); IT != OBJ.END(); IT++)
#define LLMAX 12345678901234567
#define LLMIN -12345678901234567
#define MAX 123456789
#define LL long long
#define MIN -123456789
#define PI pair<int, int>
#define PL pair<LL, LL>
#define PB push_back
#define F first
#define S second
#define LIM 100001
#define MOD 1000000007
using namespace std;

vector<vector<int>> adj;
vector<int> pd;
vector<int> visitado;

LL sum(LL a, LL b){
    return (a + b) % MOD;
}

void dfs(int v){
    visitado[v] = 1;
    FORIT(adj[v]){
        if(!visitado[IT]){
            dfs(IT);
        }
    }
}

LL rec(int v, int l){
    if(v > l)
        return 1;
    
    if(pd[v] == -1){
        LL acc = 0;
        FORIT(adj[v]){
            acc = sum(acc, rec(IT, l));
        }
        pd[v] = acc;
    }

    return pd[v];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    cin >> n >> l;
    pd.assign(n + 1, -1);
    visitado.assign(n + 1, 0);
    adj.resize(n + 1);
    
    FOR(1, l + 1){
        int k;
        cin >> k;
        FORK(0,k){
            int a;
            cin >> a;
            adj[I].PB(a);
        }
    }

    dfs(1);
    int b = 0;
    FOR(l + 1, n + 1){
        b += visitado[I];
    }

    LL a = rec(1, l);

    cout << a << ' ' << b << endl;

    return 0;
}