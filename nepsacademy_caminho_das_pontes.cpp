#include <bits/stdc++.h>
#define pi pair<int,int>
#define ind second
#define pes first
#define inf 0x3f3f3f3f 

using namespace std;

vector<pi> lista[1005];
bool vis[1005];
int dist[1005];


void dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    dist[0]=0;
    priority_queue<pi,vector<pi>,greater<pi>> fila;
    fila.push(pi(dist[0],0));
    while(true){
        int encontrado=-1;

        while(!fila.empty()){
            int atual=fila.top().ind;
            fila.pop();
            if(!vis[atual]){
                encontrado=atual;
                break;
            }
        }
        if(encontrado==-1){
            break;
        }
        vis[encontrado]=true;
        for(auto x: lista[encontrado]){
            int d=x.pes;
            int viz=x.ind;
            if(dist[viz]>dist[encontrado]+d){
                dist[viz]=dist[encontrado]+d;
                fila.push(pi(dist[viz],viz));
            }
        }
    }
}

int main(){
    int n, m, ini, fim, peso;
    cin>>n>>m;
    while(m--){
        cin>>ini>>fim>>peso;
        lista[ini].push_back(pi(peso, fim));
        lista[fim].push_back(pi(peso, ini));
    }   
    dijkstra();
    cout<<dist[n+1]<<endl;
    return 0;
}