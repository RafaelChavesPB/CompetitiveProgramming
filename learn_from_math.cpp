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
#define LIM 1000001

using namespace std;

int sieve[LIM]={0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FOR(2,sqrt(LIM)+1){
        if(sieve[i]==0){
            for(int j=2*i;j<LIM;j+=i){
                sieve[j] = 1;
            }    
        }
    }

    int n;
    cin>>n;
    FOR(2,n-1){
        int j = n-i;
        if(sieve[i]==1 and sieve[j]==1){
            cout<<i<<' '<<j<<endl;
            break;
        }
    }
    return 0;
}