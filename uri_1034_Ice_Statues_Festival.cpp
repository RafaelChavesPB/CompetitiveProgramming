#include <bits/stdc++.h>
#define TAM 1000000

using namespace std;

vector<int> v;

  
int calcula(int valor, int n){

    if(!valor%v[n-1])
        return valor/v[n-1];

    int m[valor+20];
    memset(m,TAM,sizeof(m));    
    m[0]=0;
    
    for(int i=1; i<=valor;i++){
        for(int j=0; j<n; j++){
            if(i-v[j]>=0){
                m[i]=min(m[i-v[j]]+1,m[i]);
            }
        }
    }

    return m[valor];
}

int main(){
    int cases,n,valor,temp;
    
    scanf("%d",&cases);
    
    while(cases--){
        
        scanf("%d %d",&n,&valor);
        
        while(n--){
            scanf("%d",&temp);
            v.push_back(temp);
        }

        sort(v.begin(), v.end());

        printf("%d\n",calcula(valor,v.size()));

        v.clear();
    }

    return 0;
}