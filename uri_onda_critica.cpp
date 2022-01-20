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
        ;
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
#define LIM 100001
#define MOD 1'000'000'007
using namespace std;

map<int, vector<int>> pontos;
vector<PI> input;

int solve(int h, int s){
    int n = pontos[h + 1].size(), m = pontos[h - 1].size();
    int i = 0, j = 0, x = 0, step = s, result = 0;
    
    while(true){

        if(step == 1){

            while(i < n and pontos[h + step][i] < x )
                i++;

            if(i == n)
                break;
            x = pontos[h + step][i++] + 1;
            result++;
            step = -1;

        }else{

            while(j < m and pontos[h + step][j] < x)
                j++;

            if(j == m)
                break;

            x = pontos[h + step][j++] + 1;
            result++;
            step = 1;
        }

    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n){
        int maior = MIN;
        int menor = MAX;
        pontos.clear();
        input.clear();
        FOR(0,n){
            int x, y;
            cin >> x >> y;
            maior = max(maior, y);
            menor = min(menor, y);
            input.PB({x, y});
        }

        sort(input.begin(), input.end());

        FORIT(input){
            pontos[IT.S].PB(IT.F);
        }

        int ans = 0;
        FOR(menor + 1, maior){
            ans = max(ans, max(solve(I, 1), solve(I, -1)));
        }

        cout << ans << endl;
    }
    return 0;
}