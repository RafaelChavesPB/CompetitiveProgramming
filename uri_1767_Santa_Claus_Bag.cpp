#include <bits/stdc++.h>
#define pi pair<int,int>
#define q first
#define p second

using namespace std;

struct bag{   
    int q_toys;
    int peso_ocup;
    int q_packs;
};

bag max(bag a, bag b){
    if(a.q_toys>=b.q_toys){
        return a;
    }
    return b;
}
vector<pi> packs;

bag memory[110][55];

bag calcula(int pos, int peso){
    int valor=0;
    
    if(pos==packs.size()||peso==0){
        memory[pos][peso].q_toys=0;
        memory[pos][peso].peso_ocup=0;
        memory[pos][peso].q_packs=0;
    }
    if(memory[pos][peso].q_toys!=-1){
        return memory[pos][peso];
    }
    if(peso>=packs[pos].p){ 
        bag temp=calcula(pos+1,peso-packs[pos].p);
        bag temp2=calcula(pos+1,peso);
        temp.q_toys+=packs[pos].q;
        temp.peso_ocup+=packs[pos].p;

        if(temp.q_toys>temp2.q_toys){
            temp.q_packs++;
            memory[pos][peso]=temp;
        }else{
            memory[pos][peso]=temp2;
        }
        return memory[pos][peso];
    }

    return memory[pos][peso]=calcula(pos+1,peso);
}

int main(){


    int cases;
    int n_packs;
    pi temp;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n_packs);
        for(int i=0;i<n_packs;i++){
            scanf("%d %d",&temp.q,&temp.p);
            packs.push_back(temp);
        }
        for(int i=0;i<=packs.size()+2;i++){
            for(int j=0;j<=50;j++){
                memory[i][j]={-1,-1,-1};
            }
        }
        bag ans=calcula(0,50);
        printf("%d brinquedos\nPeso: %d kg\nsobra(m) %d pacote(s)\n\n",ans.q_toys,ans.peso_ocup,n_packs-ans.q_packs);
        packs.clear();
    }

}