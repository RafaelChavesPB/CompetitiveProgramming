#include <bits/stdc++.h>
using namespace std;

vector<int> dias;
int m[1010][1010];
int funcao(int despesa){
    int maior=0;
    for(int i=0;i<dias.size();i++){
        m[i][i]=dias[i]-despesa;
        maior=max(m[i][i],maior);
    }
        
    for(int length=1;length<=dias.size();length++){
        for(int start=0;start<dias.size()-length;start++){
            int end=start+length;
            m[end][start]=m[start][start]+m[end][start+1];
            maior=max(m[end][start],maior);
        }
    }

    return maior;
}



int main(){
    int n, despesa, temp;
    while(scanf("%d",&n)!=EOF){
        scanf("%d",&despesa);
        while(n--){
            scanf("%d",&temp);
            dias.push_back(temp);
        }
        printf("%d\n",funcao(despesa));
        dias.clear();
    }
    return 0;
}