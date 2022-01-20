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
#define PB push_back
#define LL long long
#define F first
#define S second
#define LIM 100001
#define MOD 1'000'000'007
using namespace std;



vector<string> grid;

int dI[] = {1, -1, 0, 0};
int dJ[] = {0, 0, 1, -1};

void dfs(int i, int j, int n, int m){
    grid[i][j] = '#';
    FORK(0,4){
        int I = i + dI[K];
        int J = j + dJ[K];
        if( I < 0 or J < 0 or I == n or J == m or grid[I][J] == '#')
            continue;
        dfs(I, J, n, m);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, rooms = 0;
    cin >> n >> m;
    grid.resize(n);
    FOR(0,n)
        cin >> grid[I];
    FOR(0,n){
        FORJ(0,m){
            if(grid[I][J] == '.'){
                rooms++;
                dfs(I, J, n, m);
            }
        }
    }

    cout << rooms << endl;
    return 0;
}