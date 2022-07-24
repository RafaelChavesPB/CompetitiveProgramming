#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    string s;
    while(cin>>n>>m){
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>s;
            bool flag=false;
            for(auto c:s){
                if(!flag){
                    if(c!='.'){
                        flag=true;
                        ans++;
                    }
                }else{
                    if(c=='.'){
                        ans++;
                    }else{
                        flag=false;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}