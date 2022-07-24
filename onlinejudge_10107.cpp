#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    vector<int> v;
    while(cin>>a){
        v.insert(lower_bound(v.begin(),v.end(),a),a);
        int p=v.size()/2;
        if(v.size()%2){
            cout<<v[p]<<endl;
        }else{
            cout<<(v[p]+v[p-1])/2<<endl;
        }
    }
    return 0;
}