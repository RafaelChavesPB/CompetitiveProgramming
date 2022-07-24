#include <bits/stdc++.h>

using namespace std;


int main(){
    int cases,n,x,y;
    cin>>cases;
    while(cases--){
        cin>>x>>y>>n;
        auto dif=((n%x)-y+x)%x;
        cout<<n-dif<<endl;
    }

    return 0;
}