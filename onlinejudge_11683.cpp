#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,l;
    while(cin>>h>>l,h and l){
        int ans=0;
        vector<int> formato(l+1);
        for(int i=0;i<l;i++){
            cin>>formato[i];
        }
        formato[l]=h;
        for(int i=1;i<=l;i++){
            if(formato[i]>formato[i-1])
                ans+=formato[i]-formato[i-1];
        }
        cout<<ans<<endl;
    }
}