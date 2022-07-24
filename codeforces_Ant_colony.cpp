#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,int>
#define num first
#define qtd second

using namespace std;

pp seg[4*100005];
long long v[100005];

void build(int node, int s, int e){
    if(s==e){
        seg[node]={v[s],1};
        return;
    }
    int m=(s+e)/2;
    
    build(2*node,s,m);
    build(2*node+1,m+1,e);
    
    pp left=seg[2*node];
    pp right=seg[2*node+1];

    if(left.num==right.num){
        seg[node]={left.num,left.qtd+right.qtd};
        return;
    }

    long long gcd=__gcd(left.num,right.num);
    if(gcd==left.num){
        seg[node]=left;
    }else if(gcd==right.num){
        seg[node]=right;
    }else{
        seg[node]={gcd,0};
    }
}

pp query(int node, int s, int e, int qs, int qe){
    
    if(s>qe or e<qs){
        return {0,0};
    }

    if(qs<=s and e<=qe){
        return seg[node];
    }

    int m=(s+e)/2;

    pp left=query(2*node,s,m,qs,qe);
    pp right=query(2*node+1,m+1,e,qs,qe);

    if(left.num==right.num){
        return {left.num,left.qtd+right.qtd};
    }

    long long gcd=__gcd(left.num,right.num);
    if(gcd==left.num){
        return left;
    }else if(gcd==right.num){
        return right;
    }else{
        return {gcd,0};
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    build(1,1,n);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=r-l+1-query(1,1,n,l,r).qtd;
        cout<<ans<<endl;
    }
    return 0;
}