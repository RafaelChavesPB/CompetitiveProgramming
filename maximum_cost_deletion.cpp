//Problema disponivel em:https://codeforces.com/problemset/problem/1550/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;

        if(b>=0){
            cout<<n*a+n*b<<endl;
        }else{
            int size = unique(s.begin(),s.end()) - s.begin();
            cout<<n*a+(size/2+1)*b<<endl;
        }
    }
    return 0;
}