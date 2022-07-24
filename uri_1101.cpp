#include <bits/stdc++.h>

using namespace std;

int main(){

    int m,n, sum;

    while(cin>>m>>n&&m>0&&n>0){
        sum=0;
        for(int i=min(m,n);i<=max(m,n);i++){
            cout<<i<<" ";
            sum+=i;
        }
        cout<<"Sum="<<sum<<"\n";
    }
    return 0;
}