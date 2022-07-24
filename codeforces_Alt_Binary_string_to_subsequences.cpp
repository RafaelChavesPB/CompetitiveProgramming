#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        string s;
        cin>>n>>s;
        vector<int> ans(n);
        stack<int> stk[2];
        int groups=0;
        for(int i=0;i<n;i++){
            int type=s[i]-'0';
            if(stk[!type].empty()){
                ans[i]=++groups;
                stk[type].push(groups);
            }else{
                ans[i]=stk[!type].top();
                stk[type].push(ans[i]);
                stk[!type].pop();
            }
        }
        cout<<groups<<endl;
        for(auto i : ans){
            cout<<i<<' ';
        }
        cout<<endl;
    }

}