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
#define LIM 1001
#define MOD 1'000'000'007
using namespace std;

vector<string> grid;
int visited[LIM] = {0};
int freq[LIM] = {0};

vector<int> pessoas;

void dfs(int v, int n){
    visited[v] = 1;
    pessoas.PB(v);
    FOR(0, n){
        if( grid[v][I] == 'S' and !visited[I])
            dfs(I, n);
    }   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    grid.resize(n);
    
    FOR(0,n)
        cin >> grid[I];

    bool valid = true;
    int count = 0;
    FOR(0,n){
        if(!visited[I]){
            dfs(I, n);
            FORIT(pessoas){
                FORJ(0, pessoas.size()){
                    if(grid[IT][pessoas[J]] == 'D'){
                        valid = false;
                    }
                }
            }
            freq[count] = pessoas.size();
            pessoas.clear();
            count++;
        }
    }
    if(valid){
        sort(freq, freq + count, greater<int>());
        cout << count << endl;
        FOR(0, count){
            if(I)
                cout << ' ';
            cout << freq[I];
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}