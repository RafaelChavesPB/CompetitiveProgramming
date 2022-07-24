#include <iostream>

using namespace std;

int main(){

    int a,b, soma=0;

    cin>>a>>b;

    for(int i=min(a,b)+1;i<max(a,b);i++){
        if(i%2){
            soma+=i;
        }
    }

    cout<<soma<<"\n";
    return 0;
}