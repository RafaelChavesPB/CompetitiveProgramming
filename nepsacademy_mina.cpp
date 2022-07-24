#include <bits/stdc++.h>
#define pi pair<int,int>
#define pii pair<int, pi>
#define d first
#define coord second
#define lin first
#define col second
#define inf 0x3f3f3f3f

using namespace std;

int mem[101][101];
int dist[101][101];
bool vis[101][101];

int dc[]={0,1,0,-1};
int dl[]={1,0,-1,0};

bool ingrid( pi p, int n){
    return p.lin>=0 and p.lin<n and p.col>=0 and p.col<n;
}

void dijkstra(pi r, int n){
    memset(dist,0x3f,sizeof(dist));
    dist[r.lin][r.col]=0;
    priority_queue<pii,vector<pii>,greater<pii>> fila;
    fila.push(pii(dist[r.lin][r.col], r));

    while(true){
        
        pi encontrado(-1,-1);

        while(!fila.empty()){
            pi atual=fila.top().coord;
            fila.pop();
            if(!vis[atual.lin][atual.col]){
                encontrado=atual;
                break;
            }
        }

        if(encontrado.lin<0) break;

        vis[encontrado.lin][encontrado.col]=true;
        for(int i=0; i<4;i++){
            pi atual=encontrado;
            atual.lin+=dl[i];
            atual.col+=dc[i];
            if(ingrid(atual,n)){
                if(dist[atual.lin][atual.col]>dist[encontrado.lin][encontrado.col]+mem[atual.lin][atual.col]){
                    dist[atual.lin][atual.col]=dist[encontrado.lin][encontrado.col]+mem[atual.lin][atual.col];
                    fila.push(pii(dist[atual.lin][atual.col],atual));
                }
            }
        }
    }
}


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mem[i][j];
        }
    }
    dijkstra(pi(0,0),n);
    cout<<dist[n-1][n-1]<<endl;

    return 0;
}