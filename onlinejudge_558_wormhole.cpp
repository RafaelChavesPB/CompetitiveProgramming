#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int,int>,int>> arestas;
vector<int> dist;
int n;

bool bf(int r, int e){
    dist=vector<int>(n,INT_MAX);
    dist[r]=0;
    for(int i=0;i<n-1;i++){
        for(auto x: arestas){
            int a,b,w;
            a=x.first.first;
            b=x.first.second;
            w=x.second;
            dist[b]=min(dist[b],dist[a]+w);
        }
    }
    for(auto x: arestas){
        int a,b,w;
        a=x.first.first;
        b=x.first.second;
        w=x.second;
        if(dist[b]>dist[a]+w)
            return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,a,b,w;
        arestas.clear();
        dist.clear();
        cin>>n>>m;
        while(m--){
            cin>>a>>b>>w;
            arestas.push_back(pair<pair<int,int>,int>(pair<int,int>(a,b),w));
        }
        if(n-1 and bf(0,1)){
            cout<<"possible"<<endl;
        }else{
            cout<<"not possible"<<endl;
        }
    }

    return 0;
}