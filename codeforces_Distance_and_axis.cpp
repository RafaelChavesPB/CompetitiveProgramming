#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,a,k,diff;
    cin>>t;
    while(t--){
        int ans=0;
        cin>>a>>k;
        diff=k-a;
        if(diff>0){
            ans=diff;
        }else if(diff<0 and diff%2){
            ans=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}