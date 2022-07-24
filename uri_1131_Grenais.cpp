#include <bits/stdc++.h>

using namespace std;

int main(){
    int jogos=0,vInt=0,vGre=0,empates=0,gInt,gGre, verify;
    do{
        scanf("%d %d",&gInt,&gGre);
        if(gInt>gGre){
            vInt++;
        }else if(gInt<gGre){
            vGre++;
        }else{
            empates++;
        }
        jogos++;
        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d",&verify);
    }while(verify!=2);

    printf("%d grenais\n",jogos);
    printf("Inter:%d\nGremio:%d\nEmpates:%d\n",vInt,vGre,empates);
    if(vInt>vGre){
        printf("Inter venceu mais\n");
    }else if(vInt<vGre){
        printf("Gremio venceu mais\n");
    } else {
        printf("Não houve vencedor\n");
    }
    return 0;
}