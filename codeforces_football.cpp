#include <bits/stdc++.h>
using namespace std;
int main(){
    bool flag = false;
    int a=0,b=0;
    string s;
    cin>>s;
    for(auto it:s){
        if(it=='1'){
            a=0;
            b++;
        }else{
            b=0;
            a++;
        }
        if(a>=7 or b>=7){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}