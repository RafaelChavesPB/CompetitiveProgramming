#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,ans=0;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &it: v)
        cin>>it;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        int a = lower_bound(v.begin(),v.end(),v[i]+1) - v.begin();
        int b = (upper_bound(v.begin(),v.end(),v[i]+k) - v.begin())-1;
        if(a>b){
            ans++;
        }
    }
    cout<<ans<<endl;
}