#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        a-=2;
        b-=2;
        cout<<((a/3) + (a%3!=0))*((b/3) + (b%3!=0))<<endl;;
    }
    return 0;
}