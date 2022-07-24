#include <bits/stdc++.h>
using namespace std;


int acc(int n, vector<int> &v){
    int soma=0;
    for(auto i:v){
        soma+=abs(i-n);
    }
    return soma;
}

int busca_binaria( int baixo, int cima, vector<int> &v){
    while(baixo+1<cima){
        int meio=(baixo+cima)/2;
        int rc=acc(cima,v);    
        int rb=acc(baixo,v);
        if(rc<rb){
            baixo=meio;
        }else{
            cima=meio;
        }
    }  

    if(baixo!=cima){
        if(acc(cima,v)<acc(baixo,v)){
            return cima;
        }else{
            return baixo;
        }
    }else{
        return cima;
    }
}

int main(){

    int n,ans_x, ans_y ,a ,b, cont=1;
    vector<int> x,y;
    while(cin>>n, n){
        x.clear();
        y.clear();
        while(n--){
            cin>>a>>b;
            x.push_back(a);
            y.push_back(b);
        }
        cout<<"Teste "<<cont++<<endl;
        cout<<busca_binaria(*min_element(x.begin(),x.end()),*max_element(x.begin(),x.end()),x)<<" ";
        cout<<busca_binaria(*min_element(y.begin(),y.end()),*max_element(y.begin(),y.end()),y)<<endl<<endl;
    }

    return 0;
}