#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[3],b[3];
    int t;
    cin>>t;
    while(t--){
        int ans=0;
        for(int i=0;i<3;i++){
            cin>>a[i];
        }
        for(int i=0;i<3;i++){
            cin>>b[i];
        }
        int temp=min(a[2],b[1]);;
        ans=2*temp;
        a[2]-=temp;
        a[1]-=temp;
        b[2]=max(b[2]-a[2]-a[0],0);
        ans-=2*b[2];
        cout<<ans<<endl;
    }
    return 0;
}