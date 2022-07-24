#include <bits/stdc++.h>
using namespace std;
map<int,int> dias;
vector<int> visit;
vector<vector<int>> adj;
void dfs(int v){
    queue<pair<int,int>> fila;
    fila.push({v,1});
    visit[v]=1;
    while(!fila.empty()){
        auto atual=fila.front();
        fila.pop();
        for(auto x: adj[atual.first]){
            if(!visit[x]){
                dias[atual.second]++;
                fila.push({x,atual.second+1});
                visit[x]=1;
            }
        }
    }
}
int main(){
int n,t,m,a,b;
    cin>>n;
    adj.assign(n,vector<int>());
    for(int i=0;i<n;i++){
        cin>>m;
        while(m--){
            cin>>a;
            adj[i].push_back(a);
        }
    }
    cin>>t;
    while(t--){
        pair<int,int> ans(0,0);
        dias.clear();
        visit.assign(n,0);
        cin>>b;
        dfs(b);
        for(auto x:dias){
            ans=max(pair<int,int>(x.second,-x.first),ans);
        }
        if(ans.first){
            cout<<ans.first<<' '<<-ans.second<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}