#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<long long> s(n+1),psa(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>s[i];
        psa[i]=s[i]+psa[i-1];
    }
    pair<long long,int> ans(1e11,0);
    for(int i=0;i<=n-k;i++)
        ans=min(ans,{psa[i+k]-psa[i],i+1});
    cout<<ans.second<<endl;
    return 0;
}