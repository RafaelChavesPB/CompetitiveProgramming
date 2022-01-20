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

using namespace std;

// Alterar o limite antes de submeter
int solve(int arr[], int n, int x){
    int mem[x+1] = {0};

    FOR(1,x+1){
        mem[I] = MAX;
        FORJ(0,n){
            if(I >= arr[J])
                mem[I] = min(mem[I-arr[J]] + 1, mem[I]);
        }
    }

    return mem[x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[LIM];
    int n, x;
    cin >> n >> x;
    
    FOR(0, n)
        cin >> arr[I];

    int ans = solve(arr, n, x);

    cout << ( ans == MAX? -1: ans) << endl;

    return 0;
}