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
#define LIM 200001
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[LIM];
    int min_[LIM];
    int t;
    cin>>t;
    set<int> max_;
    while(t--){
        int n, ant, it = 1;
        cin >> n;
        
        FOR(1,n+1){
            max_.insert(I);
            min_[I] = 0;
            cin >> arr[I];
        }
        arr[0] = -1;

        FOR(1,n+1){

            if(arr[I-1]!=arr[I]){
                min_[arr[I]] = 1;
                cout << arr[I] << ' ';

            }else{

                while(min_[it]!=0)
                    it++;
                min_[it] = 1;
                cout << it << ' ';
            }
        }
        cout<<endl;

        FOR(1,n+1){
            if(arr[I-1] != arr[I]){
                max_.erase(arr[I]);
                cout << arr[I] << ' ';
            }else{
                auto ptr = --max_.upper_bound(arr[I]);
                cout << (*ptr) << ' ';
                max_.erase(ptr);
            }
        }
        cout << endl;
        
    }
    return 0;
}