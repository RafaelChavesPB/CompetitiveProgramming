#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b,ans="NO";
    cin>>a>>b;
    if(a.size()==b.size()){
        if(a==b or (a.size()!=1 and a!=string(a.size(),'0') and b!=string(b.size(),'0'))){
            ans="YES";
        }
    }
    cout<<ans<<endl;
    return 0;
}