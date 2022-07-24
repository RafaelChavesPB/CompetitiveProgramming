#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long ans=0;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    sort(v.begin()+1,v.end());
    for(int i=1;i<=n;i++){
        ans+=abs(v[i]-i);
    }
    cout<<ans<<endl;

    return 0;
}