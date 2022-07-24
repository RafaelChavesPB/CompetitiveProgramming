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
#define FORIT(OBJ) for(auto &IT: (OBJ))
#define MAX 123456789
#define MIN -123456789
#define PI pair<int,int>
#define PIV pair<LL,vector<LL>>
#define PB push_back
#define LL long long
#define F first
#define S second
#define LIM 2001
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, arr[LIM], ans = 0;
    vector<PIV> groups;
    pair<LL,vector<LL>> curr;
    cin>>n;
    
    FOR(0,n)
        cin >> arr[I];

    FOR(0,n){
    
        if(arr[I] >= 0){
            ans++;
            if(curr.S.empty()){
                curr.F += arr[I];
    
            }else{
                groups.PB(curr);
                curr = {arr[I],vector<LL>()};
            }        
    
        }else{
            curr.S.PB(abs(arr[I]));
        }
    }
    groups.PB(curr);

    
    LL acc = 0; 
    FORJ(0,groups.size()){
        groups[J].F += acc;
        sort(groups[J].S.begin(), groups[J].S.end());
        FOR(0,groups[J].S.size()){
            if(groups[J].S[I] <= groups[J].F){
                groups[J].F -=  groups[J].S[I];
                ans ++;
            }else{
                acc = groups[J].F;
                break;
            }
        }
    }
    cout << ans <<endl;
    return 0;
}