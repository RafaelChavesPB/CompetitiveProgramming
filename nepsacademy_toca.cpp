#include <bits/stdc++.h>

using namespace std;

bool ingrid(int l, int c, int ql, int qc){
    if(l<0 or l==ql)
        return 0;
    if(c<0 or c==qc)
        return 0;
    return 1;
}


int mem[1001][1001];
int dl[]={1,0,-1,0};
int dc[]={0,1,0,-1};

int bfs(int l,int c, int  n, int m){
    queue<pair<pair<int,int>,int>> fila;
    pair<pair<int,int>,int> temp(make_pair(l,c),0);
    fila.push(temp);
    while(!fila.empty()){
        temp=fila.front();
        fila.pop();
        mem[temp.first.first][temp.first.second]=0;
        for(int k=0;k<4;k++){
            pair<int,int> vizinho=temp.first;
            vizinho.first+=dl[k];
            vizinho.second+=dc[k];
            if(ingrid(vizinho.first,vizinho.second,n,m)){
                if(mem[vizinho.first][vizinho.second]==1){
                    fila.push(make_pair(vizinho,temp.second+1));
                }else if(mem[vizinho.first][vizinho.second]==3){
                    return temp.second+1;
                }
            }
        }
    }
}

int main(){
     int n, m, l, c;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            cin>>mem[i][j];
            if(mem[i][j]==2){
                l=i;c=j;
            }
        }
    }
    cout<<bfs(l,c,n,m)+1<<endl;
    return 0;
}
