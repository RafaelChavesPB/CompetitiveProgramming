#include <bits/stdc++.h>

using namespace std;


string seq;

struct aux{
    int ans;
    int t1;
    int t2;
    aux(){
        t1=0;
        t2=0;
        ans=0;
    };
    aux(int ans_,int t1_,int t2_){
        ans=ans_;
        t1=t1_;
        t2=t2_;
    };
};

aux sg[3000010];

void build(int node, int s, int e){
    if(s==e){
        aux temp;
        temp.ans=0;
        if(seq[s-1]=='('){
            temp.t1=1;
            temp.t2=0;
        }else{
            temp.t1=0;
            temp.t2=1;
        }
        sg[node]=temp;
        return;
    }

    int m=(s+e)/2;

    build(2*node, s, m);
    build(2*node+1,m+1,e);
    
    aux temp;
    aux left=sg[2*node];
    aux right=sg[2*node+1];
    
    int valor=min(left.t1,right.t2);
    temp.ans=valor+left.ans+right.ans;
    temp.t1=right.t1+left.t1-valor;
    temp.t2=right.t2+left.t2-valor;

    sg[node]=temp;
}

aux query(int node, int s, int e, int qs, int qe){
    if(s>qe or e<qs){
        aux temp;
        return temp;
    }
    if(qs<=s and e<=qe){
        return sg[node];
    }
    int m=(s+e)/2;

    aux left=query(2*node,s,m,qs,qe);
    aux right=query(2*node+1,m+1,e,qs,qe);
    int valor=min(left.t1,right.t2);
    return aux(valor+left.ans+right.ans,right.t1+left.t1-valor,right.t2+left.t2-valor);
    
}
int main(){
    
    int ans=0;
    int n;
    int l,r;
    cin>>seq;
    build(1,1,seq.size());
    cin>>n;
    while(n--){
        cin>>l>>r;
        cout<<query(1,1,seq.size(),l,r).ans*2<<endl;
    }
}