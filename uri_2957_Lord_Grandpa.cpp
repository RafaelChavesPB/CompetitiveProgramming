#include <bits/stdc++.h>
#define TAM 31
using namespace std;

int pegaPos(char letra){
    if(isupper(letra)){
        return letra-'A';
    }else{
        return letra-'a';
    }
}
int main(){

    ios::sync_with_stdio(false);
    int vetor[TAM]={0};
    int n, qtd, pos, ans=0;
    string temp,linha;
    
    cin>>n>>qtd;
    cin.ignore();
    for(int i=0;i<n;i++){
        int cont=0;
        getline(cin,linha);
        istringstream ss(linha);

        pos=pegaPos(linha[0]);
        while(ss>>temp){
            cont+=temp.size();
        }

        vetor[pos]=max(cont,vetor[pos]);
    }

    std::sort(vetor, vetor+TAM);
    
    for(int i=1;i<=qtd;i++){
        ans+=vetor[TAM-i];
    }
    cout<<ans<<"\n";

    return 0;
}