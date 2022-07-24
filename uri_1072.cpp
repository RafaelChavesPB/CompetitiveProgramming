#include <iostream>

using namespace std;

int main(){
    int n, temp, qout=0, qin=0;

    cin>>n;

    while(n--){
        cin>>temp;
        if(temp<=20&&temp>=10){
            qin++;
        } else{
            qout++;
        }
    }

    cout<<qin<<" in\n";
    cout<<qout<<" out\n";
    return 0;
}