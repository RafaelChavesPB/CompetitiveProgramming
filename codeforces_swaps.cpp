    //Problema Disponível em: 
    #include <bits/stdc++.h>
    #define DEBUG
    #ifdef DEBUG 
        #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
        #define bugC(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<< X <<endl; }
        #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
        #define bugM(X,N,M) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) { for(int j = 0; j < M; j++) cout<< X[i][j] << ' ' ;  cout<<endl; }}
    #else
        #define bug(X) {;}
        #define bugC(X) {;}
        #define bugV(X,N) {;}
        #define bugM(X,N,M) {;}
    #endif
    #define FOR(S,E) for(int I = S; I < E; I++)
    #define FORJ(S,E) for(int J = S; J < E; J++)
    #define FORK(S,E) for(int K = S; K < E; K++)
    #define FORT(S,E) for(int T = S; T < E; T++)
    #define FORR(S,E) for(int R = S-1; R>= E; R--)
    #define FORIT(OBJ) for(auto IT: (OBJ))
    #define LLMAX 123456789012345
    #define LLMIN -123456789012345
    #define MAX 123456789
    #define MIN -123456789
    #define PI pair<int,int>
    #define PB push_back
    #define LL long long
    #define F first
    #define S second
    #define LIM 100001
    #define MOD 1'000'000'007
    using namespace std;
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int a[LIM];
        int t;
        cin >> t;
        while(t--){
            int n, temp, last;
            vector<int> b, idx;
            cin >> n;
            FOR(0,n)
                cin >> a[I];
            cin >> temp;
            b.PB(temp);
            idx.PB(0);
     
            FOR(1,n){
                cin >> temp;
                if(temp > b.back()){
                    b.PB(temp);
                    idx.PB(I);
                }
            }
     
            int ans = MAX;
            FOR(0,n){
                int p = lower_bound(b.begin(), b.end(), a[I]) - b.begin();
                if(p < b.size())
                ans = min(I+idx[p], ans);
            }
            
            cout << ans << endl;
        }
        return 0;
    }