#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> color_adj;
vector<vector<int>> color_cc;

void dfs(int c, int v,int cc){
    color_cc[c][v]=cc;
    for(auto x: color_adj[c][v]){
        if(!color_cc[c][x])
            dfs(c,x,cc);
    }
}

int main(){
    int n,m,a,b,c,q,u,v;
    cin>>n>>m;
    color_adj.assign(m+1,vector<vector<int>>(n+1));
    color_cc.assign(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        color_adj[c][a].push_back(b);
        color_adj[c][b].push_back(a);
    }
    for(int i=1;i<=m;i++){
        int cc=1;
        for(int j=1;j<=n;j++){
            if(!color_cc[i][j]){
                dfs(i,j,cc);
                cc++;
            }
        }
    }
    cin>>q;
    while(q--){
        cin>>u>>v;
        int ans=0;
        for(int i=1;i<=m;i++){
            ans+=(color_cc[i][v]==color_cc[i][u] and color_cc[i][u]);
        }
        cout<<ans<<endl;
    }
    return 0;
}