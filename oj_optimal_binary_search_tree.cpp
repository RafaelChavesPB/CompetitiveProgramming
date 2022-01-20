//Problema Disponível em:
#include <bits/stdc++.h>
#define SUBMIT
#ifdef DEBUG
#define bug(X) {cout << "*** DEBUG *** " << __LINE__ << " " << #X << " " << X << endl;}
#define bugC(X) {cout << "*** DEBUG *** " << __LINE__ << " " << X << endl;}
#define bugV(X, N) {cout << "*** DEBUG *** " << __LINE__ << " " << #X << ':'; for (int i = 0; i < N; i++) cout << X[i] << ' '; cout << endl;}
#define bugP(X, N) {cout << "*** DEBUG *** " << __LINE__ << " " << #X << ':'; for (int i = 0; i < N; i++) cout << '(' << X[i].first << ',' << X[i].second << ')'; cout << endl;}
#define bugM(X, N, M){cout << "*** DEBUG *** " << __LINE__ << " " << #X << ":\n";for (int i = 0; i < N; i++){ for (int j = 0; j < M; j++) cout << X[i][j] << ' '; cout << endl;}}
#else
#define bug(X) {;}
#define bugC(X) {;}
#define bugV(X, N){;}
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
#define MAX 123456789
#define LL long long
#define MIN -123456789
#define PI pair<int, int>
#define PL pair<LL, LL>
#define PB push_back
#define F first
#define S second
#define LIM 251
#define MOD 1'000'000'007
using namespace std;

int mem[LIM][LIM];
int prefix[LIM];
int arr[LIM];

int rec(int l, int r){

    if(l >= r)
        return 0;
    
    if(mem[l][r] == -1){

        int result = MAX;

        FOR(l, r + 1)
            result = min(result, rec(l, I - 1) + (prefix[I] - prefix[l]) +  rec(I + 1, r) + (prefix[r+1] - prefix[I + 1]));

        mem[l][r] = result;
    }

    return mem[l][r];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while(cin >> n){
        prefix[0] = 0;
        FOR(0, n){
            cin >> arr[I];
            prefix[I + 1] = prefix[I] + arr[I];
        }

        bugV(prefix, n + 1);
        
        FORJ(0, n)
            FORK(J + 1, n)
                mem[J][K] = -1;

                bugM(mem, n, n);

        cout << rec(0, n - 1) << endl;
    }

    return 0;
}