#include <bits/stdc++.h>
#define LL long long
#define LIM 1000000000
#define DEBUG
#ifdef DEBUG 
    #define bug(X) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<" "<< X <<endl; }
    #define bugV(X,N) { cout<<"*** DEBUG *** "<<__LINE__<<" "<<#X <<':'; for(LL i = 0; i < N; i++ ) cout<< X[i] <<' ';  cout<<endl; }
#else
    #define bug(X) {;}
    #define bugV(X,N) {;}
#endif


using namespace std;

LL is_valid(int arr[],int ans[],int n, LL acc){
    LL result = 0;
    for(int i=0;i<n;i++){
        if(i>0 and !(ans[i]%ans[i-1]==0 or ans[i-1]%ans[i]==0)){
            bug(ans[i]);
            bug(ans[i-1]);
            return false;
        }
        result+=abs(arr[i]-ans[i]);
    }
    return 2*result <= acc;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[51]={0};
    int b[51]={0};
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> div;
        LL acc = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            acc+=a[i];
        }
        LL media = acc/n;
        media-=media%2;
        for(LL i=1;i<=LIM;i=i<<1){
            div.push_back(i);

        }
        for(int i=0;i<n;i++){
            int lb = lower_bound(div.begin(),div.end(),a[i])-div.begin();
            int up = (upper_bound(div.begin(),div.end(),a[i]))-div.begin()-1;
            if(up>=0){
                b[i] = div[up];
            }
            if(lb!=div.size() and abs(a[i]-div[lb]) < abs(a[i] -div[up])){
                b[i] = div[lb];
            }
        }
        for(int i=0;i<n;i++){
            cout<<b[i]<<' ';
        }
        cout<<endl;
        cout<<is_valid(a,b,n,acc)<<endl;
    }
    return 0;
}