#include <bits/stdc++.h>

using namespace std;

int main(){

    list<long> tela;
    map<long,bool> numeros;
    long temp;
    int n,k;
    scanf("%d %d",&n,&k);
    while(n--){
        scanf("%ld",&temp);
        if(!numeros[temp]){
            tela.push_front(temp);
            numeros[temp]=true;
            if(tela.size()>k){
                numeros[tela.back()]=false;
                tela.pop_back();
            }
        }
    }
    printf("%ld ",tela.size());
    for(auto x: tela){
        printf("%ld ",x);
    }
    printf("\n");
    return 0;
}