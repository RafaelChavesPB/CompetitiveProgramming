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
#define bugP(X, N)                                                \
    {                                                             \
        cout << "*** DEBUG *** " << __LINE__ << " " << #X << ':'; \
        for (int i = 0; i < N; i++)                               \
            cout << '(' << X[i].first << ',' << X[i].second << ')';                                  \
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
#define bugP(X, N) \
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
#define LIM 1001
#define MOD 1'000'000'007
using namespace std;

PI arr[LIM];

int knapsak1d(int w, int n){
    vector<int> mem(w+1,0);
    bugV(mem, w + 1);
    FOR(1 ,n + 1){
        FORR(w + 1, 1){
            if(arr[I].F <= R){
                mem[R] = max(mem[R], mem[R - arr[I].F] + arr[I].S);
            }
        }
    }
    int best = 0;

    FOR(1, w + 1)
        best = max(best, mem[I]);

        return best;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w, n, count = 0;
    while(cin >> w >> n, w or n){
        
        FOR(1, n + 1)
            cin >> arr[I].F >> arr[I].S;

        cout << "Teste " << ++count << endl;

        cout << knapsak1d(w, n) << endl << endl;

    }
    return 0;
}