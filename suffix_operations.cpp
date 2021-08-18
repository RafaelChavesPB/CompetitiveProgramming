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
#define LIM 200001
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[LIM];
    int dif[LIM];
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        FOR(0,n){
            cin>>arr[i];
            if(i>0){
                dif[i]=abs(arr[i]-arr[i-1]);
            }else{
                dif[i]=0;
            }
        }
        int ans = 0;
        LL acc = 0;
        FOR(0,n){
            acc+=dif[i];
            int diff;
            if(i==0){
                diff = abs(arr[0]-arr[1]);
            }else if(i==n-1){
                diff = abs(arr[n-1]-arr[n-2]);
            }else{
                diff = abs(arr[i]-arr[i-1])+abs(arr[i]-arr[i+1])-abs(arr[i-1]-arr[i+1]);
            }
            ans = max(diff, ans);    
        }
        cout<<acc-ans<<endl;
    }

    return 0;
}