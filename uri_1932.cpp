#include <bits/stdc++.h>
#define debug(x) cout<<x<<endl
#define debug_(x,y) cout<<x<<' '<<y<<endl
using namespace std;
struct myHash {
        size_t operator()(pair<int,int> a) const noexcept{
            size_t h1=hash<int>{}(a.first);
            size_t h2=hash<int>{}(a.second);
            return h1^(h2<<1);
        }
};
unordered_map<pair<int,int>,int,myHash> dp;
vector<int> p;   
int c;
int rec(int i, int v){
    if(i==p.size())
        return 0;
    if(dp.find({i,v})!=dp.end()){
        return dp[{i,v}];
    }
    if(v==0){
        int a=rec(i+1,p[i]);
        int b=rec(i+1,0);
        return dp[{i,v}]=max(a,b);
    }
    int a=rec(i+1,v);
    int b=rec(i+1,0)+(p[i]-v)-c;
    return dp[{i,v}]=max(a,b);   
}
int main(){
    int n;
    cin>>n>>c;
    p.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    cout<<rec(0,0)<<endl;
    return 0;
}