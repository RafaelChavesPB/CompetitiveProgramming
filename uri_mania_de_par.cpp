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
#define MAX 103456789
#define MIN -123456789
#define PI pair<int, int>
#define PB push_back
#define LL long long
#define F first
#define S second
#define LIM 100001
#define MOD 1'000'000'007
using namespace std;


vector<vector<PI>> adj;
vector<vector<int>> dist(2);

void spfa(int s, int n)
{
    vector<vector<bool>> inqueue(2,vector<bool>(n+1, false));
    queue<PI> q;
    dist[0][s] = 0;
    q.push({s, 0});
    inqueue[0][s] = 1;

    while (q.size())
    {
        int curr = q.front().F;
        int parity = q.front().S;
        q.pop();
        inqueue[parity][curr] = 0;
        
        FORIT(adj[curr])
        {
            int viz = IT.F;
            int d = IT.S;
            if(dist[parity][curr] + d < dist[!parity][viz]){
                dist[!parity][viz] = dist[parity][curr] + d;
                if(inqueue[!parity][viz])
                    continue;
                q.push({viz, !parity});
                inqueue[!parity][viz] = true;
            }
        }
    }
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b, w;
    cin >> n >> m;
    adj.resize(n + 1);
    dist[0].assign(n + 1, MAX);
    dist[1].assign(n + 1, MAX);

    FOR(0, m)
    {
        cin >> a >> b >> w;
        adj[a].PB({b, w});
        adj[b].PB({a, w});
    }


    spfa(1, n);

    if(dist[0][n] == MAX)
        cout << -1 << endl;
    else
        cout << dist[0][n] << endl;

    return 0;
}