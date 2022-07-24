#include <bits/stdc++.h>
#define pi pair<long long,long long>
#define f first
#define s second
using namespace std;

int main(){
    vector<pi> v;
    long long n,m, a=0, b=0,num;
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>num;
        v.push_back(pi(num,i));
    }
    sort(v.begin(),v.end());
    std::cin>>m;
    while(m--){
        std::cin>>num;
        pi par=*upper_bound(v.begin(),v.end(),pi(num,0));
        if(par.first==num){
            b+=v.size()-(par.second)+1;
            par=*lower_bound(v.begin(),v.end(),pi(num,0));
            a+=par.second;
        }else{
            a+=v.size();
            b+=v.size();
        }
    }
    cout<<a<<' '<<b<<endl;
    return 0;
}