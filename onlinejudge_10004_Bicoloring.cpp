#include <bits/stdc++.h>

using namespace std;

vector<int> cor;
vector<vector<int>> adj;

void bfs(int v){
    queue<int> fila;
    int atual;
    fila.push(v);

    while(!fila.empty()){
        atual=fila.front();
        fila.pop();
        for(auto i: adj[atual]){
            if(cor[i]==-1){
                cor[i]=1-cor[atual];
                fila.push(i);
            }
        }
    }
}

bool check(int n){
    for(int i=0; i<n; i++){
        for(auto j: adj[i]){
            if(cor[i]==cor[j])
                return false;
        }
    }

    return true;
}


int main(){

    int n,m,a,b;

    while(cin>>n,n){
        cin>>m;
        adj=vector<vector<int>> (n+1);
        cor=vector<int> (n+1,-1);

        for(int i=0;i<m;i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bfs(a);

        cout<<(check(n)?"BICOLORABLE.":"NOT BICOLORABLE.")<<endl;
        
    }

    return 0; 
}