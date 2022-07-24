#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,k,n1,n2;
    cin>>t;
    while(t--){
        cin>>n>>k;
        n1=n2=n;
        n1-=(k-1);
        n2-=2*(k-1);
        if(n1>0 and n1%2){
            cout<<"YES"<<endl;
            for(int i=1;i<k;i++){
                cout<<1<<' ';
            }
            cout<<n1<<endl;
            continue;
        }
        if(n2>0 and n2%2==0){
            cout<<"YES"<<endl;
            for(int i=1;i<k;i++){
                cout<<2<<' ';
            }
            cout<<n2<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}
