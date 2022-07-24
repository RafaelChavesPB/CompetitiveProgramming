#include<bits/stdc++.h>

using namespace std;


int main(){
    int t,s,cont=1;
    vector<pair<int,int>> lista, intervalo;
    while(cin>>t>>s, t and s){
        lista.clear();
        intervalo.clear();
        while(s--){
            lista.push_back(pair<int,int>());
            cin>>lista.back().first>>lista.back().second;
        }

        sort(lista.begin(),lista.end());

        intervalo.push_back(make_pair(-1,-1));
        for(auto x: lista){
            if(intervalo.back().first==-1){
                intervalo.back()=x;
            }else{
                if(x.first<=intervalo.back().second){
                    intervalo.back().second=max(x.second,intervalo.back().second);
                }else{
                    intervalo.push_back(x);
                }
            }
        }
        cout<<"Teste "<<cont++<<endl;       
        for(auto x: intervalo){
            if(x.first<x.second)
                cout<<x.first<<' '<<x.second<<endl; 
        }
        cout<<endl;

    }

    return 0;
}