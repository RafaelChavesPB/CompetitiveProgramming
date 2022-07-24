#include <bits/stdc++.h>

using namespace std;

struct teste{
    string a1,a2,a3;
    int t1,t2;
    int origem;
};

bool visitado[20];
bool lista[20][20];
int q_emails[20];
vector<string> saidas;
vector<teste> envios;

void dfs(int no, int n){
    visitado[no]=true;
    for(int i=0;i<n;i++){
        if(lista[no][i]){
            q_emails[no]++;
            if(!visitado[i])
                dfs(i,n);
        }
    }
}

int main(){

    int n, vizinho;
    teste temp;
    string temp_s;

    ios::sync_with_stdio(false);
    while(cin>>n and n){
        for(int i=0;i<n;i++){
            while(cin>>vizinho and vizinho){
                lista[i][vizinho-1]=true;
                // cout<<vizinho<<" ";
            }
            // cout<<0<<"\n";
        }
        while(cin>>temp.origem  and temp.origem){
            temp.origem--;
            cin>>temp.t1>>temp.t2>>temp.a1>>temp.a2>>temp.a3;
            envios.push_back(temp);
            // cout<<temp.origem<<" "<<temp.t1<<" "<<temp.t2<<" "<<temp.a1<<" "<<temp.a2<<" "<<temp.a3<<"\n";
        }

        for(int i=0;i<n;i++){
            cin>>temp_s;
            temp_s+=": ";
            saidas.push_back(temp_s);
            // cout<<temp_s<<"\n";
        }

        
        for(auto x: envios){
            dfs(x.origem, n);
            for(int i=0;i<n;i++){
                if(q_emails[i]<x.t1){
                    saidas[i]+=(x.a1+' ');
                }else if(q_emails[i]<x.t2){
                    saidas[i]+=(x.a2+' ');
                }else{
                    saidas[i]+=(x.a3+' ');
                }
            }
            memset(q_emails,0,sizeof(q_emails));
            memset(visitado, false, sizeof(visitado));
        }
        for(auto x: saidas){
            cout<<x<<'\n';
        }
        
        memset(lista,false,sizeof(lista));
        saidas.clear();
        envios.clear();
    }
}