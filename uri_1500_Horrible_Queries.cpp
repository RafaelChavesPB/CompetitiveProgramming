#include <bits/stdc++.h>

using namespace std;

long long segtree[5000100];
long long lazy[5000100];
long long vetor[1000010];


void build(int node, int start, int end){
    int right=2*node+1;
    int left=2*node;
    int mid=(start+end)/2;
    if(start==end){
        segtree[node]=vetor[start];
        return;
    }
    build(left,start, mid);
    build(right,mid+1, end);

    segtree[node]=segtree[left]+segtree[right];
}

void update(int node, int start, int end, int up_start, int up_end, int value){
    int right=2*node+1;
    int left=2*node;
    int mid=(start+end)/2;
    
    if(lazy[node]!=0){
        segtree[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[left]+=lazy[node];
            lazy[right]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(start>end or up_start>end or up_end<start){
        return;
    }

    if(up_start<=start and end<=up_end){
        segtree[node]+=(end-start+1)*value;
        if(start!=end){
            lazy[left]+=value;
            lazy[right]+=value;
        }
        return;
    }

    update(left,start,mid,up_start,up_end,value);
    update(right,mid+1,end,up_start,up_end,value);

    segtree[node]=segtree[left]+segtree[right];
}

long long query(int node, int start, int end, int q_start, int q_end){
    int right = 2*node+1;
    int left =2*node;
    int mid=(start+end)/2;

    if(lazy[node]!=0){
        segtree[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[left]+=lazy[node];
            lazy[right]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(start>q_end or end<q_start or start>end){
        return 0;
    }

    if(q_start<=start and end<=q_end){
        return segtree[node];
    }

    return query(left,start,mid, q_start, q_end)+query(right,mid+1,end, q_start, q_end);
}


int main(){
    int cases,n, c, mode, p, q, value;
    scanf("%d",&cases);
    while(cases--){
        memset(segtree,0,sizeof(segtree));
        memset(vetor,0,sizeof(vetor));
        memset(lazy,0,sizeof(lazy));
        scanf("%d %d",&n,&c);
        while(c--){
            scanf("%d",&mode);
            if(mode){
                scanf("%d %d",&p,&q);
                printf("%lld\n",query(1,1,n,min(p,q),max(q,p)));
            }else{
                scanf("%d %d %d",&p,&q,&value);
                update(1,1,n,min(p,q),max(q,p),value);
            }
        }
    }

}