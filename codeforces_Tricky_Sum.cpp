#include <bits/stdc++.h>

using namespace std;

int main(){
    long long t,n;
    long long soma,pot2=1;

    cin>>t;
    while(t--){
        cin>>n;
        pot2=1;
        soma=0;
        do{
            soma-=2*pot2;
            pot2*=2;
        }while(pot2<=n);
        soma+=((1+n)*n)/2;
        cout<<soma<<endl;
    }
}