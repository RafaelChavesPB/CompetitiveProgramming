#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;

struct no{
    pi total,esq,meio,dir;
    no(){
        total=pi(0,0);
        esq=pi(0,0);
        meio=pi(0,0);
        dir=pi(0,0);
    }
    no(int a){
        total=pi(a,1);
        esq=pi(a,1);
        meio=pi(a,1);
        dir=pi(a,1);
    }
};

pi soma(pi a, pi b){
    pi temp;
    temp.first=a.first+b.first;
    temp.second=a.second+b.second;
    return temp;
}

no op(no left, no right){
    no atual;
    if(left.dir.second==0){
        return right;
    }
    if(right.dir.second==0){
        return left;
    }
    auto ee = left.esq, ed = left.dir, em=left.meio, et=left.total;
    auto de = right.esq, dd = right.dir, dm=right.meio, dt=right.total;
    atual.dir=max(soma(dt,ed),max(dd,dt));
    atual.esq=max(soma(et,de),max(ee,et));
    atual.meio=max(soma(de,ed),max(em,dm));
    atual.total=soma(dt,et);

    return atual;
}

pi melhor(no a){
    return max(a.esq,max(a.dir,max(a.meio,a.total)));
}

vector<no> seg;
vector<int> v;
int n;

void build(int node, int s, int e){
    if(s==e){
        seg[node]=no(v[s]);
        return;
    }
    int m=(s+e)/2; 
    build(2*node, s, m);
    build(2*node+1,m+1, e);
    seg[node]=op(seg[2*node],seg[2*node+1]);
}

no query(int node, int s, int e, int qs, int qe){
    if(qe<s or qs>e) 
         return no();
    if(qs<=s and e <=qe) 
        return seg[node]; 
    int m=(s+e)/2;
    return op(query(2*node,s,m,qs,qe),query(2*node+1, m+1, e, qs, qe));
}

int main(){
    int m,t,a,b;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        seg=vector<no>(4*n);
        v=vector<int>(n+1);
        for(int i=1;i<=n;i++){
            scanf("%d",&v[i]);
        }
        build(1,1,n);
        cin>>m;
        while(m--){
            scanf("%d%d",&a,&b);
            auto ans=melhor(query(1,1,n,a,b));
            printf("%d %d\n",ans.first, ans.second);
        }
    }


    return 0;
}