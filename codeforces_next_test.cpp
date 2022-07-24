#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<bool> v(10e+5,true);
    int n,a;
    cin>>n;
    while(n--){
        cin>>a;
        v[a]=false;
    }
    for(int i=1;i<=v.size();i++){
        if(v[i]){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}