#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int qPoints[20]={9};
    int qSquare[20]={5};
    int it_max;
    cin>>it_max;

    for(int it=1;it<it_max;it++){
        qSquare[it]=2*qSquare[it-1]+2*(qSquare[it-1]-pow(2,it));
        qPoints[it]=qSquare[it]+qPoints[it-1];
    }

    cout<<qPoints[it_max-1]<<endl;

    return 0;

}
