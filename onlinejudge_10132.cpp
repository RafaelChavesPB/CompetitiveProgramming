#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    string s;
    cin>>t;
    getline(cin,s);
    getline(cin,s);
    while(t--){
        vector<string> v;
        map<string,set<int>> m;
        while(getline(cin,s) and s.size()>1){
            s.pop_back();
            v.push_back(s);
            s.clear();
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                string temp = v[i]+v[j];
                if(j!=i and m[temp].find(i)==m[temp].end() and m[temp].find(j)==m[temp].end()){
                    m[temp].insert(i);
                    m[temp].insert(j);
                }
            }
        }
        pair<int,string> ans={0,""};
        for(auto x : m){
                ans=max(ans,{x.second.size(),x.first});
        }
        cout<<ans.second<<endl;
        if(t)
            cout<<endl;
    }
    return 0;
}