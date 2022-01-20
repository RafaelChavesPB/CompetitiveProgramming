//Problema Disponível em:
#include <bits/stdc++.h>
#define DEBUG
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while(t--){
    
        int n, m, maxI = 1, maxJ = 1, iniI = 1, iniJ = 1, nowI = 1, nowJ = 1;
        string commands;
        cin >> n >> m >> commands;
        
        FORIT(commands){

            if(IT == 'U'){

                if(nowI == 1){
                    maxI++;
                    
                    if(maxI > n)
                        break;
                    
                    iniI++;

                }else{
                    nowI--;
                }

            }else if(IT == 'D'){
                
                if(nowI == n)
                    break;

                nowI++;
                maxI = max(maxI, nowI);

            }else if(IT == 'L'){
                
                if(nowJ == 1){
                    maxJ++;
                    
                    if(maxJ > m)
                        break;

                    iniJ++;

                }else{
                    nowJ--;
                }

            }else{

                if(nowJ == m)
                    break;

                nowJ++;
                maxJ = max(nowJ, maxJ);
            }
        }

        cout << iniI << ' ' << iniJ << endl;
    }
    return 0;
}