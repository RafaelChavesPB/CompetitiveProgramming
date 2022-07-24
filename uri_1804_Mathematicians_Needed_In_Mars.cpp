#include <bits/stdc++.h>

using namespace std;

int seg[500005];
int vetor[100005];
void build( int si, int sf, int pos){
	if(si==sf){
		seg[pos]=vetor[si];
		return;
	}
	int sm=(si+sf)/2; 
	build(si,sm,2*pos);
	build(sm+1,sf,2*pos+1);
	seg[pos]=seg[2*pos]+seg[2*pos+1];
}

void atualizar (int q, int valor, int si, int sf, int pos){
	if(si==sf){
		seg[pos]=valor;
		return;
	}
	int sm=(si+sf)/2;
	if(q<=sm)
		atualizar(q,valor,si,sm,2*pos);
	else 
		atualizar(q,valor,sm+1,sf,2*pos+1);

	seg[pos]=seg[2*pos]+seg[2*pos+1];
}


int busca(int qi, int qf, int si, int sf, int pos){
	if(qf<si or qi>sf) 
		return 0;
	if(qi<=si and qf >=sf) 
		return seg[pos]; 
	int sm=(si+sf)/2;
		return busca(qi,qf,si,sm,2*pos) +busca(qi,qf,sm+1,sf,2*pos+1);
}

int main(){
    int n, pos;
    char c;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d ",&vetor[i]);
    }
    build(1,n,1);
    while(scanf("%c %d%*c",&c,&pos)!=EOF){
		if(c=='a'){
            atualizar(pos,0,1,n,1);
        }else if(c=='?'){
            printf("%d\n",busca(1,pos-1,1,n,1));
        }
    }
    
}