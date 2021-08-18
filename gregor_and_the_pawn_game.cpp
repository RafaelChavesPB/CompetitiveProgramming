//cp template.cpp gregor_and_the_pawn_game.cpp && code gregor_and_the_pawn_game.cpp
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
        int n, ans = 0;
        cin>>n;
        string a,b;
        cin>>a>>b;
        FOR(0,n){
            if(i==0){
                if(b[i] == '1'){
                    if(a[i] == '0'){
                        ans++;
                        a[i] = '!';
                    }else if(a[i+1] == '1'){
                        a[i+1] = '!';
                        ans++;
                    }
                }
            }else if(i==n-1){
                if(b[i] == '1'){
                    if(a[i] == '0'){
                        ans++;
                        a[i] = '!';
                    }else if(a[i-1] == '1'){
                        a[i-1] = '!';
                        ans++;
                    }
                }
            }else{
                if(b[i] == '1'){
                    if(a[i] == '0'){
                        ans++;
                        a[i] = '!';
                    }else if(a[i-1] == '1'){
                        a[i-1] = '!';
                        ans++;
                    }else if(a[i+1] == '1'){
                        a[i+1] = '!';
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}