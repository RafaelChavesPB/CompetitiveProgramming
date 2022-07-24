#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n,n){
        string s;
        int maior=0,ans=0;
        vector<int> v;
        while(n--){
            cin>>s;
            int count=0;
            if(count=s.size(), s.size()!=25){    
                cin>>s;
                count+=s.size();
            }
            maior=max(maior,count);
            v.push_back(count);
        }
        for(auto x:v){
            ans+=maior-x;
        }
        cout<<ans<<endl;
    }
    return 0;
}