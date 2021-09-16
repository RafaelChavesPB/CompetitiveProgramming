//Problema Disponível em: 
#include <bits/stdc++.h>
#define SUBMIT
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
#define MAX 123456789
#define MIN -1234567890123456
#define PI pair<int,int>
#define PB push_back
#define LL long long
#define F first
#define S second
#define LIM 2001
using namespace std;

int arr[LIM] = {0};

//     q    it
LL mem[LIM][LIM];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    FOR(1,n+1){
        cin >> arr[I];
    }
    FOR(0,n+1)
        mem[0][I] = 0;
    FOR(1,n+1)
        mem[I][0] = MIN;
    int ans = 0;
    FOR(1,n+1){
        FORJ(1,n+1){
            mem[I][J] = MIN;
            if(arr[J] >= 0){
                   mem[I][J] = mem[I-1][J-1] + arr[J];
            }else{
                if(abs(arr[J]) <= mem[I-1][J-1])
                    mem[I][J] = mem[I-1][J-1] + arr[J];
                mem[I][J] = max(mem[I][J], mem[I][J-1]);
            }
        }
            bug(mem[I][n]);
        if(mem[I][n] >= 0 ){
            ans = I;
        }
    }

    cout<< ans<<endl;
    return 0;
}