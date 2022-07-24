#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a;
    cin>>n>>m;
    vector<int> dp(n+1);
    vector<int> lista(n+1);
    set<int> diff;
    for(int i=1;i<=n; i++){
        cin>>lista[i];
    }
    for(int i=n;i>0;i--){
        diff.insert(lista[i]);
        dp[i]=diff.size();
    }
    for(int i=0;i<m; i++){
        cin>>a;
        cout<<dp[a]<<endl;
    }
}