#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,int>
#define f first
#define se second
using namespace std;


int seg[5000010];
vector<pp> num;
bool compare(pp a,pp b){
    return a.f>b.f;
}

void update(ll node, ll pos, ll s, ll e){
    ll mid =(e+s)/2;
    if(s==e){
        seg[node]++;
        return;
    }

    if(pos<=mid){
        update(2*node, pos, s, mid);
    }else{
        update(2*node+1,pos, mid+1, e);
    }

    seg[node]=seg[2*node]+seg[2*node+1];
}

long long query(ll node, ll qs,ll qe, ll s, ll e){
    if(qs>e or qe<s or qs>qe or e<s){
        return 0;
    }
    if(qs<=s and e<=qe){
        return seg[node];
    }
    ll mid=(s+e)/2;
    return query(2*node, qs, qe, s, mid)+query(2*node+1,qs,qe,mid+1,e);
}

int main(){
    int n;
    ll ans=0;
    ll temp;
    cin>>n;
    for(int i=1; i<=n;i++){
        cin>>temp;
        num.push_back(pp(temp,i));
    }
    sort(num.begin(), num.end(), compare);

    for(int i=0;i<n;i++){
        update(1,num[i].se,1,n);
        long long maior_antes=query(1,1,num[i].se-1,1,n);
        long long menor_depois=n-num[i].se-query(1,num[i].se+1,n,1,n);
        // cout<<maior_antes<<" "<<menor_depois<<"\nNumero:"<<num[i].f<<endl;
        ans+=maior_antes*menor_depois;
    }
    
    cout<<ans<<endl;


    return 0;
}