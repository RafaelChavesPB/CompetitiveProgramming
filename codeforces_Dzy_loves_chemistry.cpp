#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> vis;

int dfs(int v){
    int qtd=0;
    vis[v]=1;
    for(auto x: adj[v]){
        if(!vis[x])
            qtd += dfs(x);
    }
    return qtd+1;
}
int main(){
    int n,m,a,b;
    long long ans=1;
    cin>>n>>m;
    adj.resize(n+1);
    vis.assign(n+1,0);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans=ans<<(dfs(i)-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}