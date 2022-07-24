#include <bits/stdc++.h>
using namespace std;
int main(){
    int cont=1;
    string s;
    while(cin>>s, s!="*"){
        cout<<"Case "<<cont++<<": ";
        if(s=="Umrah"){
            cout<<"Hajj-e-Asghar"<<endl;
        }else{
            cout<<"Hajj-e-Akbar"<<endl;
        }
    }
    return 0;
}