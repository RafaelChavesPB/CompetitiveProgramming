#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        stack<int> pilha;
        int ans=0;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='\\'){
                pilha.push(i);
            }else if(s[i]=='/' and pilha.size()){
                ans+=i-pilha.top();
                pilha.pop();
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}