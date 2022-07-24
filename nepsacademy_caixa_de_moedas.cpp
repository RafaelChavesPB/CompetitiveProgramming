#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<ll> seg,lazy,v;

void build(int node, int s, int e){
    if(s==e){
        seg[node]=v[s];
        return;
    }
    int m=(s+e)/2; 
    build(2*node, s, m);
    build(2*node+1,m+1, e);
    seg[node]=seg[2*node]+seg[2*node+1];
}

void update(int node, int s, int e, int us, int ue, ll value){
    if(lazy[node]!=0){
        seg[node]=((e-s+1)*lazy[node]);
        if(s!=e){
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }

    if(ue<s or e<us){
        return;
    }

    if(us<=s and e<=ue){
        seg[node]=((e-s+1)*value);
        if(s!=e){
            lazy[2*node]=value;
            lazy[2*node+1]=value;
        }
        return;
    }   

    int m=(s+e)/2;

    update(2*node,s,m,us,ue,value);
    update(2*node+1,m+1,e,us,ue,value);

    seg[node]=seg[2*node]+seg[2*node+1];
}

int query(int node, int s, int e, int qs, int qe){

    if(lazy[node]!=0){
        seg[node]=(e-s+1)*lazy[node];
        if(s!=e){
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        } 
        lazy[node]=0;       
    }

    if(qe<s or e<qs){
        return 0;
    }

    if(qs<=s and e<=qe){
        return seg[node];
    }

    int m=(s+e)/2;

    return query(2*node+1,m+1,e,qs,qe) + query(2*node, s, m, qs, qe);
}

int main(){
    ll m,op,a,b,c;
    cin>>n>>m;

    seg=lazy=vector<ll>(4*n);
    v=vector<ll>(n+1);

    for(int i=1;i<=n;i++)
        cin>>v[i];
    
    build(1,1,n);

    while(m--){
        cin>>op;
        if(op==1){
            cin>>a>>b>>c;
            update(1,1,n,a,b,c);
        }else{
            cin>>a>>b;
            cout<<query(1,1,n,a,b)<<endl;
        }
    }


    return 0;
}