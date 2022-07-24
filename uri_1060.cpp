#include <iostream>

using namespace std;

int main(){

    float temp;
    int qp=0;

    for(int i=0; i<6; i++){
        cin>>temp;
        if(temp>0)
            qp++;
    }

    cout<<qp<<" valores positivos\n";

    return 0;
}