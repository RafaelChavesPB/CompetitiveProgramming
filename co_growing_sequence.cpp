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
#define FORR(S,E) for(int i = S-1; i>= E; i--)
#define LL long long
#define F first
#define S second
#define LIM 100001
using namespace std;

int operation(int num, int ant){
    int result = 0;
    int it = 1;
    while(it <= ant){
        int a = it&num;
        int b = it&ant;
        if(b and !a)
            result |= it;
        
        it = it*2;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, temp, ant;
        cin>>n>>ant;
        int ans[n]={0};
        FOR(1,n){
            cin>>temp;
            ans[i] = operation(temp,ant);
            ant = temp^ans[i];
        }    
        FOR(0,n)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}