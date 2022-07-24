#include <bits/stdc++.h>

using namespace std;

int main(){
    string entrada;
    int n, op, ini, fin, pos;
    char c;
    cin>>entrada;
    cin>>n;
    while(n--){
        cin>>op;
        if(op==1){
            cin>>pos>>c;
            entrada[pos-1]=c;
        }else{
            cin>>ini>>fin;
            set<char> temp(entrada.begin()+ini-1,entrada.begin()+fin);
            cout<<temp.size()<<endl;
        }
    }
    return 0;
}