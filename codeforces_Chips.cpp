#include <bits/stdc++.h>

using namespace std;
int main(){
    int n,m,i=1;
    cin>>n>>m;
    while(m>=i){
        m-=i;
        i++;
        i%=n+1;
    }
    cout<<m<<endl;
    return 0;
}