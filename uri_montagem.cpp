//Problema Disponível em:
#include <bits/stdc++.h>
// #define DEBUG
#ifdef DEBUG
#define bug(X) {cout << "*** DEBUG *** " << __LINE__ << " " << #X << " " << X << endl;}
#define bugC(X) {cout << "*** DEBUG *** " << __LINE__ << " " << X << endl;}
#define bugV(X, INI, END) {cout << "*** DEBUG *** " << __LINE__ << " " << #X << ':'; for (int i = INI; i < END; i++) cout << X[i] << ' '; cout << endl;}
#define bugP(X, N) {cout << "*** DEBUG *** " << __LINE__ << " " << #X << ':'; for (int i = 0; i < N; i++) cout << '(' << X[i].first << ',' << X[i].second << ')'; cout << endl;}
#define bugM(X, N, M){cout << "*** DEBUG *** " << __LINE__ << " " << #X << ":\n";for (int i = 0; i < N; i++){ for (int j = 0; j < M; j++) cout << X[i][j] << ' '; cout << endl;}}
#else
#define bug(X) {;}
#define bugC(X) {;}
#define bugV(X, INI, END){;}
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
#define MAX 1234567890
#define LL long long
#define MIN -1234567890
#define PI pair<int, int>
#define PL pair<LL, LL>
#define PB push_back
#define F first
#define S second
#define LIM 19
#define MOD 1'000'000'007
using namespace std;

int pd[(1 << LIM) + 1];
vector<vector<int>> grid(LIM, vector<int>(LIM));



int rec(int group, int n, int p){
    if(p == n + 1)
        return 0;
    
    if(pd[group] == -1){

        pd[group] = MAX;
        
        FOR(0, n){

            if(group & (1 << I))
                continue;

            pd[group] = min(pd[group], rec(group | (1 << I), n, p + 1) + grid[I + 1][p]);
        }

        return pd[group];
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n, n){
        
        FOR(1, n + 1)
            FORJ(1, n + 1)
                cin >> grid[I][J];

        fill(pd, pd + (1 << n), -1);
        cout << rec(0, n, 1) << endl;
            
    }

    
    return 0;
}