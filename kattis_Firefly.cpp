#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,h,temp;
    cin>>n>>h;
    int gmite[500005]={0},ctite[500005]={0};
    
    for(int i=0;i<n;i++){
        cin>>temp;
        if(!(i%2)){
            gmite[temp]++;
        }else{
            ctite[h-temp+1]++;
        }
    }

    for(int i=h-1;i>0;i--){
        gmite[i]+=gmite[i+1];
    }
    
    for(int i=2;i<=h;i++){
        ctite[i]+=ctite[i-1];
    }

    int min=INT_MAX;
    int qtd_min;
    int soma;

    for(int i=1;i<=h;i++){
        soma=gmite[i]+ctite[i];   
        // cout<< gmite[i]<< " | " <<ctite[i]<<endl; 
        if(soma<min){
            qtd_min=1;
            min=soma;
        }else if(soma==min){
            qtd_min++;
        }
    }

    cout<<min<<" "<<qtd_min<<endl;

    return 0;
}