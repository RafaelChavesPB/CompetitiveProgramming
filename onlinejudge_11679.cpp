#include <bits/stdc++.h>
using namespace std;
int main(){
    int b,n;
    while(cin>>b>>n, b and n){
        ios::sync_with_stdio(false);
        int x,y,value;
        vector<int> banks(b+1,0);
        for(int i=1;i<=b;i++){
            cin>>banks[i];
        }
        while(n--){
            cin>>x>>y>>value;
            banks[x]-=value;
            banks[y]+=value;
        }
        string ans="S";
        for(auto c:banks){
            if(c<0)
                ans="N";
        }
        cout<<ans<<endl;
    }
}