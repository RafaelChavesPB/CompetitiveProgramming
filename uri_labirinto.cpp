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
#define MAX 123456789
#define MIN -123456789
#define PI pair<int, int>
#define PPI pair<PI,int>
#define PB push_back
#define LL long long
#define F first
#define S second
#define LIM 100001
#define MOD 1'000'000'007
using namespace std;

vector<string> grid;

int dI[] = {-1, 0, 0, 1};
int dJ[] = {0, -1, 1, 0};

PPI bfs(int i,  int j, int n, int m){
    vector<vector<int>> visited(n, vector<int>(m, -1));
    queue<PI> q;
    PPI last = {{i,j},0};
    q.push({i, j});
    visited[i][j] = 0;
    while(q.size()){
        PI curr = q.front();
        q.pop();
        FORK(0,4){
            int I = curr.F + dI[K];
            int J = curr.S + dJ[K];
            if(I < 0 or J < 0 or I == n or J == m or grid[I][J] == '#' or visited[I][J]!=-1)
                continue;
            visited[I][J] = visited[curr.F][curr.S] + 1;
            last = {{I, J},  visited[I][J]};
            q.push({I, J});
        }
    }
    return last;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while(cin >> n >> m and n){
        grid.resize(n);
        FOR(0,n)
            cin >> grid[I];

        int flag = 0;

        FOR(0,n){
            FORJ(0,m){
                if(grid[I][J] == '.'){
                    PPI a = bfs(I, J, n, m);
                    PPI b = bfs(a.F.F, a.F.S, n, m);
                    cout << b.S << endl;
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
    }
    return 0;
}