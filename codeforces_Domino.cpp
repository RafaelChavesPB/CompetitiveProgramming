#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, up=0, lo=0,num_u,num_l, coringa=false;
    
    cin>>n;
    while(n--){
        cin>>num_u;
        up+=num_u;
        cin>>num_l;
        lo+=num_l;
        if((num_l+num_u)%2)
            coringa=true;
    }
    int a=up%2;
    int b=lo%2;
    if((a+b)%2 or (a and b and !coringa))
        cout<<-1<<endl;
    else if(!a and !b)
        cout<<0<<endl;
    else
        cout<<1<<endl;

}