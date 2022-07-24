#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int rec(int pos, bitset<100> bm){
    if(pos==v.size()){
        long long pd=1, sm=0;
        for(int i=0;i<v.size();i++){
            if(bm[i]){
                sm+=v[i];
            }else{
                pd*=v[i];
            }
        }
        if(sm==pd)
            return sm;
        return 0;
    }
    long long a = rec(pos+1,bm);
    bm[pos]=1;
    long long b = rec(pos+1,bm);
    return max(a,b);
}
int main(){
    int t;
    cin>>t;
    for(int T=1;T<=t;T++){
        int m,n,p;
        v.clear();
        cin>>m;
        while(m--){
            cin>>p>>n;
            while(n--){
                v.push_back(p);
            }
        }
        cout<<"Case #"<<T<<": "<<rec(0,bitset<100>())<<endl;
    }
    return 0;
}