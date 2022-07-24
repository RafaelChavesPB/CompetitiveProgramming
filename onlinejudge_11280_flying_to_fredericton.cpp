#include <bits/stdc++.h>
#define pi pair<ll,ll>
#define ti pair<pi,ll>
#define ll long long
#define s second
#define f first

using namespace std;

vector<vector<ll>> bellman_ford( ll n, vector<ti> &arestas){
    vector<vector<ll>> dist(n+2,vector<ll>(n+2,INT_MAX));
    dist[0][0]=0;
    for(ll c=0;c<n;c++){
        for(auto x: arestas){
            for(ll i=1;i<=n+1;i++){
                auto ant=dist[x.f.s][i];
                auto abaixo=dist[x.f.s][i-1];
                auto novo_caminho=dist[x.f.f][i-1]+x.s;
                dist[x.f.s][i]=min(ant,min(abaixo,novo_caminho));
            }
        }
    }   
    return dist;
}
int main(){
    map<string,ll> id;
    vector<ti> arestas;
    string a,b;
    ll n,t,q,m,w,lim,cont=1;
    cin>>t;
    while(t--){
        cin>>n;
        arestas.clear();
        id.clear();
        
        for(ll i=0;i<n;i++){
            cin>>a;
            id[a]=i;
        }
        cin>>m;
        for(ll i=0;i<m;i++){
            cin>>a>>b>>w;
           arestas.push_back(ti(pi(id[a],id[b]),w));

        }
        cout<<"Scenario #"<<cont++<<endl;
        cin>>q;

        auto ans=bellman_ford(n,arestas);
        while(q--){
            cin>>lim;
            if(ans[n-1][min(lim+1,n)]>=INT_MAX){
                cout<<"No satisfactory flights"<<endl;
            }else{
                cout<<"Total cost of flight(s) is $"<<ans[n-1][min(lim+1,n)]<<endl;
            }
        }
        if(t)cout<<endl;
        
    }

}