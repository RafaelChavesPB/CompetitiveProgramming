#include <bits/stdc++.h>

using namespace std;

int main(){
    long q,n, temp, soma;
    long media;
    cin>>q;
    while(q--){
        cin>>n;
        soma=0;
        for(int i=0; i<n;i++){
            cin>>temp;
            soma+=temp;
        }
        if(soma%n){
            media=(soma/n)+1;
        }else{
            media=soma/n;
        }
        cout<<media<<endl;
    }
    return 0;
}