#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,cont=1;
    cin>>t;
    while(t--){
        int n,m=0,j=0,a;
        cin>>n;
        while(n--){
            cin>>a;
            m+=(1+a/30)*10;
            j+=(1+a/60)*15;
        }
        cout<<"Case "<<cont++<<": ";
        if(m<j){
            cout<<"Mile "<<m<<endl;
        }else if(m>j){
            cout<<"Juice "<<j<<endl;
        }else{
            cout<<"Mile "<<"Juice "<<j<<endl;
        }
    }
    return 0;
}