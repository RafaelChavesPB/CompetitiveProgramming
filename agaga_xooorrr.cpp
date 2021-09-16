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
#define MIN -123456789
#define PI pair<int,int>
#define PB push_back
#define LL long long
#define F first
#define S second
#define LIM 2002
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mem[LIM][LIM];
    int arr[LIM];
    int t;
    cin >> t;
    bug(t);
    while( t-- ){
        int n;
        cin >> n;

        FOR(1,n+1)
            cin >> arr[I];
        
        FOR(1, n+1){
            int acc = 0;
            FORJ(I, n+1){
                acc ^= arr[J];
                mem[I][J] = acc; 
            }
        }
        string ans = (mem[1][n]? "NO": "YES");
        FOR(1,n-1){
            FORJ(I+1,n){
                if(mem[1][I] == mem[I+1][J] and mem[I+1][J] == mem[J+1][n]){
                    ans = "YES";
                }
            }
        }
        cout << ans << endl;
       
    }
    return 0;
}