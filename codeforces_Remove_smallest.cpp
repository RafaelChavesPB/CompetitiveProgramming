#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n, temp;
    cin>>t;
    while(t--){
        vector<int> v;
        string ans="YES";
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>temp;
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++){
            if(v[i+1]-v[i]>1){
                ans="NO";
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}