#include <bits/stdc++.h>

using namespace std;

vector<string> matriz;
char A[30];
char B[30];
int m[100][100];

int lcs(int tamB, int tamA){
    memset(m,0,sizeof(m));
    for(int i=1;i<=tamB;i++){
        for(int j=1;j<=tamA;j++){
            if(A[j-1]==B[i-1]){
                m[i][j]=m[i-1][j-1]+1;
            } else if(m[i-1][j]>=m[i][j-1]){
                m[i][j]=m[i-1][j];
            } else {
                m[i][j]=m[i][j-1];
            }
        }
    }
    return m[tamB][tamA];
}


void movimentar(char c, int *x, int *y){
    switch(c){
        case 'N':
            *x-=1;
            break;
        case 'S':
            *x+=1;
            break;
        case 'E':
            *y+=1;
            break;
        case 'W':
            *y-=1;
    }
}
int main(){
    int h,w,t,tamA,tamB,x,y,LCS,caso=0;
    string temp;
    string caminho;
    cin>>t;
    while(t--){
        cin>>h>>w;
        while(h--){
            cin>>temp;
            matriz.push_back(temp);
        }
        cin>>tamA>>x>>y;
        cin.ignore();
        getline(cin,caminho);
        x--;y--;
        A[0]=matriz[x][y];
        A[tamA+1]='\0';
        for(int i=0;i<tamA;i++){
            movimentar(caminho[i],&x,&y);
            A[i+1]=matriz[x][y];
        }
        cin>>tamB>>x>>y;
        cin.ignore();
        getline(cin,caminho);
        x--;y--;
        B[0]=matriz[x][y];
        B[tamB+1]='\0';
        for(int i=0;i<tamB;i++){
            movimentar(caminho[i],&x,&y);
            B[i+1]=matriz[x][y];
        }

        LCS=lcs(tamB+1,tamA+1);
        cout<<"Case "<<++caso<<": "<<tamA+1-LCS<<" "<<tamB+1-LCS<<endl;
        matriz.clear();
        memset(A,'h',sizeof(A));
        memset(B,'h',sizeof(B));
    }

    return 0;
}