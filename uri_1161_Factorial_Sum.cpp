#include <bits/stdc++.h>

using namespace std;
unsigned long long fat(int n){
    long long ans=1;
    for(int i=2;i<=n;i++)
    {
        ans*=i;
    }
    return ans;
}
int main(){
    int m, n;
    while(cin>>n>>m){
        cout<<fat(n)+fat(m)<<"\n";
    }
    return 0;
}