#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> paises;
vector<pair<int,int>> gov;

void dfs(int v, int governante){
    paises[v] = governante;
    gov[governante].first += 1;
    for(auto it:adj[v]){
        if(paises[it]==-1){
            dfs(it,governante);
        }
    }
}

int main(){
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    adj.assign(n,vector<int>());
    paises.assign(n,-1);
    gov.assign(n,{0,-1});
    for(int i=0;i<k;i++){
        int a;
        cin>>a;
        gov[a-1].second=a-1;
    }
    for(int i=0;i<m;i++){
        int a;
        int b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for(int i=0;i<n;i++){
        if(gov[i].second!=-1)
            dfs(i,i);
    }
    int apatridas = 0;
    for(auto it: paises){
        if(it==-1)
            apatridas++;
    }
    pair<int,int> best = {-1,-1};
    for(int i=0;i<n;i++){
        best=max(gov[i],best);
    }
    gov[best.second].first+=apatridas;
    for(auto it: gov){
        ans += ((it.first-1)*it.first)/2;
    }
    cout<<ans-m<<endl;
    return 0;
}