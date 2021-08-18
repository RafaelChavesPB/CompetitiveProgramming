#include <bits/stdc++.h>
#define LL long long
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(int i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
#endif

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[200'001];
    int n, ini=0, ans = 1;
    cin>>n>>arr[0];
    
    for(int i=1;i<n;i++){
        cin>>arr[i];
        if(arr[i]>2*((LL)arr[i-1])){
            ans = max(ans,i-ini);
            ini = i;
        }
    }
    ans = max(n-ini,ans);
    cout<<ans<<endl;
    return 0;
}