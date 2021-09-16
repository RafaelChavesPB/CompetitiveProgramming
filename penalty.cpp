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
#define FORR(S,E) for(int R = S-1; R>= E; R--)
#define MAX 123456789
#define MIN -123456789
#define PI pair<int,int>
#define PB push_back
#define LL long long
#define F first
#define S second
#define LIM 100001
using namespace std;

int solve(int bm, string s){
    int bit = 0;
    int pos[2] = {5, 5};
    int goals[2] = {0, 0};

    FOR(0,s.size()){

        if(s[I] == '0'){
            pos[I%2]--;
        }else if(s[I] == '1'){
            goals[I%2]++; 
        }else{
            if(bm & 1<<bit)
                goals[I%2]++; 
            else
                pos[I%2]--;
            bit++;
        }
        if(pos[0] < goals[1] or pos[1] < goals[0])
            return I+1;
    }
    return 10;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while(t--){
        string s;
        int q = 1, ans = MAX; 
        cin >> s;

        FOR(0,s.size())
            if(s[I] == '?')
                q = q<<1;

        FOR(0,q){
            ans = min(ans, solve(I, s));
        }
        cout << ans << endl;
    
    }
    return 0;
}