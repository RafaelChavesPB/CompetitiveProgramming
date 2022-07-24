#include <bits/stdc++.h>

using namespace std;

long long m[1000][1000];
int s[1000][1000];
int dim[1010];

long long mcm(int qtd){
    int j, i, k, length,temp;
    bool flag=false;
    long long q=-100;
    for( i=0;i<qtd;i++)
        m[i][i]=0;
    
    for(length=2;length<=qtd;length++){
        for(int i=0;i<qtd-length+1;i++){
            j=i+length-1;
            m[i][j]=INT64_MAX;
            for(k=i;k<j;k++){
                temp=m[i][k]+m[k+1][j]+dim[i]*dim[k+1]*dim[j+1];
                if(temp<m[i][j]){
                    s[i][j]=k;
                    m[i][j]=temp;
                }else if(temp==m[i][j]){
                    q=m[i][j];
                }
            }
            if(q==m[i][j]){
                flag=true;
            }
        }
    }
    return flag;
}

string sequencia(int inicio, int final){
    string a="(";
    if(inicio==final)
        return "A"+to_string(inicio+1);
    if(final-inicio==1)
        return a+"A"+to_string(inicio+1)+"A"+to_string(final+1)+")";
    return a+sequencia(inicio,s[inicio][final])+sequencia(s[inicio][final]+1,final)+")";
}


int main(){
    int qtd;
    while(scanf("%d",&qtd)&&qtd){
    for(int i=0;i<qtd;i++){
        scanf("%d %d",&dim[i],&dim[i+1]);
    }
        if(mcm(qtd)){
            printf("%lld\n",m[0][qtd-1]);
        }else{
            printf("%s\n",sequencia(0,qtd-1).c_str());
        }
        memset(m,0,sizeof(m));
        memset(s,0,sizeof(s));
        memset(dim,0,sizeof(dim));
    }
   return 0;
}
