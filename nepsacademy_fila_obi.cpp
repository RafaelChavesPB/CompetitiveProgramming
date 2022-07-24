#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,a;
    queue<int> fila;
    set<int> sairam;
    cin>>n;
    
    while(n--){
        cin>>a;
        fila.push(a);
    }
    
    cin>>m;
    
    while(m--){
        cin>>a;
        sairam.insert(a);
    }

    while(!fila.empty()){
        if(sairam.find(fila.front())==sairam.end()){
            cout<<fila.front()<<' ';
        }
        fila.pop();
    }
    cout<<endl;



}