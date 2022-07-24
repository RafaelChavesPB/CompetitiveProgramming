#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,a,b,q,p;
        string name;
        vector<pair<pair<int,int>,string>> lista;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>name>>a>>b;
            lista.push_back({{a,b},name});
        }
        cin>>q;
        while(q--){
            vector<string> ans;
            cin>>p;
            for(auto x:lista){
                if(x.first.first<=p and p<=x.first.second)
                    ans.push_back(x.second);
            }
            if(ans.size()>1 or ans.size()==0){
                cout<<"UNDETERMINED"<<endl;
            }else{
                cout<<ans.front()<<endl;
            }
        }
        if(t)
            cout<<endl;
    }
}