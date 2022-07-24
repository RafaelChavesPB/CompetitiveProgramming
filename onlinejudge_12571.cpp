#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q,a;
        cin>>n>>q;
        vector<int> v(256);
        while(n--){
            cin>>a;
            v[a&255]=1;
        }
        while(q--){
            int ans=0;
            cin>>a;
            for(int i=0;i<256;i++){
                if(v[i])
                    ans=max(ans,a&i);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}