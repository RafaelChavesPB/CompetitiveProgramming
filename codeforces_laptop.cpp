#include <bits/stdc++.h>

using namespace std; 

int main(){
    int n,a,b;
    bool ans=false;
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(a!=b){
            
            ans=true;
        }
    }
    if(ans){
        cout<<"Happy Alex"<<endl;
    }else{
        cout<<"Poor Alex"<<endl;
    }
    return 0;
}
