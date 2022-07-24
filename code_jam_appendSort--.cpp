#include <bits/stdc++.h>
using namespace std;
pair<int,int> rec(int a, int x, int cont){
    if(x>a){
        return {cont,x};
    }
    pair<int,int> r = {INT_MAX,INT_MAX};
    for(int i=0;i<10;i++){
        r = min(rec(a,x*10+i,cont+1),r); 
    }
    return r;
}
int main(){
    int t;
    cin>>t;
    for(int T=1;T<=t;T++){
        int n;
        cin>>n;
        vector<int> v(n);
        for(auto &it: v)
            cin>>it;
        int ans=0;
        int ant=v[0];
        for(int i=1;i<n;i++){
            pair<int,int> r = rec(ant,v[i],0);
            ans+=r.first;
            ant=r.second;
        }
        cout<<"Case #"<<T<<": "<<ans<<endl;
    }
    return 0;
}