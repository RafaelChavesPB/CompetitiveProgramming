#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> visitado;
int dfs(int v){
    int cont=1;
    visitado[v]=1;
    for(auto x:adj[v]){
        if(!visitado[x])
            cont+=dfs(x);
    }
    return cont;
}
int main(){
    int t,n,m,a,b;
    cin>>t;
    while(t--){
        cin>>n>>m;
        adj.assign(n+1,vector<int>());
        visitado.assign(n+1,0);
        while(m--){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!visitado[i])
                ans=max(ans,dfs(i));
        }
        cout<<ans<<endl;
    }
}