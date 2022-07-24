#include <bits/stdc++.h>

using namespace std;

vector<int> pai,peso, qtd;

int find(int a){
    if(pai[a]==a){
        return a;
    }

    return pai[a]=find(pai[a]);
}

void join(int a,int b){


    a=find(a);
    b=find(b);
    if(a==b){
        return;
    }

    if(peso[a]<peso[b]){
        pai[a]=b;
        qtd[b]+=qtd[a];
    }

    if(peso[a]>peso[b]){
        pai[b]=a;
        qtd[a]+=qtd[b];
    }

    if(peso[a]==peso[b]){
        pai[a]=b;
        peso[b]++;
        qtd[b]+=qtd[a];
    }
}

void pre_process(int n){
    qtd=peso=pai=vector<int>(n+1,0);
    for(int i=1;i<=n;i++){
        pai[i]=i;
    }
}
int main(){
    int n,m,a,b;
    string op;
    cin>>n>>m;
    pre_process(n);
    while(m--){
        cin>>op>>a>>b;
        if(op=="F"){
            join(a,b);
        }else{
            if(find(a)==find(b))
                cout<<'S'<<endl;
            else 
                cout<<'N'<<endl;
        }
    }

    return 0; 
}