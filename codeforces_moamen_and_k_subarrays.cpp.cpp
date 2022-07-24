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
    vector<PI> arr(LIM);
    int t;
    cin>>t;
    
    while(t--){
        int n, k, prv, curr, groups = 1;
        cin >> n >> k;

        FOR(0, n){
            cin >> arr[I].F;
            arr[I].S = I;
        }
        sort(arr.begin(), arr.begin() + n);

        FOR(1,n)
            if(arr[I].S != arr[I-1].S + 1)
                groups ++; 
        
        if(k >= groups){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}