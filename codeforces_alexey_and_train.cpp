#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n+1,0);
        vector<int> b(n+1,0);
        vector<int> tt(n+1,0);
        vector<int> tn(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
            tn[i] = (b[i]-a[i])/2 +(b[i]-a[i])%2;
        }
        for(int i=0;i<n;i++){
            int tm;
            cin>>tm;
            tt[i] = a[i+1] - b[i] + tm;
        }
        int ans = tt[0];
        for(int i=1; i<n; i++){
            ans=max(b[i],ans+tn[i]);
            ans+=tt[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}