#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,cont=1;
    cin>>t;
    while(t--){
        int n,a,ans=0;
        cin>>n;
        while(n--){
            cin>>a;
            ans=max(a,ans);
        }
        cout<<"Case "<<cont++<<": ";
        cout<<ans<<endl;
    }
}