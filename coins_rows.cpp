#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
#endif
#define LL long long
#define LIM 100001
#define FOR(S,E) for(int i = S; i < E; i++)
#define FORJ(S,E) for(int j = S; j < E; j++)
#define FORR(S,E) for(int i = S-1; i>= E; i--)
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int grid[2][LIM];
    int suffix[LIM] = {0};
    int prefix[LIM] = {0};
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        suffix[n] = 0;
        grid[0][n] = 0;
        FORJ(0,2)
            FOR(0,n)
                cin>>grid[j][i];
        
        FORR(n,0)
            suffix[i] = grid[0][i+1] + suffix[i+1]; 
        
        FOR(1,n+1)
            prefix[i] = prefix[i-1] + grid[1][i-1];
        
        int ans = INT_MAX;
        FOR(0,n){
            ans = min(ans,max(prefix[i],suffix[i]));
        }
        cout<<ans<<endl;
    }
    
    return 0;
}