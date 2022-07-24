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
#define FOR(S,E) for(int i = S; i < E; i++)
#define FORJ(S,E) for(int j = S; j < E; j++)
#define FORK(S,E) for(int k = S; k < E; k++)
#define FORR(S,E) for(int i = S-1; i>= E; i--)
#define LL long long
#define F first
#define S second
#define LIM 50'001
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int grid[LIM][5];
    int t;
    cin>>t;     
    while(t--){
        int n, pos = 0;
        cin>>n;
        FOR(0,n){
            FORJ(0,5)
                cin>>grid[i][j];
        }
        FOR(1,n){
            int a = 0;
            FORJ(0,5)
                a += grid[pos][j] > grid[i][j];
            if(a > 2)
                pos = i;
        }
        bool flag = true;
        FOR(0,pos){
            int a = 0;
            FORJ(0,5)
                a += grid[pos][j] > grid[i][j];
            if(a > 2)
                flag = false;
        }
        if(!flag){
            cout<<-1<<endl;
        }else{
            cout<<pos+1<<endl;
        }
    }
    return 0;
}