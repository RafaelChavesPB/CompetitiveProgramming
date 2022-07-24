#include <bits/stdc++.h>


using namespace std;

int main(){

    int x,z, soma=0, count=1;

    scanf("%d",&x);
    while(scanf("%d",&z)&&z<=x);
    
    soma+=x;
    count++;
    x++;
    do{
        
        soma+=x;
        x++;
    }while(soma<=z&&count++);
    printf("%d\n", count);

    return 0;
}