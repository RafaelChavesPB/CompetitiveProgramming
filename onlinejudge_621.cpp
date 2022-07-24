#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        n=s.size()-1;
        if(s[0]=='9' and s[n]=='4')
            cout<<'*'<<endl;
        else if(s[n-1]=='3' and s[n]=='5')
            cout<<'-'<<endl;
        else if(s[0]=='1' and s[1]=='9' and s[2]=='0')
            cout<<'?'<<endl;
        else
            cout<<'+'<<endl;
    }
    return 0;
}