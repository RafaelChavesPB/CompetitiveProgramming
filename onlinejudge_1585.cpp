#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int ans=0;
        int acc=0;
        for(auto c : s){
            if(c=='O'){
                acc++;
                ans+=acc;
            }
            else{
                acc=0;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}