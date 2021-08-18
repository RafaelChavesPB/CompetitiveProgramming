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
    int b_odd[51]={0};
    int b_even[51]={0};
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        LL acc =0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            acc+=a[i];
            if(i%2){
                b_odd[i]=a[i];
                b_even[i]=1;
            }else{
                b_odd[i]=1;
                b_even[i]=a[i];
            }
        }
        if(is_valid(a,b_even,n,acc)){
            for(int i=0;i<n;i++){
                cout<<b_even[i]<<' ';
            }
            cout<<endl;
        }else{
            for(int i=0;i<n;i++){
                cout<<b_odd[i]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}