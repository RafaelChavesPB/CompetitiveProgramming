#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define tl pair<ll,pl>
using namespace std;
vector<vector<pl>> adj;
priority_queue<tl> pq;
ll total;

int dfs(int p, int v){
    int qft=0;
    if(adj[v].size()==1 and adj[v].front().first==p)
        return 1;
    for(auto i : adj[v]){
        if(i.first!=p){
            int qf = dfs(v,i.first);
            ll diff = qf * (i.second - i.second/2);
            qft += qf;
            total += qf * i.second;
            pq.push(tl(diff, pl(qf, i.second/2)));
        }
    }
    return qft;
}

int minMoves(ll s){
    int moves=0;
    while(total>s){
        pl desc = pq.top().second;
        ll diff = desc.first*(desc.second-desc.second/2);
        desc.second/=2;
        total -= pq.top().first;
        pq.pop();
        pq.push(tl(diff,desc));
        moves++;
    }
    return moves;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        ll s;
        cin>>n>>s;
        adj.assign(n+1,vector<pl>());
        pq = priority_queue<tl>();
        total=0;
        for(int i=0;i<n-1;i++){
            int a,b,p;
            cin>>a>>b>>p;
            adj[a].push_back(pl(b,p));
            adj[b].push_back(pl(a,p));
        }
        dfs(1,1);
        cout<<minMoves(s)<<endl;
    }
}
