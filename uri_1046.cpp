#include <iostream>

using namespace std;

int main(){

    int inicio, fim;
    cin>> inicio >> fim;

    if(inicio>=fim)
        fim+=24;

    cout<<"O JOGO DUROU "<<fim-inicio<<" HORA(S)"<<endl;
}