#include <bits/stdc++.h>

using namespace std;

int l,timer;
vector<vector<pair<int,long long>>> adj;
vector<long long> dist;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p, long long d)
{
    tin[v] = ++timer;
    dist[v]=d;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (auto u : adj[v]) {
        if (u.first != p)
            dfs(u.first, v, u.second + d);
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
    dfs(root, root,0);
}

int main(){
    int qtd, a,b,c,q;
    long long d;

    while(scanf("%d",&qtd), qtd){
        dist=vector<long long>(qtd,0);
        adj=vector<vector<pair<int,long long>>>(qtd);
        for(int i=1; i<qtd;i++){
            scanf("%d%lld",&a,&d);
            adj[a].push_back(make_pair(i,d));
            adj[i].push_back(make_pair(a,d));
        }
        preprocess(0,qtd);
        cin>>q;
        while(q--){
            scanf("%d%d",&a,&b);
            c=lca(a,b);
            printf("%lld ",dist[a]+dist[b]-2*dist[c]);
        }
        printf("\n");
    }
   
}
