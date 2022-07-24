#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    int n;
    ll a, b;
    cin>>n;
    for(int i=1;i<=n;i++){
        a=i*i;
        b=a*i;
        cout<<i<<" "<<a<<" "<<b<<"\n"<<i<<" "<<a+1<<" "<<b+1<<"\n";
    }
    return 0;
}