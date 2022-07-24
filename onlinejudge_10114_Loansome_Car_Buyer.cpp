#include <bits/stdc++.h>
#define pid pair<int,double>
#define mes first
#define taxa second

using namespace std;


int main(){
    bool aux;
    int meses_de_pagamento, meses_totais, n_taxas;
    double valor_de_emprestimo, valor_do_carro, entrada;
    vector<pid> depreciacao;
    vector<double> taxas;
    pid temp;

    while(cin>>meses_totais>>entrada>>valor_de_emprestimo>>n_taxas&&meses_totais>=0){
        
        for(int i=0;i<n_taxas;i++){
            cin>>temp.mes>>temp.taxa;
            depreciacao.push_back(temp);
        }
        depreciacao.push_back(pid(meses_totais+1,0));
        for(int i=0,m=0; i<n_taxas; i++){
            while(m<depreciacao[i+1].mes){
                m++;
                taxas.push_back(depreciacao[i].taxa);
            }
        }

        int i=0;
        double parcela=valor_de_emprestimo/meses_totais;
        valor_do_carro=(valor_de_emprestimo+entrada)*(1-taxas[i]);

        while(valor_de_emprestimo>valor_do_carro&&i<=meses_totais){
            i++;
            valor_de_emprestimo-=parcela;
            valor_do_carro=(valor_do_carro)*(1-taxas[i]);  
        }

        taxas.clear();
        depreciacao.clear();
                   
    cout<<i<<(i!=1?" months\n":" month\n");   

    }
}