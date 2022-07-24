#include <iostream>

struct horario
{
    int hora;
    int minuto;
};

using namespace std;

int main(){

    horario inicio, fim;

    int horaj;
    int minutoj;

    cin>>inicio.hora>>inicio.minuto>>fim.hora>>fim.minuto;

    horaj=fim.hora-inicio.hora;
    minutoj=fim.minuto-inicio.minuto;

    if(minutoj<0){
        minutoj+=60; 
        horaj--;
    }
    if(horaj==0&&minutoj==0||horaj<0){
        horaj+=24;
    }

    cout<<"O JOGO DUROU "<<horaj<<" HORA(S) E "<<minutoj<<" MINUTO(S)"<<endl;
              
    
}