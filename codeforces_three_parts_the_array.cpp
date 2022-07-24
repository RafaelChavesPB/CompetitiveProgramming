//Problema Disponível em: https://codeforces.com/problemset/problem/1006/C
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
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<LL> arr(n+1);
    vector<LL> suffix(n+1,0);
    FOR(0,n)
        cin>>arr[i];
    FORR(n,0)
        suffix[i] = arr[i] + suffix[i+1];
    LL acc = 0;
    LL ans = 0;
    FOR(0,n){
        acc += arr[i];
        if(binary_search(suffix.begin() + i + 1, suffix.end(), acc, greater<LL>())){
            ans = acc;
        }
    }
    cout<<ans<<endl;
    return 0;
}