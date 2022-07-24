#include<bits/stdc++.h>

using namespace std;


struct ponto{
    int x;
    int y;
};

int primeiro_no(vector<ponto> coord, int pos_atual, int meio);
int no_superior(vector<ponto> coord, int pos_ant, int pos_atual, int meio);
int no_inferior(vector<ponto> coord, int pos_ant, int pos_atual, int meio);

bool compare(ponto a,ponto b){
    return a.x < b.x;
}

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

int min(int a, int b){
    if(a<b)
        return a;
    return b;
}

int dist(int a, int b){
    return a-b;
}

int main(){

    int tam, maior,menor, saida;
    struct ponto temp;
    set<int> eixoy;
    vector<ponto> coord;

    while(cin>>tam){   
        maior=-200000;
        menor=200000;
        saida=0;

        for(int i=0;i<tam;i++){
            cin>>temp.x>>temp.y;
            eixoy.insert(temp.y+1);
            coord.push_back(temp);
        }

        sort(coord.begin(),coord.end(),compare);

        for(auto& meio: eixoy)
            saida=max(saida,primeiro_no(coord,0,meio));
        
        cout<<saida<<endl;

        coord.clear();
    }
}

int primeiro_no(vector<ponto> coord, int pos_atual, int meio){
    
    int valor=0;
    if(pos_atual==coord.size()){
        return 0;
    }
    if(dist(coord[pos_atual].y,meio)==1){
        valor=no_inferior(coord,pos_atual,pos_atual+1,meio)+1;
    }
    else if(dist(coord[pos_atual].y,meio)==-1){
        valor=no_superior(coord,pos_atual,pos_atual+1,meio)+1;
    }

    return max(valor,primeiro_no(coord,pos_atual+1,meio));
}

int no_inferior(vector<ponto> coord, int pos_ant, int pos_atual, int meio){

    int valor=0;

    if(pos_atual==coord.size()){
        return 0;
    }

    if(dist(coord[pos_atual].y,meio)==-1&&coord[pos_ant].x!=coord[pos_atual].x){
        valor=no_superior(coord,pos_atual,pos_atual+1,meio)+1;
    }
    
    return max(valor,no_inferior(coord,pos_ant,pos_atual+1,meio));
}

int no_superior(vector<ponto> coord, int pos_ant, int pos_atual, int meio){

    
    int valor=0;

    if(pos_atual==coord.size()){
        return 0;
    }

    if(dist(coord[pos_atual].y,meio)==1&&coord[pos_ant].x!=coord[pos_atual].x){
        valor=no_inferior(coord,pos_atual,pos_atual+1,meio)+1;
    }
    
    return max(valor,no_superior(coord,pos_ant,pos_atual+1,meio));
}
