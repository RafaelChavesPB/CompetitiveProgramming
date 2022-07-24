#include <bits/stdc++.h>
using namespace std;
vector<int> lista, ult, ans;
void dfs(int p,int dia, int faltam){
    if(!faltam){
        return;
    }
    if(ult[p]!=-1){
        ult[p] = dia-ult[p];
        faltam-=1;
    }
    ult[p]=dia;
    dfs(lista[p],dia+1,faltam);
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        lista.resize(n+1);
        ult.assign(n+1,-1);
        ans.assign(n+1,-1);
        for(int i=1;i<=n;i++){
            cin>>lista[i];
        }
        for(int i =1;i<=n;i++){
            if(ans[i]==-1)
                dfs(lista[i],1)
        }
        cout<<<<endl;
    }
    return 0;
}