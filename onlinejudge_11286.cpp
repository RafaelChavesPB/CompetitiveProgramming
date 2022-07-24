#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n, n){
        map<vector<int>,int> m;
        int maior=0;
        while(n--){
            vector<int> temp;
            for(int i=0;i<5;i++){
                temp.push_back(0);
                cin>>temp.back();
            }
            sort(temp.begin(),temp.end());
            maior=max(++m[temp],maior);
        }
        int ans=0;
        for(auto x:m){
            if(x.second==maior)
                ans+=x.second;
        }
        cout<<ans<<endl;
    }
    return 0;
}