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
#define LIM 300001
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[LIM];
    int q;
    cin>>q;
    while(q--){
        int n,k,t,p;
        cin >> n >> k;
        vector<PI> ac(k);
        vector<PI> utils;
        FOR(0,k)
            cin >> ac[I].F;
        FOR(0,k)
            cin >> ac[I].S;
        sort(ac.begin(), ac.end());
        FOR(0,k){
            while(true){
                if(utils.size()){
                    if(utils.back().S + abs(ac[I].F - utils.back().F) < ac[I].S){
                        break;
                    }else if(ac[I].S + abs(ac[I].F - utils.back().F) < utils.back().S){
                        utils.pop_back();
                    }else{
                        utils.PB(ac[I]);
                        break;
                    }
                }else{
                    utils.PB(ac[I]);
                    break;
                }
            }
        }
        FOR(1,utils[0].F+1)
            arr[I] = utils[0].S + abs(utils[0].F - I);
        FOR(utils.back().F,n+1)
            arr[I] = utils.back().S + abs(I-utils.back().F);
        FOR(1,utils.size())
            FORJ(utils[I-1].F,utils[I].F)
                arr[J] = min(utils[I-1].S + abs(J-utils[I-1].F), utils[I].S + abs(J-utils[I].F));
        
        FOR(1,n+1){
            cout << arr[I] << ' '; 
        }
        cout << endl;
        

    }
    return 0;
}