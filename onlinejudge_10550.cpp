#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    while(cin>>a>>b>>c>>d, a or b or c or d){
        int ans=1080;
        int temp;
        temp = a-b;
        if(temp<0)
            temp+=40; 
        ans+=(temp)*9;
        temp = c-b;
        if(temp<0)
            temp+=40; 
        ans+=(temp)*9;
        temp = c-d;
        if(temp<0)
            temp+=40; 
        ans+=(temp)*9;
        cout<<ans<<endl;
    }
    return 0;
}