#include <bits/stdc++.h>

using namespace std;

int main(){
    int x1,x2,y1,y2,n,a,b, cont=1;
    pair<int,int> sd, ie, pos;
    while(cin>>x1>>y1>>x2>>y2,x1 and y1 and x2 and y2){
        int qtd=0;
        cin>>n;
        while(n--){
            cin>>a>>b;
            if(a>=x1 and a<=x2 and b<=y1 and b>=y2){
                qtd++;
            }
        }

        cout<<"Teste "<<cont++<<endl;
        cout<<qtd<<endl;
        cout<<endl;
    }


    return 0;
}