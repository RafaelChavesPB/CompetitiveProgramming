#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m=-15000000,a,ans=-15000000;
        cin>>n;
        while(n--){
            cin>>a;
            ans = max(m-a,ans);
            m = max(a,m);
        }
        cout<<ans<<endl;
    }
}