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

vector<string> grid, path;

int dJ[] = {0, 1, 0, -1};
int dI[] = {-1, 0, 1, 0};
string dir = "URDL";

void bfs(PI init, int n, int m){
    queue<PI> q;
    q.push(init);
    grid[init.F][init.S] = '#';
    while(q.size()){
        PI curr = q.front();
        q.pop();
        FORK(0,4){
            int I = curr.F + dI[K];
            int J = curr.S + dJ[K];
            if(I < 0 or I == n or J < 0 or J == m or grid[I][J] == '#')
                continue;
            path[I][J] = dir[K];
            grid[I][J] = '#';
            q.push({I, J});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    PI init, end;
    cin >> n >> m;
    grid.resize(n);
    path.assign(n, string(m, '0'));
    FOR(0,n){
        cin >> grid[I];
        FORJ(0,m){
            if(grid[I][J] == 'A')
                init = {I, J};
            if(grid[I][J] == 'B')
                 end = {I, J};
        }
    }

    bfs(init, n, m);

    if(grid[end.F][end.S] == '#'){
        string ans = "";
        while(end != init){
            ans += path[end.F][end.S];
            if(path[end.F][end.S] == 'U'){
                end.F++;
            }else if(path[end.F][end.S] == 'D'){
                end.F--;
            }else if(path[end.F][end.S] == 'L'){
                end.S++;
            }else if(path[end.F][end.S] == 'R'){
                end.S--;
            }
        }
        bugM(path, n, m);
        reverse(ans.begin(), ans.end());

        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}