#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, n, i, soma=0;

    scanf("%d",&a);
    while(scanf("%d",&n)&&n<=0);
    for(i=0;i<n;i++){
        soma+=a;
        a++;
    }
    printf("%d\n",soma);
    return 0;
}