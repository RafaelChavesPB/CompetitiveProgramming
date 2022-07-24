#include <bits/stdc++.h>

using namespace std;
 
int main(){
    int r,teste_case=0,n;
    cin>>n;
    while(n--){
        cin>>r;
        cout<<"Case "<<++teste_case<<":\n";
        cout<<fixed<<setprecision(0)<<-2.25*r<<" "<<1.5*r<<endl;
        cout<<fixed<<setprecision(0)<<2.75*r<<" "<<1.5*r<<endl;
        cout<<fixed<<setprecision(0)<<2.75*r<<" "<<-1.5*r<<endl;
        cout<<fixed<<setprecision(0)<<-2.25*r<<" "<<-1.5*r<<endl;
    }
}