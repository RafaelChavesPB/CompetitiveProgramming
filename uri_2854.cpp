#include <bits/stdc++.h>

using namespace std;

map<string,vector<string>> lista_adjacentes;
map<string,bool> visitado;

int DFS(string pessoa);

int main (){
    int qpessoas,qrelacoes,qfamilias=0, qvisitadas=0;
    string p1,rtemp,p2;
    cin>>qpessoas>>qrelacoes;
    for(int i=0;i<qrelacoes;i++){
        cin>>p1>>rtemp>>p2;
        lista_adjacentes[p1].push_back(p2);
        lista_adjacentes[p2].push_back(p1);
        visitado[p1]=false;
        visitado[p2]=false;
    }    

    while(qvisitadas!=qpessoas){
        for(auto& p: visitado){
            if(!p.second){
                qvisitadas+=DFS(p.first);
                break;
            }      
        }
        qfamilias++;
    }
    cout<<qfamilias<<"\n";

}

int DFS(string pessoa){
    int soma=0;
    visitado[pessoa]=true;
    for(auto& parente: lista_adjacentes[pessoa]){
        if(!visitado[parente]){
            soma+=DFS(parente);
        }
    }
    return soma +1 ;
}