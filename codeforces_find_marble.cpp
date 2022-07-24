#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,s,t,ans=-1;
    cin>>n>>s>>t;
    vector<int> shuf(n+1);
    for(int i=1;i<=n;i++)
        cin>>shuf[i];
    if(s==t){
        cout<<0<<endl;
    }else{
        for(int i=1;i<=n;i++){
            s=shuf[s];
            if(s==t){
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}