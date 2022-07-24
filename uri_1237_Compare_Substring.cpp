#include <bits/stdc++.h>

using namespace std;

int m[100][100];
char b[100][100]; 
char A[100],B[100];

int lcs(int Bsize, int Asize){
    int maior=0;
    for(int i=0;i<=Bsize;i++)
        m[i][0]=0;
    for(int j=1;j<=Asize;j++)
        m[0][j]=0;

    for(int i=1;i<=Bsize;i++){
        for(int j=1;j<=Asize;j++){
            if(A[j-1]==B[i-1]){
                m[i][j]=m[i-1][j-1]+1;
                maior=max(maior,m[i][j]);
            }else
            {
                m[i][j]=0;
            }
        }
    }

    return maior;
}

int main(){

    while(scanf("%[^\n]%*c",A)!=EOF){
        scanf("%[^\n]%*c",B);
        cout<<lcs(strlen(B),strlen(A))<<"\n";
    }
    return 0;
}