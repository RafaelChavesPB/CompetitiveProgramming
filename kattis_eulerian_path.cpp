#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int,int>

using namespace std;

vi grau;
vvi adj;
multiset<pi> arestas;
stack<int> path;
int n;

void euler_tour(int v){
    for(auto viz: adj[v]){
        auto ptr=arestas.find(pi(v,viz));
        if(ptr!=arestas.end()){
            arestas.erase(pi(v,viz));
            euler_tour(viz);
        }
    }
    path.push(v);
}

bool cc(){
    stack<int> pilha;
    vi visitado(n,1);
    pilha.push(0);
    while(!pilha.empty()){
        auto v=pilha.top();
        pilha.pop();
        visitado[v]=0;
        for(auto viz: adj[v]){
            if(visitado[viz]){
                pilha.push(viz);
            }
        }
    }

    for(auto i: visitado){
        if(i){
            return false;
        }
    }

    return true;
}

int main(){
    int m,a,b;
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m,n and m){
        vector<int> grau(n,0);
        adj=vector<vector<int>>(n);
        arestas.clear();
        while(m--){
            cin>>a>>b;
            adj[a].push_back(b);
            arestas.insert(make_pair(a,b));
            grau[a]--;
            grau[b]++;
        }
        int neg=0,pos=0,ind_n=-1,ind_p=-1;
        for(int i=0; i<n; i++){
            if(grau[i]<0){
                neg++;
                if(grau[i]==-1)
                    ind_n=i;
            }else if(grau[i]>0){
                pos++;
                if(grau[i]==1)
                    ind_p=i;
            }
        }
                
        auto comp=cc();
        if(comp and neg==0 and pos==0){
            euler_tour(0);
        }else if(comp and neg==1 and pos==1 and ind_n!=-1 and ind_p!=-1){
            euler_tour(ind_n);
        }else{
            cout<<"Impossible";
        }

        while(!path.empty()){
            cout<<path.top()<<' ';
            path.pop();
        }
        cout<<endl;
    }

    return 0;
}