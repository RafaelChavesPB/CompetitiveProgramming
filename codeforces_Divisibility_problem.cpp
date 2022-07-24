#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,a,b,ans;

    cin>>n;

    while(n--){
        cin>>a>>b;
        if(a%b==0){
            cout<<0<<endl;
        }else{

        cout<<b-(a%b)<<endl;
        }
    }

    return 0;
}