#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    
    double n1,n2,n3,n4,media,nfinal,mediafinal;
    cout<<fixed<<setprecision(1);

    cin>>n1>>n2>>n3>>n4;

    media=(n1*2+n2*3+n3*4+n4)/10;
    cout<<"Media: "<<media<<"\n";
    
    if(media>=7){
        cout<<"Aluno aprovado.\n";
    } else if(media>=5){
        cout<<"Aluno em exame.\n";
        cin>>nfinal;
        cout<<"Nota do exame: "<<nfinal<<"\n";
        mediafinal=(media+nfinal)/2;
        
        if(mediafinal>=5)
            cout<<"Aluno aprovado.\n";
        else
            cout<<"Aluno reprovado.\n";
        
        cout<<"Media final: "<<mediafinal<<"\n";

    } else{
        cout<<"Aluno reprovado.\n";
    }
}