#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,n,cont,i;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<4){
            cout<<-1<<endl;
            continue;
        }
        
        for(i=2;i<=n;i+=2)
            cout<<i<<' ';
        i-=5;
        cout<<i<<' ';
        if(n%2){
            i+=4;
            cout<<i<<' ';
            i-=2;
            cout<<i<<' ';
            i-=4;
        }else{
            i+=2;
            cout<<i<<' ';
            i-=4;
        }
        for(;i>=1;i-=2)
            cout<<i<<' ';
        
        cout<<endl;
    }


    return 0;
}