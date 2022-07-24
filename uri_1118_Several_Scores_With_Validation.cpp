#include <bits/stdc++.h>

using namespace std;

int main(){
    int verify, cont=0;
    double temp, total=0;

    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(2);
    do{
        cont=0;
        total=0;
        while(cont<2){
            cin>>temp;
            if(temp>=0&&temp<=10){
                total+=temp;
                cont++;
            }else{
                cout<<"nota invalida\n";
            }
        }
        cout<<"media = "<<total/2<<"\n";
        while(cout<<"novo calculo (1-sim 2-nao)\n"&&cin>>verify&&verify!=1&&verify!=2);
    }while(verify!=2);
    return 0;
}