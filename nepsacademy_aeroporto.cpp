#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,v, ini, fim,caso=0;
    while(cin>>a>>v, a and v){
        int maximo=0;
        int fluxo[101]={0};
        while(v--){
            cin>>ini>>fim;
            fluxo[ini]++;
            fluxo[fim]++;
            maximo=max(maximo,max(fluxo[ini],fluxo[fim]));
        }
        cout<<"Teste "<<++caso<<endl;
        for(int i=1;i<=a;i++){
            if(fluxo[i]==maximo){
                cout<<i<<' ';
            }
        }
        cout<<endl<<endl;
    }
}