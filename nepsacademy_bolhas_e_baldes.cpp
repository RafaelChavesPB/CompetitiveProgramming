#include <bits/stdc++.h>
using namespace std;

vector<int> bit;

int sum(int k) {
    int s = 0;
    while (k >= 1) {
        s += bit[k];
        k -= k&-k;
    }
    return s;
}


void update(int k, int x, int n) {
    while (k <= n){
        bit[k] += x;
        k += k&-k;
    }
}


int main(){
    int n;
    vector<pair<int,int>> v;
    while(cin>>n, n){
        int ans=0;
        v=vector<pair<int,int>> (n+1);
        bit=vector<int>(n+1,0);
        for(int i=1; i<=n;i++){
            cin>>v[i].first;
            v[i].second=i;
        }
        sort(v.begin(), v.end());
        for(int i=1;i<=n;i++){
            update(v[i].second,1,n);
            ans+=sum(n)-sum(v[i].second);
        }

        if(ans%2){
            cout<<"Marcelo"<<endl;
        }else{
            cout<<"Carlos"<<endl;
        }
    }
    return 0;
}