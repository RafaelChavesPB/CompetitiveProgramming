#include <bits/stdc++.h>
#define  ps pair<string,string>
#define  psi pair<ps,int> 
#define s second
#define f first
using namespace std;

map<ps,set<ps>> adj;
map<ps,int> lista;
ps root("Erdos","P.");

void bfs(){
    psi atual;
    queue<psi> fila;
    fila.push(psi(root,0));
    lista[root]=0;
    while(!fila.empty()){
        atual=fila.front();
        fila.pop();
        for(auto viz: adj[atual.first]){
            if(lista[viz]==-1){
                lista[viz]=atual.s+1;
                fila.push(psi(viz,atual.s+1));
            }
        }
    }
}

int main()
{
    int n,cont=1;
    
    while (cin >> n, n)
    {
        adj.clear();
        lista.clear();
        cin.ignore();
        while (n--)
        {
            vector<ps> autores;
            string a, b;
            getline(cin, a);
            istringstream ss(a);
            while (ss >> a)
            {
                ss >> b;
                b.pop_back();
                autores.push_back(ps(b,a));
                lista[ps(b,a)]=-1;
            }
            for(int i=0;i<autores.size();i++){
                for(int j=i+1; j<autores.size(); j++){
                    adj[autores[i]].insert(autores[j]);
                    adj[autores[j]].insert(autores[i]);
                }
            }
        }
        bfs();
        cout<<"Teste "<<cont++<<endl;
        for(auto x: lista){
            if(x.f!=root){
                cout<<x.f.s<<' '<<x.f.f<<": ";
                if(x.s==-1){
                    cout<<"infinito"<<endl;
                }else{
                    cout<<x.s<<endl;
                }
            }
        }
        cout<<endl;
    }

    return 0;
}