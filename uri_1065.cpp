#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int temp;
    int q=0;

    for(int i=0; i<5; i++){
        cin>>temp;
        if(temp%2==0){
            q++;
        }
    }

    cout<<q<<" valores pares\n";
}