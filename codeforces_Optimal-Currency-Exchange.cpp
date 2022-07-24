#include <bits/stdc++.h>
#define INI_EU 7
#define TAM 13
using namespace std;

bool m[100000000];
int calcula(int n, int cot_dolar, int cot_euro){
    int valor=n;
    int notas[13]={1,2,5,10,20,50,100,5};
    for(int i=0;i<INI_EU;i++){
        notas[i]*=cot_dolar;
    }
    notas[INI_EU]*=cot_euro;
    

    m[n]=true;
    for(int i=n;i>=0;i--){
        if(m[i]){
            for(auto j: notas){
                if(j<=i){
                    m[i-j]=true;
                    valor=min(i-j,valor);
                }
            }
        }
    }
    return valor;
}

int main(){
    int n,cot_dol, cot_eu;
    scanf("%d %d %d",&n,&cot_dol,&cot_eu);

    printf("%d\n",calcula(n,cot_dol,cot_eu));
    return 0;
}