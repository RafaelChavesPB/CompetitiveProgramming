#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> lista,v;
    int n,ans=0;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]==i){
            ans++;
        }else{
            lista.push_back(i);
        }
    } 
    if(lista.size()){
        ans++;
        for(auto i:lista){
            if(v[v[i]]==i){
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}