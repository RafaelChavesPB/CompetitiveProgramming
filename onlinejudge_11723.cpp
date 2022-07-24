#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,n,ans,cont=1;
    while(cin>>r>>n, r and n){
        r-=n;
        if(r>0){
            ans = (r/n) + (r%n!=0);
        }else{
            ans=0;
        }
        cout<<"Case "<<cont++<<": ";
        if(ans<=26){
            cout<<ans<<endl;
        }else{
            cout<<"impossible"<<endl;
        }
    }
    return 0;
}