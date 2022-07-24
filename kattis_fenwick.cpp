#include <bits/stdc++.h>
using namespace std;

vector<long long> bit;
int n;

long long sum(int index) {
    long long soma = 0;
    while (index >= 1) {
        soma += bit[index];
        index -= index&-index;
    }
    return soma;
}

void update(int index, int dif) {
    while (index <= n){
        bit[index] += dif;
        index += index&-index;
    }
}

int main(){
    int m;
    long long a,b;
    char op;
    ios::sync_with_stdio(false);
    scanf("%d%d",&n,&m);

    bit=vector<long long> (n+1,0);
    while(m--){
        do{
            op=getchar();
        }while(op=='\n');
        if(op=='+'){
            scanf("%lld%lld",&a,&b);
            update(a+1,b);
        }else{
            scanf("%lld",&a);
            printf("%lld\n",sum(a));
        }
    }
}