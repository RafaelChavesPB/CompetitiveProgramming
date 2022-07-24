#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    int a=1,n,ans=0;
    for(int i=1;a<=50000;i++){
        a*=i;
        v.push_back(a);
    }
    cin>>n;
    while(n){
        auto it = upper_bound(v.begin(),v.end(),n)-v.begin();
        n-=v[it-1];
        ans++;
    }
    cout<<ans<<endl;


}