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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        LL p[2] = {0,1}, ini = 0, ans = 0, first_q = -1, len;

        FOR(0,s.size()){

            if(s[I]!='?'){
                p[s[I]-'0'] = 1 & I;
                p[!(s[I]-'0')] =  !(1 & I);       
            }    
        }

        FOR(0,s.size() + 1){

            if(I == s.size()){
                len = I - ini;
                ans += len*(len + 1)/2;

            }else if(s[I] == '?'){

                if(first_q == -1)
                    first_q = I;

            }else if(p[s[I]-'0'] != I%2){
                len = I - ini;
                ans += len*(len + 1)/2; 

                if(first_q == -1){
                    ini = I;

                }else{
                    len = I-first_q;
                    ans -= len*(len+1)/2;
                    ini = first_q;
                    first_q = -1;
                }
                p[s[I]-'0'] = 1 & I;
                p[!(s[I]-'0')] =  !(1 & I);

            }else{
                first_q = -1;
            }
        }
        cout << ans << endl; 
    }
    return 0;
}