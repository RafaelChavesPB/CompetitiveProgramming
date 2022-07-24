#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, maximo=0;
    map<string,int> mp;
    string team;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>team;
        mp[team]++;
    }
    for(auto x:mp){
        if(x.second>maximo){
            maximo=x.second;
            team=x.first;
        }
    }
    cout<<team<<endl;
    return 0;
}