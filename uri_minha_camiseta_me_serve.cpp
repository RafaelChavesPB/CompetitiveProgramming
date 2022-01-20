//Problema Disponível em:
#include <bits/stdc++.h>
#define SUBMIT
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
#define MAX 123456789
#define MIN -123456789
#define PI pair<int, int>
#define PB push_back
#define LL long long
#define F first
#define S second
#define LIM 40
#define MOD 1'000'000'007
using namespace std;

map<string, int> labels = {{"XXL", 2}, {"XL", 3}, {"L", 4}, {"M", 5}, {"S", 6}, {"XS", 7}};

int n, m;
int capacity[LIM][LIM];
int adj[LIM][LIM];
vector<int> parent;

int bfs(int s, int t) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<PI> q;
    q.push({s, MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        FOR(0,n){
            if(adj[cur][I]){
                if (parent[I] == -1 && capacity[cur][I]) {
                    parent[I] = cur;
                    int new_flow = min(flow, capacity[cur][I]);
                    if (I == t){
                        return new_flow;
                    }
                    q.push({I, new_flow});
                }
            }
        }
    }

    bugV(parent, n);

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    parent.assign(n, -1);
    int new_flow;

    while (new_flow = bfs(s, t)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        memset(adj, 0, sizeof(adj));
        memset(capacity, 0, sizeof(capacity));
        cin >> m >> N;
        n = N + 8;

        FOR(2,8){
            adj[0][I] =  adj[I][0] = 1;
            capacity[0][I] = m/6;
        }

        FOR(8, n){
            string temp;
            int a;

            FORJ(0,2){
                cin >> temp;
                a = labels[temp];
                adj[I][a] = adj[a][I] = 1;
                capacity[a][I] = 1;
            }
            adj[1][I] = adj[I][1] = 1;
            capacity[I][1] = 1;
        }

        int ans = maxflow(0, 1);
        cout << (ans == N? "YES" : "NO") << endl;
        bugM(adj, 15, 15);
    }
    return 0;
}