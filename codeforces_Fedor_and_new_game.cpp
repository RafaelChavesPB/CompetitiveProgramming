#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,k,amigos=0;
    unsigned a;
    vector<unsigned int> v;
    cin>>n>>m>>k;
    while(m--){
        cin>>a;
        v.push_back(a);
    }
    cin>>a;
    for(auto x: v){
        auto dif=__builtin_popcount(a^x);
        if(dif<=k){
            amigos++;
        }
    }

    cout<<amigos<<endl;


    return 0;
}