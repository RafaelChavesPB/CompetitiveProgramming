#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    string name;
    cin>>t;
    getline(cin,name);
    getline(cin,name);
    cout<<fixed<<setprecision(4);
    while(t--){
        int cont=0;
        map<string,int> m;
        while(getline(cin,name) and name.size()){
            cont++;
            if(name.back()=='\n' or name.back()=='\r')
                name.pop_back();
            m[name]++;
        }
        for(auto x:m){
            cout<<x.first<<' '<<(100.0*x.second)/cont<<endl;
        }
        if(t)
            cout<<endl;
    }
}