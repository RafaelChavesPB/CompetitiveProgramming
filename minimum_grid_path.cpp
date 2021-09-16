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
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL arr[LIM];
    int t;
    cin >> t;

    while(t--){
        int n,  qq_odd, qq_even;
        LL min_even, min_odd, ans, q;
        cin >> n;

        FOR(1,n+1)
            cin >> arr[I];
        min_even = arr[2];
        min_odd = arr[1];
        qq_even = qq_odd = 0;
        q = 0; 
        ans = min_even*n + min_odd*n;
        bug(ans);
        FOR(3,n+1){
            if(I%2){
                q += max(arr[I], min_odd);
                min_odd = min(arr[I], min_odd);
                qq_odd++;
            }else{
                q += max(arr[I], min_even);
                min_even= min(arr[I], min_even);
                qq_even++;
            }
            LL now = min_even*(n-qq_even) + q + min_odd*(n-qq_odd);
            bug(now)
            ans = min(now, ans);
        }

        cout << ans << endl;
    }
    return 0;
}