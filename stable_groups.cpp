#include <bits/stdc++.h>
using namespace std;
int main(){
    long long unsigned n,k,x,groups=1;
    cin>>n>>k>>x;
    vector<long long> v(n);
    vector<long long> d;
    for(int i= 0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n-1;i++){
        long long diff = v[i+1]-v[i];
        if(diff>x)
            d.push_back(diff); 
    }
    sort(d.begin(),d.end());
    for(auto diff:d){
        long long div = diff/x;
        if(diff>div*x){
            if(k>=div){
                k-=div;
            }else{
                groups++;
            }
        }else{
            div--;
            if(k>=div){
                k-=div;
            }else{
                groups++;
            }
        }
    }
    cout<<groups<<endl;
    return 0;
}