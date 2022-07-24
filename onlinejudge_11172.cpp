#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,t;
    char c;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a<b)
            c='<';
        else if(a>b)
            c='>';
        else 
            c='=';
        cout<<c<<endl;
    }
    return 0;
}