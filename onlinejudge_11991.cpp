#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a,b;
    while(cin>>n>>m){
        map<int,vector<int>> mp;
        for(int i=1;i<=n;i++){
            cin>>a;
            mp[a].push_back(i);
        }
        while(m--){
            cin>>a>>b;
            if(mp[b].size()<a)
                cout<<0<<endl;
            else 
                cout<<mp[b][a-1]<<endl;
        }
    }
}