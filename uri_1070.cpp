#include <iostream>

using namespace std;

int main(){

    int num;
    cin>>num;

    num=(num%2?num:num+1);
    for(int i=0;i<12;i+=2){
        cout<<num+i<<"\n";
    }
    return 0;
}