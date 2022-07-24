#include <iostream>
#include <iomanip>

using namespace std;

int main (){

    cout<<fixed<<setprecision(2);

    float money, taxe=0;
    cin>>money;
    
    if(money<=2000){
        cout<<"Isento\n";
    } else  if(money<=3000){
        taxe+=.08*(money-2000);
    } else  if(money<=4500){
        taxe+=(1000*.08)+(money-3000)*.18;
    } else {
        taxe+=(1000*.08)+(1500*.18)+(money-4500)*.28;
    }

    if(taxe)
        cout<<"R$ "<<taxe<<"\n";
    return 0;
}