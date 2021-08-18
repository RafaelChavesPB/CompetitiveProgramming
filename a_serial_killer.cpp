#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    cout<<a<<' '<<b<<endl;
    int n;
    cin>>n;
    while(n--){
        string x,y;
        cin>>x>>y;
        if(x == a){
            a = y;
        }else{
            b = y;
        }
        cout<< a << ' ' <<b<<endl; 
    }
    return 0;
}