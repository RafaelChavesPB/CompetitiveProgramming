#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n,n){
        int a=0,b=0,cont=0;
        for(int i=0;i<32;i++){
            if(n&(1<<i)){
                cont++;
                if(cont%2)
                    a|=(1<<i);
                else
                    b|=(1<<i);
                
            }
        }
        cout<<a<<' '<<b<<endl;
        
    }
    return 0;
}
