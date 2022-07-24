#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dislike,like;
vector<int> vis,cc;
set<int> ln;

void dfs(int v){
    int qtd=0;
    vis[v]=0;
    cc.push_back(v);
    for(int x: dislike[v]){
        ln.insert(x);
    }
    for(int x: like[v]){
        if(vis[x]){
            dfs(x);
        }
    }
}

int main(){
    int m,n,k,a,b;
    cin>>n>>k;
    dislike.resize(n+1);
    like.resize(n+1);
    vis.assign(n+1,1);
    while(k--){
        cin>>a>>b;
        like[a].push_back(b);
        like[b].push_back(a);
    }
    cin>>m;
    while(m--){
        cin>>a>>b;
        dislike[a].push_back(b);
        dislike[b].push_back(a); 
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            cc.clear();
            ln.clear();
            bool valido=true;
            dfs(i);
            for(auto x: cc){
                if(ln.find(x)!=ln.end()){
                    valido=false;
                }
            }
            if(valido){
                ans=max(ans,(int)cc.size());
            }
        }
    }
    cout<<ans<<endl;
}