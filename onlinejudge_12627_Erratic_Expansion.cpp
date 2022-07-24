#include <bits/stdc++.h>

using namespace std;

int matrizimpar[1000][1000];
int matrizpar[1000][1000];

int main(){

    int limit;
    int continue_, cont=0, contador=0;
    matrizpar[1][1]=1;
    matrizimpar[1][1]=1;
    while(cin>>continue_&&continue_){
        limit=pow(2,cont);
        if(cont%2){
            for(int i=1;i<=limit;i++){
                for(int j=1;j<=limit;j++){
                    if(matrizpar[i][j]){
                        matrizimpar[i*2-1][j*2-1]=1;
                        matrizimpar[i*2-1][j*2]=1;
                        matrizimpar[i*2][j*2-1]=1;
                        matrizimpar[i*2][i*2]=0;
                    }
                    else{
                        matrizimpar[i*2-1][j*2-1]=0;
                        matrizimpar[i*2-1][j*2]=0;
                        matrizimpar[i*2][j*2-1]=0;
                        matrizimpar[i*2][i*2]=0;
                    }
                }
            }

            for(int i=1;i<=limit;i++){
                for(int j=1;j<=limit;j++){
                    if(matrizpar[i][j])contador++;
                }
                cout<<i<<":"<<contador<<" -> "<<i%4<<" -> "<<i%8<<" -> "<<i%16<<"\n";
                contador=0; 
            }
            cout<<"\n\n";
        }
        else{
            for(int i=1;i<=limit;i++){
                for(int j=1;j<=limit;j++){
                    if(matrizimpar[i][j]){
                        matrizpar[i*2-1][j*2-1]=1;
                        matrizpar[i*2-1][j*2]=1;
                        matrizpar[i*2][j*2-1]=1;
                        matrizpar[i*2][i*2]=0;
                    }
                    else{
                        matrizpar[i*2-1][j*2-1]=0;
                        matrizpar[i*2-1][j*2]=0;
                        matrizpar[i*2][j*2-1]=0;
                        matrizpar[i*2][i*2]=0;
                    }
                }
            }
            
            for(int i=1;i<=limit;i++){
                for(int j=1;j<=limit;j++){
                    if(matrizpar[i][j])contador++;
                }
                cout<<i<<":"<<contador<<" -> "<<i%4<<" -> "<<i%8<<" -> "<<i%16<<"\n";
                contador=0;
            }

        }
        cont++;
        

    }

    return 0;
}