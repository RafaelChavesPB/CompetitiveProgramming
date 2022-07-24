#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout<<fixed<<setprecision(2);
    double inicial, acrescimo, v[5]={.15,.12,.10,.07,.04}, percentual;
    
    cin>>inicial;

    if(inicial<=400){
        acrescimo=inicial*v[0];
        percentual=v[0]*100;

    } else if(inicial<=800){
        acrescimo=inicial*v[1];
        percentual=v[1]*100;
    } else if(inicial<=1200){
        acrescimo=inicial*v[2];
        percentual=v[2]*100;
    } else if(inicial<=2000){
        acrescimo=inicial*v[3];
        percentual=v[3]*100;
    } else {
        acrescimo=inicial*v[4];
        percentual=v[4]*100;
    }

    cout<<"Novo salario: "<<inicial+acrescimo<<"\n";
    cout<<"Reajuste ganho: "<<acrescimo<<"\n";
    cout<<fixed<<setprecision(0)<<"Em percentual: "<<percentual<<" %\n";
    return 0;
}