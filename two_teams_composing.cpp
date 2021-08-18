#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>t;
    set<int> diff;
    map<int,int> eq;
    while(t--){
        diff.clear();
        eq.clear();
        int n,a;
        cin>>n;
        while(n--){
            cin>>a;
            diff.insert(a);
            eq[a]++;
        }
        int ans = 0;
        for(auto it:eq){
            if(it.second == diff.size()){
                ans = max(ans,it.second-1);
            }else{
                ans = max(min(it.second,(int)diff.size()),ans);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}