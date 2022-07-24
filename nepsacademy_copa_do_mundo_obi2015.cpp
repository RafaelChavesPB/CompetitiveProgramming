#include <bits/stdc++.h>

using namespace std;


int main(){
    queue<char> fila;
    char time1,time2;
    int a,b;
    for(int i=0;i<16;i++){
        fila.push('A'+i);
    }
    for(int i=0;i<15;i++){
        time1=fila.front();
        fila.pop();
        time2=fila.front();
        fila.pop();
        cin>>a>>b;
        if(a>b)
            fila.push(time1);
        else
            fila.push(time2);
    }

    cout<<fila.front()<<endl;


    return  0;
}