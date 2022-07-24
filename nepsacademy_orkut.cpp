#include <bits/stdc++.h>

using namespace std;

map<string,vector<string>> adj;
map<string,int> grau;
vector<string> lista_sequencial;

void topological_sort(){
    queue<string> fila;
    for (auto x : adj)
        for (auto v : x.second)
            grau[v]++;

    for (auto p:grau)
            if (p.second==0)
                    fila.push(p.first);

    while (!fila.empty())
    {
            auto atual = fila.front();
            lista_sequencial.push_back(atual);
            fila.pop();

            for(auto v: adj[atual]){
                    if((--grau[v])==0)
                            fila.push(v);
            }
    }

}


int main(){
    int n,t,cont=1;
    string pai,temp,filho;
    while(cin>>n,n){
        adj.clear();
        grau.clear();
        lista_sequencial.clear();
        for(int i=0;i<n;i++){
            cin>>temp;
            grau[temp]=0;
        }
        for(int i=0;i<n;i++){
            cin>>filho>>t;
            while(t--){
                cin>>pai;
                adj[pai].push_back(filho);
            }
        }
        topological_sort();
        cout<<"Teste "<<cont++<<endl;
        if(lista_sequencial.size()==adj.size()){
            for(auto x: lista_sequencial){
                cout<<x<<' ';
            }
        }else{
            cout<<"impossivel";
        }
        cout<<endl<<endl;
    }




    return 0;
}