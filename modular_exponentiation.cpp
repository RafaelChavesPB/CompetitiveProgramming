#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, m, x=1;
    cin>>n>>m;
    while(n-- and x<=m){
        x*=2;
    }
    cout<<m%x<<endl;
    return 0;
}