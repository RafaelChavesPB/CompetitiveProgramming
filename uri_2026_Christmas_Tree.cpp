#include <bits/stdc++.h>
#define pi pair<int,int>
#define q first
#define p second 

using namespace std;

vector<pi> caixas; 


int calcula(int pos, int peso){
    int valor=0;
    if(peso==0||pos==caixas.size()){
        return 0;
    }
    if(peso>=caixas[pos].p){
        valor=calcula(pos+1,peso-caixas[pos].p)+caixas[pos].q;
    }
    return max(valor,calcula(pos+1,peso));
}

int main(){
    int cases, qtd_caixas, peso_max, n=1;
    pi temp;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d %d",&qtd_caixas,&peso_max);
        while(qtd_caixas--){
            scanf("%d %d",&temp.q, &temp.p);
            caixas.push_back(temp);
        }
        printf("Galho %d:\nNumero total de enfeites: %d\n\n",n++,calcula(0,peso_max));
        caixas.clear();
    }
    
}