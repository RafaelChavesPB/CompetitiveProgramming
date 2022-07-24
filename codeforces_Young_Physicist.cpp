#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n, a=0,b=0,c=0,x,y,z;
    cin>>n;
    while(n--){
        cin>>x>>y>>z;
        a+=x;
        b+=y;
        c+=z;
    }
    if(a or b or c){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }

    return 0;
}