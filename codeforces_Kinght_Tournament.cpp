#include <bits/stdc++.h>

using namespace std;

int arr[5*100000];
bool tree[5*1000000];

void build(int node, int s, int e){
    if(s==e){
        tree[node]=1;
        return;
    }
    int  mid=(s+e)/2;
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);
    tree[node]=tree[2*node] or tree[2*node+1];
    return;
}

void update(int node, int s, int e, int us, int ue, int winner){
      
    if(s>ue or e<us or tree[node]==0){
        return; 
    }

    if(s==e){
        if(s!=winner){
            arr[s]=winner;
            tree[node]=0;
        }
        return;
    }
    
    int mid=(s+e)/2;

    update(2*node,s, mid,us,ue, winner);
    update(2*node+1,mid+1,e,us,ue,winner);

    tree[node]=tree[2*node] or tree[2*node+1];
}

int main(){
    int s,e,winner, n, m;
    cin>>n>>m;
    build(1,1,n);
    while(m--){
        cin>>s>>e>>winner;
        update(1,1,n,s,e,winner);
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return 0;
}