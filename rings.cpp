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
#define LIM 100001
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        if(s.find('0') == string::npos){
            cout << 1 << ' ' << n/2 << ' ' << 2 << ' ' << n/2 + 1 << endl; 
        }else{
            bool flag = false;
            FOR(n/2,n){
                if(s[I] == '0'){
                    flag = true;
                    cout << 1 << ' ' << I + 1 << ' ' << 1 << ' ' << I << endl; 
                    // cout<<s.substr(0,I)<< ' ' << s.substr(0,I+1)<<endl;
                    break;
                }
            }
            if(!flag){
                FOR(0,n/2){
                    if(s[I] == '0'){
                        cout << I + 1 << ' ' << n << ' ' << I + 2 << ' ' << n << endl;
                        // cout<<s.substr(I,n-I)<< ' ' << s.substr(I+1,n-I-1)<<endl;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}