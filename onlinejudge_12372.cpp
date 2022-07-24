#include <bits/stdc++.h>
using namespace std;
int main(){
    int cont=1,t,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        cout<<"Case "<<cont++<<": ";
        if(a>20 or b>20 or c>20)
            cout<<"bad";
        else
            cout<<"good";
        cout<<endl;
    }
    return 0;
}