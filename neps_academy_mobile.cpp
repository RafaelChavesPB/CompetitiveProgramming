#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> pecas;


bool verificar(int v, int p){
    bool first=true;
    int qtd=0;
    for(auto i: adj[v])
        if(i!=p){
            if(!verificar(i,v)){
                return false;
            }if(first){
                qtd=pecas[i];
                first=false;
            }else if(qtd!=pecas[i]){
                return false;
            }
        } 
    return true;
}

int dfs(int v, int p){
    pecas[v]=1;
    for(auto i: adj[v]){
        if(i!=p){
            pecas[v]+=dfs(i,v);
        }
    }
    return pecas[v];
}


int main(){
    int n,a,b;
    cin>>n;
    adj=vector<vector<int>>(n+1);
    pecas=vector<int>(n+1);
    for(int i=0;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,0);
    cout<<(verificar(0,0)?"bem":"mal")<<endl;

    return 0;
}