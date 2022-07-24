#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,temp, dif=INT_MAX;
    vector<int> v;
    cin>>n>>m;
    while(m--){
        v.push_back(0);
        cin>>v.back();
    }
    sort(v.begin(),v.end());
    for(int i=0;i<=v.size()-n;i++)
        dif=min(v[i+n-1]-v[i],dif);
    cout<<dif<<endl;
    return 0;
}