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
#define PSI pair<PI,string>
#define PB push_back
#define LL long long
#define S second
#define F first
#define LIM 100001
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        string s;
        int n;
        cin >> n >> s;
        int zeros = 0;
        FOR(0,n){
            if(s[I] == '0')
                zeros++;
        }
        if(zeros%2){
            if(zeros == 1)
                cout << "BOB" << endl;
            else 
                cout << "ALICE" << endl;
        }else{
            cout << "BOB" << endl;
        }
    }
    return 0;
}