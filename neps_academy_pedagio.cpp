#include <bits/stdc++.h>
#define si set<int>
#define pi pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

int n; 
vvi adj;

void bfs(int i, int l){
    set<int> visitado;
    queue<pi> fila;
    fila.push(pi(i,l));  
    while(!fila.empty()){
        auto v = fila.front();
        fila.pop();
        visitado.insert(v.first);
        for(auto viz: adj[v.first]){
            if(v.second and visitado.find(viz)==visitado.end())
                fila.push(pi(viz,v.second-1));
        }
    }
    string ans;
    for(auto cid: visitado){
        if(cid!=i){
            ans+=to_string(cid)+' ';
        }
    }
    cout<<ans<<endl;
}
int main(){
    int m,a,b,inicio, p,cont=1;
    while(cin>>n>>m>>inicio>>p, n and m and inicio and p){
        adj=vvi(n+1);
        while(m--){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout<<"Teste "<<cont++<<endl;
        bfs(inicio,p);
        cout<<endl;
    }
    return  0;
}