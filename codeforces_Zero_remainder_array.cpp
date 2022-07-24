#include <bits/stdc++.h>

using namespace std;

int main(){
    map<long long,long long> mod;
    long long k,a,n,t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(long long i=0;i<n;i++){
            cin>>a;
            if(a%k!=0){
                mod[k-(a%k)]++;
            }
        }
        auto qtd=0;
        if(mod.empty()){
            cout<<qtd<<endl;
            continue;
        }

        long long maximo;
        stack<long long> apagar;
        while(!mod.empty()){
            maximo=0;
            for(auto &x: mod){
                if(x.second==1){
                    apagar.push(x.first);
                }else{
                    x.second--;
                }
                maximo=max(maximo,x.first);
            }
            while(!apagar.empty()){
                mod.erase(apagar.top());
                apagar.pop();
            }
            qtd++;
        }
        cout<<(qtd-1)*k+maximo+1<<endl;
    }


    return 0;
}