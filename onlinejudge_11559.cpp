#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,h,b,w,p,d;
    while(cin>>n>>b>>h>>w){
        int ans=INT_MAX;
        for(int i=0;i<h;i++){
            cin>>p;
            for(int j=0;j<w;j++){
                cin>>d;
                if(d>=n){
                    ans=min(ans,p*n);
                }
            }
        }
        if(ans<=b){
            cout<<ans<<endl;
        }else{
            cout<<"stay home"<<endl;
        }
    }
    return 0;
}