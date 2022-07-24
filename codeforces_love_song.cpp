#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    string s;
    cin>>n>>m;
    cin>>s;
    vector<int> acc(n+1);
    for(int i=1;i<=n;i++){
        acc[i] = acc[i-1] + (s[i-1] - 'a'+1);
    }
    cout<<endl;
    while(m--){
        int a,b;
        cin>>a>>b;
        cout<<acc[b]-acc[a-1]<<endl;
    }
    return 0;
}