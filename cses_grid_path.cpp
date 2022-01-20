//Problema Disponível em: 
#include <bits/stdc++.h>
#define SUBMIT
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
    #define bugM(X,N,M) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) { for(int j = 0; j < M; j++) cout<< X[i][j] << ' ' ;  cout<<endl; }}
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
    #define bugM(X,N,M) {;}
#endif
#define FOR(S,E) for(int I = S; I < E; I++)
#define FORJ(S,E) for(int J = S; J < E; J++)
#define FORK(S,E) for(int K = S; K < E; K++)
#define FORT(S,E) for(int T = S; T < E; T++)
#define FORR(S,E) for(int R = S-1; R>= E; R--)
#define FORIT(OBJ) for(auto IT: (OBJ))
#define LLMAX 123456789012345
#define LLMIN -123456789012345
#define MAX 123456789
#define MIN -123456789
#define PI pair<int,int>
#define PB push_back
#define LL long long
#define F first
#define S second
#define LIM 1000;
#define MOD 1'000'000'007
using namespace std;

int sum(int a, int b){
    return (a+b) % MOD;
}

int solve(vector<string> &grid, int n){
    int mem[n][n];

    if(grid[0][0] == '*')
        return 0;

    mem[0][0] = 1;

    FOR(0,n){
        FORJ(0,n){

            if(J or I)
                mem[I][J] = 0;

            if(grid[I][J] == '.'){
                if(I)
                    mem[I][J] = sum(mem[I][J], mem[I-1][J]);
                if(J)
                    mem[I][J] = sum(mem[I][J], mem[I][J-1]);
            }
        }
    }
    bugM(mem,n,n);
    return mem[n-1][n-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> grid(n);

    FOR(0,n)
        cin >> grid[I]; 
    
    cout << solve(grid, n) << endl;
    return 0;
}