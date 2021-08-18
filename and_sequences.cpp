//Problema disponivel em: https://codeforces.com/contest/1513
#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
#endif
#define FOR(S,E) for(int i = S; i < E; i++)
#define FORJ(S,E) for(int j = S; j < E; j++)
#define FORR(S,E) for(int i = S-1; i>= E; i--)
#define LL long long
#define F first
#define S second
#define LIM 200001
#define MOD 1000000007
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[LIM];
    int t;
    cin>>t;
    while(t--){
        int n;
        int all = INT_MAX;
        LL equals = 0;
        cin>>n;
        FOR(0,n){
            cin>>arr[i];
            all&=arr[i];
        }
        FOR(0,n)
            equals+=(all==arr[i]);

        LL ans = (equals)*(equals-1);
        FOR(2, n-1){
            ans *= i;
            ans %= MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}