#include <bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>> edges;
vector<int> pai;
vector<int> peso;

int find(int x){
    if(pai[x] == x)
        return x;
    return pai[x] = find(pai[x]);
}
void join(int a,int b){
    a = find(a);
    b= find(b);
    if(peso[a]<peso[b])
        pai[a] = b;
    else if(peso[a] > peso[b])
        pai[b]=a;
    else{
        pai[a] = b;
        peso[b]++;
    }
}
int kruskal(int n){
    pai.assign(n,0);
    peso.assign(n,0);
    int ans = INT_MAX;
    for(int i=0;i<n;i++)
        pai[i]=i;
    sort(edges.begin(),edges.end(),greater<pair<int,pair<int,int>>>());
    for(auto it : edges){
        if(find(it.second.first) != find(it.second.second)){
            join(it.second.first,it.second.second);
            ans=min(it.first,ans);
        }
    }
    return ans;

}
int main(){
    int t,n,m,a,b,c,cont=1;
    cin>>t;
    while (t--){
        cin>>n>>m;
        edges.clear();
        for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            edges.push_back({c,{a,b}});
        }
        cout<<"Case #"<<cont++<<": ";
        cout<<kruskal(n)<<endl;
    }
    
    return 0;
}