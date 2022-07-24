#include <bits/stdc++.h>
using namespace std;

vector<int> seg[4*(int)10e+5+1]; 
int vetor[(int)10e+5];

void update(int node, int pos, int cor, int s, int e){
    if(s==e){
        seg[node]=vector<int>(51,0);
        seg[node][cor]=1;
        return;
    }
    int m=(s+e)/2;
    if(pos<=m)
        update(2*node,pos,cor,s,m);
    else 
        update(2*node,pos,cor,m+1,e);

    seg[node]=vector<int>(51);
    for(int i=1; i<51; i++){
        seg[node][i]=seg[2*node][i] or seg[2*node+1][i];
    }
    
}

void build(int node, int s, int e){
    if(s==e){
        seg[node]=vector<int>(51);
        seg[node][vetor[s]]=1;
        return;
    }
    int m=(s+e)/2; 
    build(2*node, s, m);
    build(2*node+1,m+1, e);
    
    seg[node]=vector<int>(51);
    for(int i=1; i<51; i++){
        seg[node][i]=seg[2*node][i] or seg[2*node+1][i];
    }
}

vector<int> query(int node, int s, int e, int qs, int qe){
    if(qe<s or qs>e) 
         return vector<int>(51,0);
    if(qs<=s and e <=qe) 
        return seg[node]; 
    int m=(s+e)/2;

    auto v=vector<int>(51);
    auto left=query(2*node,s,m,qs,qe);
    auto right=query(2*node+1, m+1, e, qs, qe);

    for(int i=1; i<51; i++){
        v[i]= left[i] or right[i];
    }
    return v;
}


int main(){
    int u,x,v,op,n,q;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>vetor[i];
    }
    build(1,1,n);
    cin>>q;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>u>>x;
            update(1,u,x,1,n);
        }else{
            cin>>u>>v;
            auto ans=0;
            auto b=query(1,1,n,min(u,v),max(u,v));
            for(auto i:b){
                ans+=i;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}