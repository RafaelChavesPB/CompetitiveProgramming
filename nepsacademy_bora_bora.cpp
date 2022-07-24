#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;

int main(){
    int it,descartou,p,m,n,rank,naipe,sentido,penalidade;
    string c;
    while(cin>>p>>m>>n, p and m and n){
        vector<multiset<pi,greater<pi>>> mao(p);
        queue<pi> saque;
        pi topo;
        for(int i=0; i<n;i++){
            cin>>rank>>c;
            if(c=="C")
                naipe=0;
            else if(c=="D")
                naipe=1;
            else if(c=="H")
                naipe=2;
            else 
                naipe=3;

            if(i<p*m){
                mao[i/m].insert(pi(rank,naipe));
            }else if(i==p*m){
                topo=pi(rank,naipe);
            }else{
                saque.push(pi(rank,naipe));
            }
        }
        sentido=1,it=0; 
        penalidade=topo.first;
        if(penalidade==12){
            sentido*=-1;
            penalidade=0;
        }

        while(true){
    
            if(penalidade==7 or penalidade==11 or penalidade==1)
            {
                if(penalidade==7){
                    mao[it].insert(saque.front());
                    saque.pop();    
                    mao[it].insert(saque.front());
                    saque.pop();  
                }else if(penalidade==1){
                    mao[it].insert(saque.front());
                    saque.pop();
                }
                it=(it+sentido+2*p)%p;
            }    
            penalidade=0;
            descartou=0;
            
            for(auto carta:mao[it]){
                if(carta.first==topo.first or carta.second==topo.second){
                    topo=carta;
                    descartou=1;
                    break;
                }
            }

            if(descartou){
                mao[it].erase(topo);
                if(!mao[it].size()){
                    cout<<it+1<<endl;
                    break;
                }
                penalidade=topo.first;
            }else{
                if(saque.front().first==topo.first or saque.front().second==topo.second){
                    topo=saque.front();
                    penalidade=topo.first;
                }else{
                    mao[it].insert(saque.front());
                }
                saque.pop();
            }
            if(penalidade==12)
                sentido*=-1;

            it=(it+sentido+2*p)%p;
        }
    }
}