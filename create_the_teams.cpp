#include <bits/stdc++.h>
#define LL long long
#define N 100001
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
    int t;
    int arr[N];
    cin>>t;
    while(t--){
        int n,x, ans=0;
        cin>>n>>x;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int tam = 1;
        while(tam<=n){
            int limit = x/tam + (x%tam>0); 
            int pos = lower_bound(arr,arr+n,limit) - arr;
            bug(pos);
            if(n-pos>=tam){
                int qtd = (n-pos)/tam;
                while(qtd--){
                    n-=tam;
                    ans++;
                }
            }
            tam++;
        }
        cout<<ans<<endl;
    }
    return 0;
}