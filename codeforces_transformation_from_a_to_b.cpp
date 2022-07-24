#include <bits/stdc++.h>
using namespace std;
vector<long long> rec(long long n,long long b){
    if(n>b)
        return {};
    if(n==b)
        return {n};
    vector<long long> r = rec(n*10+1,b);
    if(r.size()){
        r.push_back(n);
        return r;
    }
    r = rec(n*2, b);
    if(r.size())
        r.push_back(n);
    return r;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,b;
    cin>>a>>b;
    vector<long long> ans = rec(a,b);
    if(ans.size()){
        cout<<"YES"<<endl;
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto it: ans)
            cout<<it<<' ';
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}