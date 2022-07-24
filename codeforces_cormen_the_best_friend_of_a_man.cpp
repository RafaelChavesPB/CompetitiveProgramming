#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,acc=0;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i){
            int value = max(0,k-v[i]-v[i-1]);
            v[i] += value;
            acc += value;
        }
    }
    cout<<acc<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}