#include <bits/stdc++.h>
#define pi pair<int,int> 
#define viz first
#define pes second

using namespace std;
vector<vector<pair<int,int>>> lista(250);
int visitado[255];
int dist[255];

int menorDist(int n){
   int pos=0, valor=INT_MAX;
   for(int i=0;i<n;i++){
       if(dist[i]<valor&& !visitado[i]){
           valor=dist[i];
           pos=i;
       }
   }
   return pos;
}

int dijkstra(int raiz, int final, int n){

    dist[raiz]=0;
    int u;
    for(int i=0; i<n-1;i++){
        u=menorDist(n);
        visitado[u]=true;
        if(u<final){
            for(auto vizinho: lista[u]){
                if(vizinho.viz==u+1&&vizinho.pes+dist[u]<dist[vizinho.viz] && !visitado[vizinho.viz]){
                    dist[vizinho.viz]=vizinho.pes+dist[u];
                    break;
                }
            }
        }else{
            for(auto vizinho: lista[u]){
                if(vizinho.pes+dist[u]<dist[vizinho.viz] && !visitado[vizinho.viz]){
                    dist[vizinho.viz]=vizinho.pes+dist[u];
                }
            }        
        }
    }

    return dist[final];
}


int main(){
    int n, m, c, k, u, v, peso;
    ios::sync_with_stdio(false);
    while(cin>>n>>m>>c>>k&&n!=0&&m!=0&&c!=0&&k!=0){
        for(int i=0;i<n;i++){
            visitado[i]=0;
            dist[i]=INT_MAX;
        }

        while(m--){
            cin>>u>>v>>peso;
            lista[u].push_back(pi(v,peso));
            lista[v].push_back(pi(u,peso));
        }
        cout<<dijkstra(k,c-1,n)<<"\n";
        for(int i=0;i<n;i++){
            lista[i].clear();
        }
    }


    return 0;
}