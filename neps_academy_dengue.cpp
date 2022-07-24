#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

vector<set<int>> adj;
// priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fp;
queue<int> fila;

int main(){
    int n,a,b,cont=1, ultimo;
    while(cin>>n,n){
        adj=vector<set<int>> (n+1);
        for(int i=1;i<n;i++){
            cin>>a>>b;
            adj[a].insert(b);
            adj[b].insert(a);
        }

        if(n==1){
            ultimo=1;
        }

        for(int i=1;i<=n;i++){
            if(adj[i].size()==1){
                fila.push(i);
                ultimo=i;
            }
        }
        while(!fila.empty()){
            auto ind=fila.front();
            fila.pop();
            for(auto x:adj[ind]){
                adj[x].erase(ind);
                if(adj[x].size()==1){
                    fila.push(x);
                    ultimo=x;
                }
            }
        }
        cout<<"Teste "<<cont++<<endl;
        cout<<ultimo<<endl<<endl;
    }

    return 0;
}