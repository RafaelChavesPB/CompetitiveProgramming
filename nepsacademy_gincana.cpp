#include <bits/stdc++.h>

using namespace std;

vector<int> lista[1001];
bool visitado[1001];

void dfs(int no){
    visitado[no]=true;
    for(auto x: lista[no]){
        if(!visitado[x]){
            dfs(x);
        }
    }
}

int main(){
    int n,m,ini,fim, ans=0;
    cin>>n>>m;
    while(m--){
        cin>>ini>>fim;
        lista[ini].push_back(fim);
        lista[fim].push_back(ini);
    }

    for(int i=1;i<=n;i++){
        if(!visitado[i]){
            dfs(i);
            ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}