#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
set<int> st[2];
string s;

void solve(int group, int pos, int type){
    auto it=st[type].upper_bound(pos);
    if(it!=st[type].end()){
        ans[*it]=group;
        int aux=*it;
        st[type].erase(it);
        solve(group, aux, !type);
    }
    return;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n>>s;
        st[0].clear();
        st[1].clear();
        ans.assign(n,0);
        for(int i=0; i<n; i++){
            st[s[i]-'0'].insert(i);
        }
        int qtd=0;
        for(int i=0;i<n;i++){
            if(ans[i]==0){
                qtd+=1;
                solve(qtd,i-1,s[i]-'0');
            }
        }
        cout<<qtd<<endl;
        for(auto i : ans){
            cout<<i<<' ';
        }
        cout<<endl;
    }
    return 0;
}