#include <iostream>

using namespace std;

int main (){

    int value;
    int q_banknotes;
    int banknotes[]={ 100, 50, 20, 10, 5, 2 , 1};

    cin>>value;
    cout<<value<<endl;

    for(int i=0;i<7;i++){
        
        q_banknotes=value/banknotes[i];
        value%=banknotes[i];

        cout<<q_banknotes<<" nota(s) de R$ "<<banknotes[i]<<",00"<<endl;
    }
}