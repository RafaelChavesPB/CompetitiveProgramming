#include <bits/stdc++.h>

using namespace std;

vector<int> seg,v; 

void update(int node, int pos, int valor, int s, int e){
    if(s==e){
        seg[node]=valor;
        return;
    }
    int m=(s+e)/2;
    if(pos<=m)
        update(2*node,pos,valor,s,m);
    else 
        update(2*node+1,pos,valor,m+1,e);

    seg[node]=seg[2*node]*seg[2*node+1];
}

void build(int node, int s, int e){
    if(s==e){
        seg[node]=v[s];
        return;
    }
    int m=(s+e)/2; 
    build(2*node, s, m);
    build(2*node+1,m+1, e);
    seg[node]=seg[2*node]*seg[2*node+1];
}

int query(int node, int s, int e, int qs, int qe){
    if(qe<s or qs>e) 
         return 1;
    if(qs<=s and e <=qe) 
        return seg[node]; 
    int m=(s+e)/2;
    return query(2*node,s,m,qs,qe)*query(2*node+1, m+1, e, qs, qe);
}

int main(){

    int n,k,a,b;
    string op;

    while(cin>>n>>k){
        seg=vector<int>(4*n);
        v=vector<int>(n+1); 
        for(int i=1;i<=n;i++){
            cin>>a;
            if(a<0)
                v[i]=-1;
            else if(a>0)
                v[i]=1;
            else
                v[i]=0;
            
        }
        build(1,1,n);
        while(k--){
            cin>>op>>a>>b;
            if(op=="C"){
                if(b<0)
                    b=-1;
                else if(b>0)
                    b=1;
                else
                    b=0;
                update(1,a,b,1,n);
            }
            else{
                auto ans = query(1,1,n,a,b);
                if(ans<0)
                    cout<<'-';
                else if(ans>0)
                    cout<<'+';
                else
                    cout<<'0';
            } 
        }
        cout<<endl;
    }
    return 0;
}