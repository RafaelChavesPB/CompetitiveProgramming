#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    vector<int> v;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    sort(v.begin(),v.begin()+k+1,greater<int>());
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
    return 0;
}