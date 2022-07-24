#include <bits/stdc++.h>
#define f first
#define s second
#define pi pair<int,int>

using namespace std;


char m[25][25]; //Matriz preenchida com os numeros do jogo
int visitado[25][25];
int desc[25][25]; //Matriz com a pontuação descr 
int dx[]={0,1,0,-1}; //{N,L,S,O}
int dy[]={-1,0,1,0}; //{N,L,S,O}
int dd[]={1,2,4,8}; //{N,L,S,O}
int polyominoes[10];
bool inGrid(int y, int x, int tam_y, int tam_x){
    return (x>=0 and x<tam_x) and (y>=0 and y<tam_y);
}

bool verify(int q_lin, int q_col){ //Verifica se há dois numeros iguais muito proximos
    int col_prov, lin_prov;
    char num;

    for(int lin=0;lin<q_lin;lin++){
        for (int col=0; col<q_col;col++){
            num=m[lin][col];
            for(int dir=0; dir<4;dir++){
                for(int i=1;i<=(num-'0');i++){
                    col_prov=col+i*dx[dir];
                    lin_prov=lin+i*dy[dir];
                    if(inGrid(lin_prov,col_prov,q_lin,q_col)){
                        if(m[lin_prov][col_prov]==num){
                            return false; //encontrou um erro
                        }
                    }   
                }
            }
        }
    }
    return true; //não encontrou um erro
}

void DFS(int lin, int col, int valor){
    int dir=3;
    polyominoes[m[lin][col]-'0']++;
    visitado[lin][col]=valor;
    while(desc[lin][col]){
        if(desc[lin][col]-dd[dir]>=0){
            if(!visitado[lin+dy[dir]][col+dx[dir]]){
                DFS(lin+dy[dir],col+dx[dir],valor);
            }
            desc[lin][col]-=dd[dir];
        }
        dir--;
    }
}


bool testa(int q_lin, int q_col){
    bool flag=true;
    int cont=1;
    for(int i=0;i<q_lin;i++){
        for(int j=0; j<q_col; j++){
            if(!visitado[i][j]){
                memset(polyominoes,0,sizeof(polyominoes));
                DFS(i,j,cont++);
                for(int it=0;it<10;it++){
                    if(polyominoes[it]>1){
                        flag=false;
                    }
                }
            }
        }
    }
    return flag;
}


int main(){

    int r,c,n;
    scanf("%d",&n);
    
    while(n--){
        
        memset(visitado,false,sizeof(visitado));
        scanf("%d %d%*c", &r,&c);
        
        for(int i=0;i<r;i++){
            scanf("%[^\n]%*c",&m[i][0]);
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                scanf("%d",&desc[i][j]);
            }
        }
        printf("%s\n",(testa(r,c) and verify(r,c)?"valid":"invalid"));
    }
    return 0;

}