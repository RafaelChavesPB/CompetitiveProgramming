#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        vector<long long> diff;
        long long ant = 0;
        for(auto &it: arr)
            cin>>it;
        sort(arr.begin(),arr.end());
        for(auto it: arr){
            diff.push_back(abs(it-ant));
            ant = it;
        }
        long long acc = 0;
        for(auto it:arr){
            acc-=it;
        }
        long long ans = arr.back();
        for(int i=0;i<n;i++){
            acc+=diff[i]*(n-i);
            ans+=acc;
        }
        cout<<ans<<endl;

    }
    return 0;
}