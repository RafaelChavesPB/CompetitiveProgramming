#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    int m;
    cin>>m;
    while(m--){
        int q;
        cin>>q;
        int ans = upper_bound(v.begin(),v.end(),q) - v.begin();
        cout<<ans<<endl;
    }
}