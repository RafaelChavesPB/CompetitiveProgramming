#include <bits/stdc++.h>
using namespace std;
vector<int> sequence,answer,visited,cc;
void dfs(int v){
    cc.push_back(v);
    visited[v]=1;
    if(!visited[sequence[v]])
        dfs(sequence[v]);
}
int main(){
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        sequence.resize(n+1);
        answer.assign(n+1,0);
        visited.assign(n+1,0);
        for(int i=1;i<=n;i++)
            cin>>sequence[i];
        for(int i=1;i<=n;i++){
            cc.clear();
           if(!visited[i]){
               dfs(i);
               for(auto v:cc){
                   answer[v]=cc.size();
               }
           } 
        }
        for(int i=1;i<=n;i++){
            cout<< answer[i] << ' ';
        }
        cout<<endl;
    }
    return 0;
}