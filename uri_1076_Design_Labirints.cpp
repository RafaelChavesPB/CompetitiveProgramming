#include <bits/stdc++.h>

using namespace std;

vector<int> lista[100];
bool visitado[100];
 
int dfs(int no){
    visitado[no]=true;
    int cont=0;
    for(auto x: lista[no]){
        if(!visitado[x]){
            cont+=dfs(x)+2;
        }
    }
    return cont;

}
int main(){

    int n;
    int a,b;
    int origem, v, ar;

    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d",&origem,&v, &ar);
        for(int i=0;i<ar;i++){
            scanf("%d %d",&a,&b);
            lista[a].push_back(b);
            lista[b].push_back(a);
        }    

        printf("%d\n",dfs(origem));

        for(auto &x: lista)
            x.clear();
        memset(visitado,false,sizeof(visitado));
    }    
    return 0;
}