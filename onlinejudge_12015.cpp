#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,relev,caso=1;
    string url;
    cin>>t;
    while(t--){
        cout<<"Case #"<<caso++<<":"<<endl;
        int best=0;
        vector<pair<string,int>> lista;
        for(int i=0;i<10;i++){
            cin>>url>>relev;
            lista.push_back({url,relev});
            best=max(best,relev);
        }
        for(auto p:lista){
            if(p.second==best){
                cout<<p.first<<endl;
            }
        }
    }
    return 0;
}