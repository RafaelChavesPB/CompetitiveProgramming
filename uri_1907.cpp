#include <bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second


using namespace std;

stack<ii>pilha;
int visitado[1024][1024];
int mi[]={-1,0,1,0};
int mj[]={0,1,0,-1};

bool inGrid(int i, int j, int imax, int jmax){
    if(i>imax||j>jmax||i<0||j<0)
        return false;
    return true;
}

void dfs(ii ponto, int qlinha, int qcoluna){
    ii vizinho;
    ii temp;
    pilha.push(ponto);
    while(!pilha.empty()){
        temp=pilha.top();
        pilha.pop();
        visitado[temp.f][temp.s]=1;
        for(int h=0;h<4;h++){
            vizinho.f=temp.f+mi[h];
            vizinho.s=temp.s+mj[h];
            if(inGrid(vizinho.f,vizinho.s, qlinha, qcoluna)&&(!visitado[vizinho.f][vizinho.s])){
                pilha.push(vizinho);
            }
        }
    }
}

int main(){


    ios::sync_with_stdio(false);
    int n,m, regiao=0, ui=0, uj=0;
    char temp;

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>temp;
            if(temp=='o'){
                visitado[i][j]=1;
            }
        }
    
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visitado[i][j]){
                dfs(ii(i,j),n,m);
                regiao++;
            }
        }
    }
    
    cout<<regiao<<"\n";
    return 0;

}

