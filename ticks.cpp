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
#define LIM 3501
#define MOD 1'000'000'007
using namespace std;

vector<string> grid;
vector<vector<int>> painted;
PI d[] = {{-1, -1}, {-1, 1}};


bool find(int i, int j, int k, int dir){
    if(k == 0)
        return 0;

    if(painted[i][j] == 0)
        return 1;

    return find(i + d[dir].F, j + d[dir].S, k - 1, dir);
}


void paint(int i, int j, int k, int dir){
    if(k > 0){
        paint(i + d[dir].F, j + d[dir].S, k - 1, dir);
        painted[i][j] = 1;
    }
}


int rec(int i, int j, int m, int dir){
    if(i < 0 or j < 0 or j == m or grid[i][j]!='*')
        return 0;

    return rec(i + d[dir].F, j + d[dir].S, m, dir) + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){

        int n, m, k;
        cin >> n >> m >> k;
        grid.assign(n, "");
        painted.assign(n, vector<int>(m, 0));

        FOR(0, n)
            cin >> grid[I];

        bool flag = true;

        FORR(n, 1)
        {
            FOR(1, m-1)
            {
                if(grid[R][I] == '*'){
                    
                    int a = rec(R, I, m, 0);
                    int b = rec(R, I, m, 1);
                    int size = min(a, b);

                    if(size > k){
                        
                        paint(R, I, size, 0);
                        paint(R, I, size, 1);
                    }
                }
            }
        }

        FOR(0, n){
            FORJ(0, m){
                if(grid[I][J] == '*' and painted[I][J] == 0 ){
                    flag = false;
                }
            }
        }

        bugM(grid, n, m);
        bugM(painted, n, m);

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}