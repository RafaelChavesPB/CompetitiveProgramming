#include <bits/stdc++.h>

using namespace std;

long long tree[5*1000000];
long long arr[1000005];
bool build(int node, int s, int e){
    if(s==e){
        tree[node]=arr[s];
        return false;
    }
    int mid=(s+e)/2;
    
    bool flag=build(2*node+1,mid+1,e);
    build(2*node,s,mid);
    if(flag){
        tree[node]=tree[2*node]^tree[2*node+1];    
        return false;
    }else{
        tree[node]=tree[2*node]|tree[2*node+1];
        return true;
    }
}

// long long query(int node, int s, int e, int qs, int qe){
//     if(e<qs or qe<s){
//         return 0;
//     }
//     if(s==qs and qe==e){
//         return tree[node];
//     }
//     int mid=(s+e)/2;
//     return query(2*node,s,mid,qs,qe)+query(2*node+1,mid+1,e,qs,qe);
// }

int update(int node, int s, int e, int pos,long long value){
    if(e<pos or pos<s){
        return false;
    }
    if(s==pos and pos==e){
        arr[pos]=value;
        tree[node]=value;
        return false;
    }
 
    int mid=(s+e)/2;   
    bool flag=update(2*node+1,mid+1,e,pos,value);
    bool flag2=update(2*node,s,mid,pos,value);
    if(flag or flag2){
        tree[node]=tree[2*node]^tree[2*node+1];    
        return false;
    }else{
        tree[node]=tree[2*node]|tree[2*node+1];
        return true;
    }
}


int main(){
    long long n,m,tam;
    cin>>n>>m;
    tam=pow(2,n);
    for(int i=1;i<=tam;i++)
        cin>>arr[i];
    build(1,1,tam);
    while(m--){
        int s, e;
        cin>>s>>e;
        update(1,1,tam,s,e);
        cout<<tree[1]<<endl;
    }
    return 0;
}