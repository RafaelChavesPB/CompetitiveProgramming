//Problema Disponível em:
#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG
#define bug(X)                                                                 \
    {                                                                          \
        cout << "*** DEBUG *** " << __LINE__ << " " << #X << " " << X << endl; \
    }
#define bugC(X)                                                   \
    {                                                             \
        cout << "*** DEBUG *** " << __LINE__ << " " << X << endl; \
    }
#define bugV(X, N)                                                \
    {                                                             \
        cout << "*** DEBUG *** " << __LINE__ << " " << #X << ':'; \
        for (int i = 0; i < N; i++)                               \
            cout << X[i] << ' ';                                  \
        cout << endl;                                             \
    }
#define bugM(X, N, M)                                             \
    {                                                             \
        cout << "*** DEBUG *** " << __LINE__ << " " << #X << ":\n"; \
        for (int i = 0; i < N; i++)                               \
        {                                                         \
            for (int j = 0; j < M; j++)                           \
                cout << X[i][j] << ' ';                           \
            cout << endl;                                         \
        }                                                         \
    }
#else
#define bug(X) \
    {          \
        ;      \
    }
#define bugC(X) \
    {           \
        ;       \
    }
#define bugV(X, N) \
    {              \
        ;          \
    }
#define bugM(X, N, M) \
    {                 \
        ;             \
    }
#endif
#define FOR(S, E) for (int I = S; I < E; I++)
#define FORJ(S, E) for (int J = S; J < E; J++)
#define FORK(S, E) for (int K = S; K < E; K++)
#define FORT(S, E) for (int T = S; T < E; T++)
#define FORR(S, E) for (int R = S - 1; R >= E; R--)
#define FORIT(OBJ) for (auto &IT : (OBJ))
#define LLMAX 123456789012345
#define LLMIN -123456789012345
#define LL long long
#define MAX 123456789
#define MIN -123456789
#define PI pair<int, int>
#define PB push_back
#define F first
#define S second
#define LIM 501
#define MOD 1'000'000'007
using namespace std;

vector<vector<LL>> adj;

void floyd_warshall(int n){
    FOR(1,n+1)
        adj[I][I] = 0;
    
    FORK(1, n+1){
        FOR(1, n+1){
            FORJ(1, n+1){
                if(adj[I][K] != LLMAX and adj[K][J] != LLMAX )
                    adj[I][J] = min(adj[I][J], adj[I][K] + adj[K][J]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    adj.assign(n+1, vector<LL>(n+1, LLMAX));
    FOR(0,m){
        int a, b;
        LL w;
        cin >> a >> b >> w;
        adj[a][b] = adj[b][a] = min(adj[b][a], w);
    }

    floyd_warshall(n);
    
    FORK(0, q){
        int a, b;
        cin >> a >> b;
        cout << (adj[a][b] == LLMAX? -1: adj[a][b]) << endl;
    }
    return 0;
}