#include <bits/stdc++.h>

using namespace std;

int l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout, labels, nivel;
vector<pair<int,int>> pares;
vector<vector<int>> up;

void dfs(int v, int p, int nvl)
{
    nivel[v]=nvl;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v,nvl+1);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root,int n) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up=vector<vector<int>>(n+1, vector<int>(l + 1));
    dfs(root, root, 0);
}

int main(){
    long long a,b,c,n, ans=0;
    cin>>n;
    adj=vector<vector<int>>(n+1,vector<int>());
    nivel=labels=vector<int>(n+1);
    pares=vector<pair<int,int>>((n/2)+1,make_pair(-1,-1));
    for(int i=1;i<=n;i++){
        cin>>c;
        labels[i]=c;
        if(pares[c].first==-1){
            pares[c].first=i;
        }else{
            pares[c].second=i;
        }
    }
    for(int i=0;i<n-1; i++){
        cin>>a;
        cin>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    preprocess(1,n);
    for(auto x: pares){
        a=x.first;
        b=x.second;
        c=lca(a,b);
        ans+=nivel[a]+nivel[b]-2*nivel[c];
    }

    cout<<ans<<endl;
}
