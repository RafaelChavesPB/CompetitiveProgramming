#include <bits/stdc++.h>

using namespace std;

int main(){
    int p,w,m,ans=0;
    cin>>p>>w>>m;
    if(w*100<p*m){
        ans=(p*m)/100-w;
        if(p*m%100)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}