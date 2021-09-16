//Problema Disponível em: 
#include <bits/stdc++.h>
#define SUBMIT
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
#define LIM 101
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[LIM],b[LIM],c[LIM];
    int t;
    cin>>t;
    while(t--){
        
        int n, A = 0, B = 0;
        vector<pair<int,int>> ans;
        cin>>n;
        FOR(0,n){
            
            cin>>a[i];
            A += a[i];
        }
        FOR(0,n){
            
            cin>>b[i];
            B += b[i];
            c[i] = a[i] - b[i];
        }
        if(A == B){

            FOR(0,n)
                FORJ(0,n)
                    while(i!=j and c[i]>0 and c[j]<0){

                        c[i]--;
                        c[j]++;
                        ans.push_back({i+1,j+1});
                    }
                
            
            cout<<ans.size()<<endl;
            FOR(0,ans.size())
                cout<<ans[i].F<<' '<<ans[i].S<<endl;
            bugV(c,n);
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}