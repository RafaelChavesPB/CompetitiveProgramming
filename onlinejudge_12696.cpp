#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,acc=0;
    cin>>n;
    while(n--){
        long double a,b,c,d;
        cin>>a>>b>>c>>d;
        if((a<=56.001 and b<=45.001 and c<=25.001 or (a+b+c)<=125.001) and d<=7.001){
            acc++;
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }   
    cout<<acc<<endl;
}