#include <iostream>

using namespace std;

int main(){

    int temp, qpar=0, qimpar=0, qpos=0, qneg=0;
    for(int i=0;i<5;i++){
        cin>>temp;
        if(temp%2==0)
            qpar++;
        else 
            qimpar++;
        if(temp>0)
            qpos++;
        else if(temp!=0)
                qneg++;
    }
 cout<<qpar<<" valor(es) par(es)\n";
 cout<<qimpar<<" valor(es) impar(es)\n";
 cout<<qpos<<" valor(es) positivo(s)\n";
 cout<<qneg<<" valor(es) negativo(s)\n";
}