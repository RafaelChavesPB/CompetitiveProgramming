#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, a, b; 
    long long ans = 0;
    cin >> n >> m;
    vector<set<int>> adj(n + 1);
    vector<int> energy(n + 1);
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++){
        cin >> energy[i];
        pq.push(make_pair(energy[i], i));
    }
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    while(!pq.empty()){
        auto atual=pq.top();
        pq.pop();
        for(auto x : adj[atual.second]){
            adj[x].erase(atual.second);
            ans += energy[x];
        }
    }
    cout<<ans<<endl;

    return 0;
}