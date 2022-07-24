#include <bits/stdc++.h>
#define pi pair<int,int>
#define ppi pair<int,pi>
#define impar 1
#define par 0
using namespace std;
vector<vector<pi>> adj;
vector<int> vis[2];
vector<int> dist[2];

void dijkstra(){	
    dist[par][1]=0;
    priority_queue<ppi,vector<ppi>,greater<ppi>> fila;
    fila.push({dist[par][1], {par,1}});
    while(true){
        int encontrado=-1;
        int paridade;
        while(!fila.empty()){
            auto atual=fila.top().second;
            fila.pop();
            if(!vis[atual.first][atual.second]){
                encontrado=atual.second;
                paridade=atual.first;
                break;
            }
        }
        if(encontrado==-1)
            break;
        vis[paridade][encontrado]=true;
        for(auto x: adj[encontrado]){
            int d=x.second;
            int viz=x.first;
            if(dist[!paridade][viz]>dist[paridade][encontrado]+d){
                dist[!paridade][viz]=dist[paridade][encontrado]+d;
                fila.push({dist[!paridade][viz],{!paridade,viz}});
            }
        }
    }
}


int main(){
    int n,m,a,b,c;
    cin>>n>>m;
    adj.assign(n+1,vector<pi>());
    vis[0]=vis[1]=vector<int>(n+1,0);
    dist[0]=dist[1]=vector<int>(n+1,12345678);
    while(m--){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dijkstra();
    cout<<(dist[par][n]!=12345678?dist[par][n]:-1)<<endl;
    return 0;
}