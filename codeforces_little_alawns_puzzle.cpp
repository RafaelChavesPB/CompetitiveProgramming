#include <bits/stdc++.h>
#define N (7+(long long)1e+9)
using namespace std;

vector<int> groups;
vector<int> v;
vector<vector<int>> adj; 
void dfs(int i, int g){
    groups[i]=g;
    for(auto it: adj[i])
        if(groups[it]==-1)
            dfs(it,g);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,num;
        cin>>n;
        v.resize(n);
        groups.assign(n,-1);
        adj.assign(n,vector<int>());
        for(int i=0;i<n;i++){
            cin>>num;
            v[i] = num-1;
        }
        for(int i=0;i<n;i++){
            cin>>num;
            adj[v[i]].push_back(num-1);
            adj[num-1].push_back(v[i]);
        }
        int count = 0;
        long long ans = 1; 
        for(int i = 0;i<n;i++){
            if(groups[i]==-1){
                dfs(i,count);
                count++;
                ans = (ans*2) % N;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}