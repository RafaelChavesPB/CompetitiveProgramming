#include <bits/stdc++.h>
#define  debug(x) cout<<(x)<<endl
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int a,b;
        vector<int> v(n,0);
        cin>>a;
        for(int i=1;i<n;i++){
            cin>>b;
            if(abs(a-b)<n)
                v[abs(a-b)]=1;
            a=b;
        }
        string ans="Jolly";
        for(int i=1;i<n;i++){
            if(!v[i]){
                ans="Not jolly";
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}