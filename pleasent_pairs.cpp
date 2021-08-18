#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int ans = 0;
        cin>>n;
        vector<pair<long long,int>> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i].first;
            arr[i].second = i+1;
        }
        sort(arr.begin(),arr.end());
        for(long long i=0;i<n;i++){
            for(long long j=i+1;(arr[i].first*arr[j].first<=2*n) and j < n;j++){
                if(arr[i].first*arr[j].first == arr[i].second + arr[j].second){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}