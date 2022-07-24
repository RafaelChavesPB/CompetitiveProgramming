#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    double temp;
    double soma=0;
    int q=0;

    cout<<fixed<<setprecision(1);

    for(int i=0; i<6; i++){
        cin>>temp;
        if(temp>0){
            soma+=temp;
            q++;
        }
    }

    cout<<q<<" valores positivos\n";
    cout<<soma/q<<"\n";
}