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
    int n;
    cin>>n;
    string names[n];
    string roles[n];
    FOR(0,n)
        cin>>names[i]>>roles[i];
    FOR(0,n)
        if(roles[i]=="rat")
            cout<<names[i]<<endl;  
    FOR(0,n)
        if(roles[i]=="woman" or roles[i]=="child")
            cout<<names[i]<<endl;  
    FOR(0,n)
        if(roles[i]=="man")
            cout<<names[i]<<endl;   
    FOR(0,n)
        if(roles[i]=="captain")
            cout<<names[i]<<endl;   
    return 0;
}