#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, carlos, maximo=0, temp;
    scanf("%d %d",&n,&carlos);
    while(--n){
        scanf("%d",&temp);
        maximo=max(temp,maximo);
    }
    printf("%c\n",(carlos>=maximo?'S':'N'));
    return 0;
}