#include <bits/stdc++.h>

using namespace std;

int main(){
    map<int,int> l,p;
    int a,b,n,m;
    cin>>n>>m;
    while(n--){
        cin>>a>>b;
        l[a]=b;
    } 
    while(m--){
        cin>>a>>b;
        if(l[a]<b){
            l[a]=b;
            p[a]=b;
        }
    }

    for(auto i: p){
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;
}