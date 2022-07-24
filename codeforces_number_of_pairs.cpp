#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,l,r,ans=0;
        cin>>n>>l>>r;
        long long v[n];
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v,v+n);
        for(int i=0;i<n;i++){
            if(v[i]>=r)
                continue;
            long long diff_min = l - v[i];
            long long diff_max = r - v[i];
            int start = lower_bound(v,v+n,diff_min) - v;
            int end = upper_bound(v,v+n,diff_max) - v; 
            ans+=end-start-(start<=i and i<end?1:0);
            // cout<<v[i]<<' '<<end-start-(start<=i and i<end?1:0)<<endl;
        }
        cout<<ans/2<<endl;
    }
    return 0;
}