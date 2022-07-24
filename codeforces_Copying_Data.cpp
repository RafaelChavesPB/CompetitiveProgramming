#include <bits/stdc++.h>

using namespace std;

int seg[4*100000];
int lazy[4*100000];

void update(int node, int s, int e, int us, int ue, int vs){
    int m=(s+e)/2;
    if(lazy[node]){
        seg[node]=lazy[node];
        if(s!=e){
            lazy[2*node]=seg[node];
            lazy[2*node+1]=seg[node]+m-s+1;
        }
        lazy[node]=0;
    }

    if(s>ue or e<us){
        return;
    }

    if(us<=s and e<=ue){
        seg[node]=s-us+vs;
        if(s!=e){
            lazy[2*node]=seg[node];
            lazy[2*node+1]=seg[node]+m-s+1;
        }
        return;
    }

    seg[node]=0;
    update(2*node,s,m,us,ue,vs);
    update(2*node+1,m+1,e,us,ue,vs);
}


int query( int node, int s, int e, int pos){
    int m=(s+e)/2;
    if(lazy[node]){
        seg[node]=lazy[node];
        if(s!=e){
            lazy[2*node]=seg[node];
            lazy[2*node+1]=seg[node]+m-s+1;
        }
        lazy[node]=0;
    }

    if(s==e){
        return seg[node];
    }

    if(pos<=m){
        return query(2*node,s,m,pos);
    }else{
        return query(2*node+1,m+1,e,pos);
    }
}
int main(){
    long a[100005];
    long b[100005];
    int tam, n, ia, ib, comp, tipo,pos;
    scanf("%d %d",&tam,&n);
    for(int i=1;i<=tam;i++){
        scanf("%ld",&a[i]);
    }
    for(int i=1;i<=tam;i++){
        scanf("%ld",&b[i]);
    }

    while(n--){
        scanf("%d",&tipo);
        if(tipo==1){
            scanf("%d %d %d",&ia,&ib,&comp);
            update(1,1,tam,ib,ib+comp-1,ia);
        }else{
            scanf("%d",&pos);
            int pos_a=query(1,1,tam,pos);
            if(pos_a){
                printf("%ld\n",a[pos_a]);
            }else{
                printf("%ld\n",b[pos]);
            }
        }
    }
    return 0;
}