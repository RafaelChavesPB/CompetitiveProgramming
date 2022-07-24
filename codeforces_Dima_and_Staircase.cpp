#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    long long w,h,ans,last=0;
    cin>>n;
    vector<long long> degraus(n+1);
    for(int i=1;i<=n;i++)
        cin>>degraus[i];
    cin>>m;
    while(m--){
        cin>>w>>h;
        ans=max(last,degraus[w]);
        last=ans+h;
        cout<<ans<<endl;
    }
    return 0;
}