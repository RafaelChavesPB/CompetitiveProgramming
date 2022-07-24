#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    int ans =0;
    for(int i=0;i<n;i++){
        int count = 1;
        int employe = i;
        while(v[employe]!=-1){
            employe = v[employe]-1 ;
            count++;
        }
        ans = max(ans,count);
    }
    cout<<ans<<endl;
}