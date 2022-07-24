#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n,m,t,entrada,time=0,side=0;
        string lado;
        queue<pair<int,int>> fila[2];
        cin>>n>>t>>m;
        vector<int> desembarque(m);
        for(int i=0;i<m;i++){
            cin>>entrada>>lado;
            if(lado=="left"){
                fila[0].push({entrada,i});
            }else{
                fila[1].push({entrada,i});
            }
        }
        fila[0].push({123456789,0});
        fila[1].push({123456789,0});
        while(fila[0].front().first!=123456789 or fila[1].front().first!=123456789){
           int cont=0;
           if(fila[side].front().first<=time){
               while(fila[side].front().first<=time and cont<n){
                   desembarque[fila[side].front().second]=time+t;
                   fila[side].pop();
                   cont++;
               }
           }else if(fila[!side].front().first<=time){
               side=!side;
               time+=t;
               while(fila[side].front().first<=time and cont<n){
                   desembarque[fila[side].front().second]=time+t;
                   fila[side].pop();
                   cont++;
               }
           }else if(fila[side].front()<=fila[!side].front()){
               time=fila[side].front().first;
               while(fila[side].front().first<=time and cont<n){
                   desembarque[fila[side].front().second]=time+t;
                   fila[side].pop();
                   cont++;
               }
           }else{
               side=!side;
               time=fila[side].front().first+t;
               while(fila[side].front().first<=time and cont<n){
                   desembarque[fila[side].front().second]=time+t;
                   fila[side].pop();
                   cont++;
               }
           }
           side=!side;
           time+=t;
        }
        if(k)
            cout<<endl;
        for(auto x:desembarque){
            cout<<x<<endl;
        }
    }
    return 0;
}