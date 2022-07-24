#include <bits/stdc++.h>

using namespace std;

int main(){
    bool alice,beto,clara;

    while(cin>>alice>>beto>>clara){

        if(alice==beto&& beto==clara)
            cout<<'*';
        else if(clara==beto)
            cout<<'A';
        else if(clara==alice)
            cout<<'B';
        else if(alice==beto)
            cout<<'C';

        cout<<'\n';
    }
    return 0;
}