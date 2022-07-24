#include <bits/stdc++.h>
#define int long long

using namespace std;

int memory[1024];
vector<int> furos;

int patches(int remendo1, int remendo2, int n, int pos, int final){
        
    if(memory[pos]!=-1){
        return memory[pos];
    }
    if(pos>=n){
        return 0;
    }

    int qtd=1;
    int qtd2=1;     
    int inicio=furos[pos];


    while(remendo2>=furos[pos+qtd2]-inicio and pos+qtd<n){
        qtd2++;
    }

    while(remendo1>=furos[pos+qtd]-inicio and pos+qtd<n){
        qtd++;
    }


    /*SOL1*/ memory[pos]=min(patches(remendo1,remendo2,n,pos+qtd,final)+remendo1,patches(remendo1,remendo2,n,pos+qtd2,final)+remendo2);
    return memory[pos];
    

    
} 
 main(){
    int n, perimetro, remendo1, remendo2,temp;

    while(cin>>n>>perimetro>>remendo1>>remendo2){
        for(int i=0;i<n;i++){
            cin>>temp;
            furos.push_back(temp);
        }
        furos.push_back(INT_MAX);
        memset(memory,-1,sizeof(memory));
        cout<<patches(min(remendo1,remendo2),max(remendo1,remendo2),n,0,perimetro)<<"\n";
        furos.clear();
    }


    return 0;
} 