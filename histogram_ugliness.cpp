#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n+2);
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }
        long long ans = 0; 
        for(int i=1;i<=n;i++){
            if(v[i]>v[i+1] and v[i]>v[i-1]){
                int alt = v[i]-max(v[i-1],v[i+1]);
                v[i] -= alt;
                ans+=alt;
            }
            ans+=abs(v[i]-v[i-1]);
        }
        ans+=v[n];
        cout<<ans<<endl;
    }

    return 0;
}