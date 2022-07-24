#include <bits/stdc++.h>

using namespace std;

int main(){
    int alcool=0,gasolina=0,diesel=0,temp;
    while(cin>>temp&&temp!=4){
        switch(temp){
            case 1: alcool++;
                break;
            case 2:gasolina++;
                break;
            case 3: diesel++;
                break;
        }
    }        
    cout<<"MUITO OBRIGADO\n"<<"Alcool: "<<alcool<<"\n";
    cout<<"Gasolina: "<<gasolina<<"\nDiesel: "<<diesel<<"\n";
    return 0;
}
