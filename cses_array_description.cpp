//Problema Disponível em: 
#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugC(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
    #define bugM(X,N,M) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) { for(int j = 0; j < M; j++) cout<< X[i][j] << ' ' ;  cout<<endl; }}
#else
    #define bug(X) {;}
    #define bugC(X) {;}
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
#define LIM 100001
#define MOD 1'000'000'007
using namespace std;


int sum(int a, int b){
    return (a + b) % MOD;
}

int solve(int n, int m, int arr[]){
    int mem[n+1][m+2];

    FOR(0, n+1)
        FORJ(0, m+2)
            mem[I][J] = 0;
    
    if(arr[0])
        mem[0][arr[0]] = 1; 
    else
        FOR(1, m+1)
            mem[0][I] = 1;
    
    FOR(1, n)
        FORJ(1,m+1)
            if(arr[I] == 0 or arr[I] == J)
                mem[I][J] = sum(sum(mem[I-1][J-1], mem[I-1][J]), mem[I-1][J+1]);

    int ans = 0;        
    FOR(1,m+1)
        ans = sum(ans, mem[n-1][I]);
    
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[LIM];
    int n, m;
    cin >> n >> m;

    FOR(0, n)
        cin >> arr[I];
    
    cout << solve(n, m, arr) << endl;
    return 0;
}