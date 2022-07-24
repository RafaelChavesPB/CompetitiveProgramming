#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> visitado; 

int dfs(int v){
    int cont=1;
    visitado[v]=1;
    for(auto x: adj[v]){
        if(!visitado[x])
            cont+=dfs(x);
    }
    return cont;
}
int main(){
    int n,m,k,a,b;
    while(cin>>n>>m, n or m){
        adj.assign(n,vector<int>());
        visitado.assign(n,0);
        while(m--){
            cin>>k;
            cin>>a;
            while(--k > 0){
                cin>>b;
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }
        cout<<dfs(0)<<endl;

    }
}