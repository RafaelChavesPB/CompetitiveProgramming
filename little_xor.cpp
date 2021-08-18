#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans = 0;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        int value = 0;
        for(int j=i;j<n;j++){
            value^=v[j];
            ans = max(value,ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}