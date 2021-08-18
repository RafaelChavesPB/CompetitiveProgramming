//cp template.cpp captain_flint_and_crew_recruitment.cpp && code captain_flint_and_crew_recruitment.cpp
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
        int n;
        cin>>n;
        if(n<=30){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            if(n == 36 or n == 40 or n == 44){
                cout<<6<<' '<<10<<' '<<15<<' '<<n-31<<endl;
            }else{
                cout<<6<<' '<<10<<' '<<14<<' '<<n-30<<endl;
            }
        }
    }
    return 0;
}