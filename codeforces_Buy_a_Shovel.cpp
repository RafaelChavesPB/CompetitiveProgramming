#include <bits/stdc++.h>

using namespace std;

int main(){
    long price, ans=1,k;
    cin>>price>>k;
    while(ans*price%10!=0 and ans*price%10!=k){
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}