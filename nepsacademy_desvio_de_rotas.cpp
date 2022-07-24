#include <bits/stdc++.h>
#define pi pair<int,int>
#define vpi vector<pi> 
#define inf 0x3f3f3f3f

using namespace std;

vector<vpi> lista(255,vpi());
bool visitado[255];
int dist[255];

void dijkstra(int ori, int dest){
    dist[ori]=0;
    priority_queue<pi,vpi,greater<pi>> fila;
    fila.push(pi(0,ori));
    while(true){
        int encont=-1;
        while(!fila.empty()){
            int atual=fila.top().second;
            fila.pop();
            if(!visitado[atual]){
                encont=atual;
                break;
            }
        }
        if(encont==-1){
            break;
        }
        visitado[encont]=true;
        
        if(encont<dest)
            for(auto x: lista[encont]){
                int d=x.first;
                int viz=x.second;
                if(dist[viz]>dist[encont]+d and viz==encont+1){
                    dist[viz]=dist[encont]+d;
                    fila.push(pi(dist[viz],viz));
                }
            }
        else
            for(auto x: lista[encont]){
                int d=x.first;
                int viz=x.second;
                if(dist[viz]>dist[encont]+d){
                    dist[viz]=dist[encont]+d;
                    fila.push(pi(dist[viz],viz));
                }
            }
    }

}
int main(){
    int n,m,c,k;
    int ini, fin, pes;
    while(cin>>n>>m>>c>>k, n and m and c and k){
        lista=vector<vpi>(255,vpi());
        memset(visitado,0,sizeof(visitado));
        memset(dist,0x3f,sizeof(dist));
        while(m--){
            cin>>ini>>fin>>pes;
            lista[ini].push_back(pi(pes,fin));
            lista[fin].push_back(pi(pes, ini));

        }
        dijkstra(k,c-1);
        cout<<dist[c-1]<<endl;
    }
    return 0;
}