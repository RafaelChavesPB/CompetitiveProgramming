#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,l,a;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fp;
    cin>>n>>l;
    vector<int> ans(n+1,0);
    for(int i=1;i<=n and l; i++, l--){
        cin>>a;
        fp.push(make_pair(a,i));
        ans[i]++;
    }
    for(int i=0; i<l; i++){
        auto atual=fp.top();
        fp.pop();
        cin>>a;
        atual.first+=a;
        ans[atual.second]++;
        fp.push(atual);
    }

    for(int i=1;i<=n;i++){
        cout<<i<<' '<<ans[i]<<endl;
    }





    return 0;
}