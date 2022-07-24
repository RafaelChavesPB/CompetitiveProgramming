#include <bits/stdc++.h>

using namespace std;

int main (){
    double num;
    cin>>num;
    if(num<0||num>100){
        cout<<"Fora de intervalo\n";
    } else if(num<=25){
        cout<<"Intervalo [0,25]\n";
    } else if(num<=50){
        cout<<"Intervalo (25,50]\n";
    } else if(num<=75){
        cout<<"Intervalo (50,75]\n";
    } else {
        cout<<"Intervalo (75,100]\n";
    }
    return 0;
}