#include <iostream>
#define ll long long

using namespace std;

int verifica(int numero){
    int qdigitos=1;
    ll seq_1=1;
    do{
        while(seq_1<numero)
        {
            qdigitos++;
            (seq_1*=10)++;
        }
        seq_1%=numero;
    }while(seq_1);


    return qdigitos;
}
int main(){
    int num;

    while(cin>>num){
        cout<<verifica(num)<<"\n";
    }
    
    return 0;
}