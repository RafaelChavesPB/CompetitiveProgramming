#include <iostream>
#define TAM 3

using namespace std;

void ordenar(double v[]){
    double temp;
    for(int i=0;i<TAM-1; i++){
        for(int j=0;j<TAM-1;j++){
            if(v[j]<v[j+1]){
                temp=v[j+1];
                v[j+1]=v[j];
                v[j]=temp;
            }
        }        
    }
}



int main(){
    double v[3];

    cin>>v[0]>>v[1]>>v[2];
    
    ordenar(v);    

    double a=v[0]*v[0];
    double b=v[1]*v[1];
    double c=v[2]*v[2];

    if(v[0]>=(v[1]+v[2])){
        cout<<"NAO FORMA TRIANGULO\n"; 
        return 0;
    }else if(a==(b+c)){
        cout<<"TRIANGULO RETANGULO\n";
    }else if(a>(b+c)){
        cout<<"TRIANGULO OBTUSANGULO\n";
    }else{
        cout<<"TRIANGULO ACUTANGULO\n";
    }

    if(a==b&&a==c){
        cout<<"TRIANGULO EQUILATERO\n";
    }else if(a==b||a==c||b==c){
        cout<<"TRIANGULO ISOSCELES\n";
    }
    return 0;
}