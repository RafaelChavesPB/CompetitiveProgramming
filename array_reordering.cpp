//Problema Disponível em: https://codeforces.com/problemset/problem/1535/B
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
#define LIM 100001
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, even = 0, ans = 0;
        cin>>n;
        vector<int> odd;
        FOR(0,n){
            int temp;
            cin>>temp;
            if(temp%2){
                odd.push_back(temp);
            }else{
                even++;
            }
        }
        while(even--)
            ans += even + odd.size();
        FOR(0,odd.size()){
            FORJ(i+1,odd.size()){
                ans += __gcd(odd[i],odd[j]) > 1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}