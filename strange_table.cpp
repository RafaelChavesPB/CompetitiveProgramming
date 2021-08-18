#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long  n,m,x,i,j;
        cin>>n>>m>>x;
        i = (x-1)%n;
        j = (x-1)/n;
        cout<<i*m + 1 + j<<endl;
    }
    return 0;
}