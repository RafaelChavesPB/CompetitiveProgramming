#include <bits/stdc++.h>

using namespace std;

int main(){

    for(int i=1;i<=9;i+=2){
        for(int j=6+i;j>=4+i;j--){
            cout<<"I="<<i<<" J="<<j<<"\n";
        }
    }

    return 0;
}