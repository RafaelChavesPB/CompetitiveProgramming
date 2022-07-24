#include <bits/stdc++.h>
#define vi vector<int>
#define mvi map<int,vi>

using namespace std;

mvi adj;
int n;

bool cc(int r){
    vi visitado(7,1);
    stack<int> pilha;
    pilha.push(r);
    while(!pilha.empty()){
        auto v=pilha.top();
        pilha.pop();
        visitado[v]=0;
        for(auto viz:adj[v]){
            if(visitado[viz]){
                pilha.push(viz);
            }
        }
    }

    for(auto v:adj){
        if(visitado[v.first]){
            return false;
        }
    }
    return true;
}

int main(){
    int a,b,cont=1;
    while(cin>>n,n){
        int impar=0;
        adj.clear();
        for(int i=0;i<n;i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout<<"Teste "<<cont++<<endl;
        if(cc(a)){
            for(auto v: adj){
                impar+=(v.second.size()%2);
            }
            if(impar==0 or impar==2){
                cout<<"sim"<<endl;
            }else{
                cout<<"nao"<<endl;
            }
        }else{
            cout<<"nao"<<endl;
        }
        cout<<endl;
    }

    return 0;
}