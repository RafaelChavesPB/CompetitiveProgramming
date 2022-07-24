#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b, ans=0;;
    vector<int> freq(24*60+1);
    cin>>n;
    while(n--){
        cin>>a>>b;
        ans=max(ans,++freq[a*60+b]);
    }
    cout<<ans<<endl;
    return 0;
}
s