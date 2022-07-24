#include <bits/stdc++.h>

using namespace std;

int vetor[100010];
long long segtree[500040];

void build(int si, int sf, int pos){
    if(si==sf){
        segtree[pos]=vetor[si];
        return;
    }
    int sm=(si+sf)/2;
    build(si,sm,2*pos);
    build(sm+1,sf,2*pos+1);
    segtree[pos]=segtree[2*pos]*segtree[2*pos+1];
}

void update(int q, int valor, int si, int sf,int pos){
    if(si==sf){
        vetor[q]=valor;
        segtree[pos]=valor;
        return;
    }
    int sm=(si+sf)/2;
    if(q<=sm){
        update(q,valor,si,sm,2*pos);
    }else{
        update(q,valor,sm+1,sf,2*pos+1);
    }
    segtree[pos]=segtree[2*pos]*segtree[2*pos+1];
}

long long search(int qi,int qf, int si, int sf, int pos){
    if(qf<si or qi>sf){
        return 1;
    }
    if(qi<=si and qf>=sf){
        return segtree[pos];
    }
    int sm=(si+sf)/2;
    return search(qi,qf,si,sm,2*pos)*search(qi,qf,sm+1,sf,2*pos+1);
}

int value(int n){
    if(n>0)
        return 1;
    if(n<0)
        return -1;
    return 0;
}

int main(){
    int n,m,pos,num1,num2,temp;
    char op;
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            cin>>temp;
            vetor[i]=value(temp);
        }
        memset(segtree,1,sizeof(segtree));
        build(1,n,1);
        while(m--){
            cin>>op>>num1>>num2;
            if(op=='C'){
                num2=value(num2);
                update(num1,num2,1,n,1);
            }else if(op=='P'){
                long long result=search(num1,num2,1,n,1);
                if(result>0){
                    cout<<'+';
                }else if(result<0){
                    cout<<'-';
                }else{
                    cout<<'0';
                }
            }
        }
        cout<<'\n';
    }

    return 0;
}