#include <bits/stdc++.h>

using namespace std;


int main(){
    long long n, temp;
    vector<long long> v(6,0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp>0){
            if(temp>v[0]){
                v[2]=v[1];
                v[1]=v[0];
                v[0]=temp;
            }else if(temp>v[1]){
                v[2]=v[1];
                v[1]=temp;
            }else if(temp>v[2]){
                v[2]=temp;
            }
        }else{
            if(temp<v[3]){
                v[5]=v[4];
                v[4]=v[3];
                v[3]=temp;
            }else if(temp<v[4]){
                v[5]=v[4];
                v[4]=temp;
            }else if(temp<v[5]){
                v[5]=temp;
            }
        }
    }

    long long ans=-10e+15;
    for(int i=0; i<4; i++ ){
        for(int j=i+1; j<5;j++){
            for(int k=j+1;k<6;k++){
                ans=max(ans,v[i]*v[j]*v[k]);
            }
        }
    }
    cout<<ans<<endl;
    



}