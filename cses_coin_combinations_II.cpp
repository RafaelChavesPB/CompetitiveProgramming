//Problema Disponível em: 
#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
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
#define LIM 101
#define MOD 1000000007
using namespace std;

int sum(int a, int b){
    return (a + b) % MOD;
}

int solve(int arr[], int n, int x){
    int mem[x+1] = {1};

    FOR(0,n){
        FORJ(arr[I], x+1){
               mem[J] = sum(mem[J], mem[J-arr[I]]);
        }
    }

    return mem[x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    int arr[LIM];
    cin >> n >> x;
    
    FOR(0,n)
        cin >> arr[I];

    cout << solve(arr, n, x) << endl;
    return 0;
}