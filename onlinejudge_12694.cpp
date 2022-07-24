#include <bits/stdc++.h>
#define pi pair<int,int>
#define vpi vector<pi>
#define s second
#define f first

using namespace std;

vpi lista;

bool compare(pi a, pi b){
    return a.s<b.s;
}

int guloso(void){
    int qtd=0;
    int final_ant=0;
    for(int i=0;i<lista.size();i++){
        if(lista[i].f>=final_ant){
            qtd++;
            final_ant=lista[i].s;
        }
    }
    return qtd;
}

int main(){

    int n, inicio, final;

    cin>>n;

    while(n--){
        while(cin>>inicio>>final&&(inicio||final)){
            lista.push_back(pi(inicio,final));
        }
        sort(lista.begin(),lista.end(),compare);

        // for(auto x: lista){
        //     cout<<x.f<<" "<<x.s<<endl;
        // }
        // cout<<endl;

        cout<<guloso()<<endl;

        lista.clear();

    }
    return 0;
}