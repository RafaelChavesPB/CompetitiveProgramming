#include <bits/stdc++.h>
using namespace std;

set<int> disponiveis;
vector<set<int>> proibidos;
vector<pair<int,int>> ans;

void bfs(int raiz){
    disponiveis.erase(raiz);
    // queue<int> fila;
    // fila.push(raiz);
    // while(!fila.empty()){
    // auto atual = fila.front();
    // fila.pop();
    for(auto x : disponiveis){
        if(proibidos[raiz].find(x) == proibidos[raiz].end()){
            // fila.push(x);
            ans.push_back(make_pair(raiz,x));
            // disponiveis.erase(x);                
        }
    }
    // }
}
int main(){
    int n,m,a,b;
    cin>>n>>m;
    proibidos.resize(n+1);
    for(int i=1;i<=n;i++)
       disponiveis.insert(i); 
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        proibidos[a].insert(b);
        proibidos[b].insert(a);
    }
    auto raiz = make_pair(INT_MAX,0);
    for(int i=1;i<=n;i++)
        raiz = min(raiz, make_pair((int)proibidos[i].size(),i));
    bfs(raiz.second);
    cout<<ans.size()<<endl;
    for(auto x: ans)
        cout<<x.first<<' '<<x.second<<endl;
    return 0;
}