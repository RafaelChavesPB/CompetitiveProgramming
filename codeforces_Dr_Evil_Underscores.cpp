#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll func(vector<ll> &v, int bit){
    if(bit<0 || v.empty()) return 0;

    int temp;
    vector<ll> h,l;
    for(auto i: v){
        temp=i>>(bit);
        temp%=2;
        if(temp){
            h.push_back(i);
        }else{
            l.push_back(i);
        }
    }

    if(h.empty()) return func(l,bit-1);
    if(l.empty()) return func(h,bit-1);

    return min(func(l,bit-1),func(h,bit-1))+(1<<bit);
}

int main(){ 
    ll n,temp;
    vector<ll> v;
 
    cin>>n;
    v.resize(n);
    for(auto &i: v){
        cin>>i;
    }
    cout<<func(v,30)<<endl;
    return 0;
}